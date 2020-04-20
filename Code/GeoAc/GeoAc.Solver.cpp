#ifndef GEOAC_SOLVER_CPP_
#define GEOAC_SOLVER_CPP_

#include <math.h>
#include <iostream>
#include <omp.h>

#include "GeoAc.Parameters.h"
#include "../Atmo/Atmo_State.h"
#include "../Atmo/G2S_GlobalSpline1D.h"
#include "GeoAc.EquationSets.h"

using namespace std;

int GeoAc_Propagate_RK4(double ** & solution, bool & check, GeoAc_Sources_Struct &sources, SplineStruct &splines){
	int k = 0;                                                      // Integer to track ending index of solution
	int step_limit = GeoAc_ray_limit * int(1.0/(GeoAc_ds_min*10));	// Limiting number of steps, defined by limiting ray length divided by step size (length/step)
	double s = 0, ds = GeoAc_ds_min;                                // Current ray length and (variable) ray length step

	double *temp0 = new double [GeoAc_EqCnt];		double *temp1 = new double [GeoAc_EqCnt];
	double *temp2 = new double [GeoAc_EqCnt];		double *temp3 = new double [GeoAc_EqCnt];
	double *temp4 = new double [GeoAc_EqCnt];

	double *partial1 = new double [GeoAc_EqCnt];	double *partial2 = new double [GeoAc_EqCnt];
	double *partial3 = new double [GeoAc_EqCnt];
 
	check = false;
     	for(k = 0; k < (step_limit - 1); k++){
                //cout << "Printing sources struct. Thread id: " << omp_get_thread_num() << endl;
                //PRINTSTRUCT(sources);
       		for (int i = 0; i < GeoAc_EqCnt; i++){
			temp0[i] = solution[k][i];
		}
		GeoAc_UpdateSources(s, temp0, sources, splines);
       		ds = GeoAc_Set_ds(temp0);
              
       		s += ds;
		for (int i = 0; i < GeoAc_EqCnt; i++){
			temp1[i] = ds*GeoAc_EvalSrcEq(s, temp0, i, sources);
			partial1[i] = solution[k][i] + temp1[i]/2.0;
		}		

       		GeoAc_UpdateSources(s + ds/2, partial1, sources, splines);
		for (int i = 0; i < GeoAc_EqCnt; i++){
			temp2[i] = ds*GeoAc_EvalSrcEq(s + ds/2.0, partial1, i, sources);
			partial2[i] = solution[k][i] + temp2[i]/2.0;

		}

		GeoAc_UpdateSources(s + ds/2, partial2, sources, splines);	
		for (int i = 0; i < GeoAc_EqCnt; i++){
			temp3[i] = ds*GeoAc_EvalSrcEq(s + ds/2.0, partial2, i, sources);
			partial3[i] = solution[k][i] + temp3[i];
		}

		GeoAc_UpdateSources(s + ds, partial3, sources, splines);
		for (int i = 0; i < GeoAc_EqCnt; i++){
			temp4[i] = ds*GeoAc_EvalSrcEq(s+ds, partial3, i, sources);
			solution[k+1][i] = solution[k][i] + temp1[i]/6.0 + temp2[i]/3.0 + temp3[i]/3.0 + temp4[i]/6.0;
/*                        if (isnan(solution[k+1][i]) & !isnan(solution[k][i])){
                            cout << k << ", " << i << ": ";
                            cout << temp1[i] << " " << temp2[i] << " " << temp3[i] << " " << temp4[i] << endl;
                            cout << sources.c_gr_mag << " " << solution[k][i] << " -> " << solution[k+1][i] << endl;
                        }*/
		}

/*                if (k == 8786){
                    for (int i = 0; i < GeoAc_EqCnt; i++){
                        cout << solution[k+1][i] << " ";
                    }
                    cout << endl;
                }*/

                //if (k == 8786){
                    //cout << "Should break here, printing struct" << endl;
                    //PRINTSTRUCT(sources);
                //}

		if(GeoAc_BreakCheck(solution,k+1, sources)){
                        //cout << "Break Check " << k << endl;
			check = true;
			break;
		}
		if(GeoAc_GroundCheck(solution,k+1)){
                        //cout << "Ground Check " << k << endl;
			check = false;
			break;
		}

	}
	
	delete [] temp0;	delete [] temp1;	delete [] temp2;
	delete [] temp3;	delete [] temp4;
	delete [] partial1;	delete [] partial2;	delete [] partial3;
	
	return k+1;
}

