#ifndef GEOAC_SOLVER_CPP_
#define GEOAC_SOLVER_CPP_

#include <math.h>

#include "GeoAc.Parameters.h"
#include "GeoAc.EquationSets.h"

// Edit/Add these includes to access Splines_Struct
#include "../Atmo/Atmo_State.h"
#include "../Atmo/G2S_GlobalSpline1D.h"

using namespace std;

/* Generic version of GeoAc_Propogate_RK4 that doesn't perform any extra
 * calculations. It produces that final row of data and the new initial conditions
 *
 * @return bool check - True if we are done with this ray entirely
 *                    - False if we are just done with this segment
 *
 * @param initial_conds - the initial conditions. new initial conditions
 *                      - are calculated at the end at written to this variable
 * @param final_row - final row of values
 * @param sources, splines - structs containing information about the ray
 */
bool GeoAc_Propagate_RK4(double* &initial_conds, double* &final_row,
                         GeoAc_Sources_Struct &sources, Splines_Struct &splines){
    int k = 0;                                                      // Integer to track ending index of solution
    int step_limit = GeoAc_ray_limit * int(1.0/(GeoAc_ds_min*10));	// Limiting number of steps, defined by limiting ray length divided by step size (length/step)
    double s = 0, ds = GeoAc_ds_min;                                // Current ray length and (variable) ray length step

    double *temp0 = new double [GeoAc_EqCnt];            double *temp1 = new double [GeoAc_EqCnt];
    double *temp2 = new double [GeoAc_EqCnt];            double *temp3 = new double [GeoAc_EqCnt];
    double *temp4 = new double [GeoAc_EqCnt];

    double *partial1 = new double [GeoAc_EqCnt];	double *partial2 = new double [GeoAc_EqCnt];
    double *partial3 = new double [GeoAc_EqCnt];

    // row i-1 and row i
    // row i is read from, row i+1 is written to
    double prev[GeoAc_EqCnt], current[GeoAc_EqCnt];
    for (int i = 0; i < GeoAc_EqCnt; i++) {current[i] = initial_conds[i];}
    // row i+1 is final_row

    bool check = false;
    for(k = 0; k < (step_limit - 1); k++){
        for (int i = 0; i < GeoAc_EqCnt; i++){
            temp0[i] = current[i];
        }
        GeoAc_UpdateSources(s, temp0, sources, splines);
        ds = GeoAc_Set_ds(temp0);

        s += ds;
        for (int i = 0; i < GeoAc_EqCnt; i++){
            temp1[i] = ds*GeoAc_EvalSrcEq(s,temp0,i, sources);
            partial1[i] = current[i] + temp1[i]/2.0;
        }		

        GeoAc_UpdateSources(s + ds/2, partial1, sources, splines);
        for (int i = 0; i < GeoAc_EqCnt; i++){
            temp2[i] = ds*GeoAc_EvalSrcEq(s + ds/2.0, partial1, i, sources);
            partial2[i] = current[i] + temp2[i]/2.0;
        }

        GeoAc_UpdateSources(s + ds/2, partial2, sources, splines);	
        for (int i = 0; i < GeoAc_EqCnt; i++){
            temp3[i] = ds*GeoAc_EvalSrcEq(s + ds/2.0, partial2,i, sources);
            partial3[i] = current[i] + temp3[i];
        }

        GeoAc_UpdateSources(s + ds, partial3, sources, splines);
        for (int i = 0; i < GeoAc_EqCnt; i++){
            temp4[i] = ds*GeoAc_EvalSrcEq(s+ds, partial3, i, sources);
            final_row[i] = current[i] + temp1[i]/6.0 + temp2[i]/3.0 + temp3[i]/3.0 + temp4[i]/6.0;
        }

        if(GeoAc_BreakCheck(&final_row, 0, sources)){
            check = true;
            break;
        }
        if(GeoAc_GroundCheck(&final_row, 0)){
            check = false;
            break;
        }

        // Update our rows
        for (int i = 0; i < GeoAc_EqCnt; i++) {
            prev[i] = current[i];
            current[i] = final_row[i];
        }
    } // End k for loop

    if (!check) {                 
        // Set new initial conditions based on last 3 rows
        double** rows = new double*[3];
        rows[0] = prev;
        rows[1] = current;
        rows[2] = final_row;
        GeoAc_SetReflectionConditions(rows, 2, sources, splines);
        // SetReflectionConditions() will write to rows[0] so we save those
        // values to initial_conds, which is passed by reference
        initial_conds = rows[0];
    }

    delete [] temp0;	delete [] temp1;	delete [] temp2;
    delete [] temp3;	delete [] temp4;
    delete [] partial1;	delete [] partial2;	delete [] partial3;
	
    return check;
}