int GeoAc_Propagate_RK4_2(double ** & solution, double& r_max, double& travel_time, double& attenuation,
                              double GeoAc_theta, double GeoAc_phi, double freq, bool CalcAmp, GeoAc_Sources_Struct &sources,
                              SplineStruct &splines, ofstream* raypaths, ofstream* caustics){
	int k = 0;                                                      // Integer to track ending index of solution
	int step_limit = GeoAc_ray_limit * int(1.0/(GeoAc_ds_min*10));	// Limiting number of steps, defined by limiting ray length divided by step size (length/step)
	double s = 0, ds = GeoAc_ds_min;                                // Current ray length and (variable) ray length step

	double *temp0 = new double [GeoAc_EqCnt];		double *temp1 = new double [GeoAc_EqCnt];
	double *temp2 = new double [GeoAc_EqCnt];		double *temp3 = new double [GeoAc_EqCnt];
	double *temp4 = new double [GeoAc_EqCnt];

	double *partial1 = new double [GeoAc_EqCnt];	double *partial2 = new double [GeoAc_EqCnt];
	double *partial3 = new double [GeoAc_EqCnt];
 
        // Create a copy of r_max because if Break_Check() is triggered, r_max doesn't change
        double r_max_cpy = max (r_max, solution[0][0] - r_earth);

        // Used to check for a change in sign from the result of GeoAc_Jacobian()
        double D, D_prev;

        // Check which files to write to
        bool WriteRays = raypaths != nullptr;
        bool WriteCaustics = caustics != nullptr;

        // Stores if we are completely done iterating for this ray (ignore other bounces)
	bool check = false;
     	for(k = 0; k < (step_limit - 1); k++){
                //cout << "Printing sources struct. Thread id: " << omp_get_thread_num() << endl;
                //PRINTSTRUCT(sources);
                
                // Calculate the next row of solution from the current row
       		for (int i = 0; i < GeoAc_EqCnt; i++){
			temp0[i] = solution[k][i];
		}
		GeoAc_UpdateSources(s, temp0, sources, splines);
       		ds = GeoAc_Set_ds(temp0);
              
       		s += ds;
		for (int i = 0; i < GeoAc_EqCnt; i++){
			temp1[i] = ds*GeoAc_EvalSrcEq(s, temp0, i, sources);
			partial1[i] = solution[k][i] + temp1[i]/2.0;
		}		

       		GeoAc_UpdateSources(s + ds/2, partial1, sources, splines);
		for (int i = 0; i < GeoAc_EqCnt; i++){
			temp2[i] = ds*GeoAc_EvalSrcEq(s + ds/2.0, partial1, i, sources);
			partial2[i] = solution[k][i] + temp2[i]/2.0;

		}

		GeoAc_UpdateSources(s + ds/2, partial2, sources, splines);	
		for (int i = 0; i < GeoAc_EqCnt; i++){
			temp3[i] = ds*GeoAc_EvalSrcEq(s + ds/2.0, partial2, i, sources);
			partial3[i] = solution[k][i] + temp3[i];
		}

		GeoAc_UpdateSources(s + ds, partial3, sources, splines);
		for (int i = 0; i < GeoAc_EqCnt; i++){
			temp4[i] = ds*GeoAc_EvalSrcEq(s+ds, partial3, i, sources);
			solution[k+1][i] = solution[k][i] + temp1[i]/6.0 + temp2[i]/3.0 + temp3[i]/3.0 + temp4[i]/6.0;
		}

                // If this triggers, we are completely done iterating through this ray    
		if(GeoAc_BreakCheck(solution,k+1, sources)){
                        //cout << "Break Check " << k << endl;
			check = true;
			break;
		}
                // If this triggers, we are done with this bounce,
                // but can still iterate through future bounces in this ray
		if(GeoAc_GroundCheck(solution,k+1)){
                        //cout << "Ground Check " << k << endl;
			check = false;
			break;
		}

                // Add to travel time and attenuation
                GeoAc_TravelTimeSegment(travel_time, solution, k, k+1, splines);
                GeoAc_SB_AttenSegment(attenuation, solution, k, k+1, freq, splines);            

                // Write to those files
                if(WriteRays || WriteCaustics){
                    // If this is the first iteration, set D_prev
                    if(WriteCaustics && k == 0){                    
                        D_prev = GeoAc_Jacobian(solution,1, splines);
                    }
         
                    // Set D         
                    if(WriteCaustics) D = GeoAc_Jacobian(solution,k+1, splines);
                 
                    // Write to raypaths if 25|k+1
                    if(WriteRays && (k+1) % 25 == 0){
                        *raypaths << solution[k+1][0] - r_earth;
                        *raypaths << '\t' << setprecision(8) << solution[k+1][1] * TO_DEG;
                        *raypaths << '\t' << setprecision(8) << solution[k+1][2] * TO_DEG;
                        if(CalcAmp){    *raypaths << '\t' << 20.0*log10(GeoAc_Amplitude(solution,k+1,GeoAc_theta,
                                                                                    GeoAc_phi,sources, splines));}
                        else{           *raypaths << '\t' << 0.0;}
                        *raypaths << '\t' << -attenuation;
                        *raypaths << '\t' << travel_time << '\n';
                    }
                  
                    // Write to caustics if D and D_prev have different signs
                    if(WriteCaustics && D*D_prev < 0.0){
                        *caustics << solution[k+1][0] - r_earth;
                        *caustics << '\t' << setprecision(8) << solution[k+1][1] * TO_DEG;
                        *caustics << '\t' << setprecision(8) << solution[k+1][2] * TO_DEG;
                        *caustics << '\t' << travel_time << '\n';
                    }
                    // Update D_prev
                    if(WriteCaustics) D_prev = D;
                }
 
                // Check if we have a new highest value for r_max
                r_max_cpy = max (r_max_cpy, solution[k+1][0] - r_earth);
        
	}
	
        // Delete local variables
	delete [] temp0;	delete [] temp1;	delete [] temp2;
	delete [] temp3;	delete [] temp4;
	delete [] partial1;	delete [] partial2;	delete [] partial3;

        // Check if we are still iterating through this ray
        if (!check){
            // Update r_max              
            r_max = r_max_cpy;
            // Return the last row of solution that we filled
            return k+1;
        // If we are done with the ray, return null
        } else return -1;
}


#endif /* GEOAC_SOLVER_CPP_ */