/* Performs most of our calculations and file I/O
 *
 * @return bool check - True if we are done with this ray entirely
 *                    - False if we are just done with this segment
 *
 * @param initial_conds - the initial conditions. new initial conditions
 *                      - are calculated at the end at written to this variable
 * @param CalcAmp - should amplitude calculation be performed
 * @param bnc_cnt - current bounce number
 * @param freq - frequency
 * @param GeoAc_theta, GeoAc_phi - current angles of propogation
 * @param lat_src, lon_src, z_src - spherical coords of the source location
 * @param sources, splines - structs containing information about the ray
 * @param results, raypaths, caustics - file output streams
 */
bool GeoAc_Propagate_RK4(double* &initial_conds, bool CalcAmp, int bnc_cnt,
                         double freq, double GeoAc_theta, double GeoAc_phi,
                         double lat_src, double lon_src, double z_src,
                         GeoAc_Sources_Struct &sources, Splines_Struct &splines,
                         ofstream &results, ofstream &raypaths, ofstream &caustics){
    int k = 0;                                                      // Integer to track ending index of solution
    int step_limit = GeoAc_ray_limit * int(1.0/(GeoAc_ds_min*10));	// Limiting number of steps, defined by limiting ray length divided by step size (length/step)
    double s = 0, ds = GeoAc_ds_min;                                // Current ray length and (variable) ray length step

    double *temp0 = new double [GeoAc_EqCnt];            double *temp1 = new double [GeoAc_EqCnt];
    double *temp2 = new double [GeoAc_EqCnt];            double *temp3 = new double [GeoAc_EqCnt];
    double *temp4 = new double [GeoAc_EqCnt];

    double *partial1 = new double [GeoAc_EqCnt];	double *partial2 = new double [GeoAc_EqCnt];
    double *partial3 = new double [GeoAc_EqCnt];

    // row i-1, row i, and row i+1
    // row i is read from, row i+1 is written to
    double* prev = new double[GeoAc_EqCnt];
    double* current = new double[GeoAc_EqCnt];
    double* next = new double[GeoAc_EqCnt];
    for (int i = 0; i < GeoAc_EqCnt; i++) {current[i] = initial_conds[i];}

    // Check if we are writing to raypaths or caustics
    bool WriteRays = raypaths.is_open();
    bool WriteCaustics = caustics.is_open();

    // Stored travel time and attenuation
    double travel_time = 0, attenuation = 0;

    // Used to calculate information for output files
    double D, D_prev, r_max = current[0] - r_earth;

    bool check = false;
    for(k = 0; k < (step_limit - 1); k++){
        for (int i = 0; i < GeoAc_EqCnt; i++){
            temp0[i] = current[i];
        }
        GeoAc_UpdateSources(s, temp0, sources, splines);
        ds = GeoAc_Set_ds(temp0);

        s += ds;
        for (int i = 0; i < GeoAc_EqCnt; i++){
            temp1[i] = ds*GeoAc_EvalSrcEq(s,temp0,i, sources);
            partial1[i] = current[i] + temp1[i]/2.0;
        }		

        GeoAc_UpdateSources(s + ds/2, partial1, sources, splines);
        for (int i = 0; i < GeoAc_EqCnt; i++){
            temp2[i] = ds*GeoAc_EvalSrcEq(s + ds/2.0, partial1, i, sources);
            partial2[i] = current[i] + temp2[i]/2.0;
        }

        GeoAc_UpdateSources(s + ds/2, partial2, sources, splines);	
        for (int i = 0; i < GeoAc_EqCnt; i++){
            temp3[i] = ds*GeoAc_EvalSrcEq(s + ds/2.0, partial2,i, sources);
            partial3[i] = current[i] + temp3[i];
        }

        GeoAc_UpdateSources(s + ds, partial3, sources, splines);
        for (int i = 0; i < GeoAc_EqCnt; i++){
            temp4[i] = ds*GeoAc_EvalSrcEq(s+ds, partial3, i, sources);
            next[i] = current[i] + temp1[i]/6.0 + temp2[i]/3.0 + temp3[i]/3.0 + temp4[i]/6.0;
        }

        // Update r_max
        r_max = max(r_max, next[0] - r_earth);

        if(GeoAc_BreakCheck(&next, 0, sources)){
            check = true;
            break;
        }
        if(GeoAc_GroundCheck(&next, 0)){
            check = false;
            break;
        }

        // See GeoAc_TravelTime() and GeoAc_Atten() in GeoAc.EquationSets.Global.cpp
        // Calculate ds = sqrt(dr^2 + r^2 dt^2 + r^2 + cos(t)^2 + dp^2)
        double dr = next[0] - current[0];
        double dt = next[1] - current[1];
        double dp = next[2] - current[2];
        // Calculate (r,t,p) at the midpoint between [n] and [n+1]
        double r = current[0] + dr/2.0;
        double t = current[1] + dt/2.0;
        double p = current[2] + dp/2.0;
        double ds_ = sqrt(pow(dr,2) + pow(r*dt,2) + pow(r*cos(t)*dp,2));
        // Calculate |c_prop|
        double nu[3];
        nu[0] = current[3] + (next[3] - current[3])/2.0;
        nu[1] = current[4] + (next[4] - current[4])/2.0;
        nu[2] = current[5] + (next[5] - current[5])/2.0;
        double nu_mag = sqrt(nu[0]*nu[0] + nu[1]*nu[1] + nu[2]*nu[2]);
        // Fill in c_prop and calculate its magnitude
        double c_prop[3];
        c_prop[0] = c(r,t,p,splines.Temp_Spline) * nu[0]/nu_mag + w(r,t,p);
        c_prop[1] = c(r,t,p,splines.Temp_Spline) * nu[1]/nu_mag + v(r,t,p,splines.Windv_Spline);
        c_prop[2] = c(r,t,p,splines.Temp_Spline) * nu[2]/nu_mag + u(r,t,p,splines.Windu_Spline);
        double c_prop_mag = sqrt(pow(c_prop[0],2) + pow(c_prop[1],2) + pow(c_prop[2],2));
        // Add contribution to the travel time
        travel_time += ds_/c_prop_mag;

        // Calculate ds = sqrt(dr^2 + r^2 dt^2 + r^2 + sin(t)^2 + dp^2)
        ds_ = sqrt(pow(dr,2) + pow(r*dt,2) + pow(r*sin(t)*dp,2));
        // Add contibution to the attenuation
        attenuation += SuthBass_Alpha(r, t, p, freq, splines)*ds_;

        // Write to raypaths and caustics
        if(WriteRays || WriteCaustics){
            if(WriteCaustics && k == 0){
                D_prev = GeoAc_Jacobian(&next, 0, splines);
            }
                    
            // write profiles to data files and vector arrays
            if(WriteCaustics) {D = GeoAc_Jacobian(&next, 0, splines);}
                
            if(WriteRays && (k+1) % 25 == 0){
                raypaths << next[0] - r_earth;
                raypaths << '\t' << next[1] * 180.0/Pi;
                raypaths << '\t' << next[2] * 180.0/Pi;
                if(CalcAmp){    raypaths << '\t' << 20.0*log10(GeoAc_Amplitude(&next,0,GeoAc_theta,GeoAc_phi,sources, splines));}
                else{           raypaths << '\t' << 0.0;}
                raypaths << '\t' << -attenuation;
                raypaths << '\t' << travel_time << '\n';
            }
                
            if(WriteCaustics && D*D_prev < 0.0){
                caustics << next[0] - r_earth;
                caustics << '\t' << next[1] * 180.0/Pi;
                caustics << '\t' << next[2] * 180.0/Pi;
                caustics << '\t' << travel_time << '\n';
            }
            if(WriteCaustics) {D_prev = D;}
         }

         // Update our rows
         for (int i = 0; i < GeoAc_EqCnt; i++) {
             prev[i] = current[i];
             current[i] = next[i];
         }
    } // End k for loop

    if (WriteCaustics) {caustics.close();}

    // Write to results
    if (!check) {
        double GC_Dist1 = pow(sin((next[1] - lat_src*Pi/180.0)/2.0),2);
        double GC_Dist2 = cos(lat_src*Pi/180.0) * cos(next[1]) * pow(sin((next[2] - lon_src*Pi/180.0)/2.0),2);
        
        double inclination = - asin(c(next[0], next[1], next[2], splines.Temp_Spline) / c(r_earth + z_src, lat_src*Pi/180.0, lon_src*Pi/180.0, splines.Temp_Spline) * next[3]) * 180.0 / Pi;
        double back_az = 90.0 - atan2(-next[4], -next[5]) * 180.0 / Pi;
        if(back_az < -180.0) {back_az +=360.0;}
        if(back_az >  180.0) {back_az -=360.0;}
          
        results << GeoAc_theta * 180.0/Pi;
        results << '\t' << 90 - GeoAc_phi * 180.0/Pi;
        results << '\t' << bnc_cnt;
        results << '\t' << next[1] * 180.0/Pi;
        results << '\t' << next[2] * 180.0/Pi;
        results << '\t' << travel_time;
        results << '\t' << 2.0 * r_earth * asin(sqrt(GC_Dist1+GC_Dist2)) / travel_time;
        results << '\t' << r_max;
        results << '\t' << inclination;
        results << '\t' << back_az;
        if(CalcAmp){    results << '\t' << 20.0*log10(GeoAc_Amplitude(&next,0,GeoAc_theta,GeoAc_phi,sources, splines));}
        else{           results << '\t' << 0.0;}
        results << '\t' << -attenuation;
        results << '\n';
        
        // Set new initial conditions based on last 3 rows
        double** rows = new double* [3];
        rows[0] = prev;
        rows[1] = current;
        rows[2] = next;
        GeoAc_SetReflectionConditions(rows, 2, sources, splines);
        // SetReflectionConditions() will write to rows[0] so we save those
        // values to initial_conds, which is passed by reference
        initial_conds = rows[0];
    }

    delete [] temp0;	delete [] temp1;	delete [] temp2;
    delete [] temp3;	delete [] temp4;
    delete [] partial1;	delete [] partial2;	delete [] partial3;
	
    return check;
}

#endif /* GEOAC_SOLVER_CPP_ */
