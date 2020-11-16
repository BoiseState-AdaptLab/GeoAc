#include <omp.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <sstream>
#include <math.h>

#include "GeoAc/GeoAc.Parameters.h"
#include "Atmo/Atmo_State.h"
#include "Atmo/G2S_GlobalSpline1D.h"

#include "GeoAc/GeoAc.EquationSets.h"
#include "GeoAc/GeoAc.Solver.h"
#include "GeoAc/GeoAc.Interface.h"
#include "GeoAc/GeoAc.Eigenray.h"

using namespace std;

void GeoAcGlobal_Usage(){ 
    cout << '\n';
    cout << '\t' << "#############################################" << '\n';
    cout << '\t' << "####             GeoAcGlobal             ####" << '\n';
    cout << '\t' << "####    Three-Dimensional Ray Tracing    ####" << '\n';
    cout << '\t' << "####     Using Spherical Coordinates     ####" << '\n';
    cout << '\t' << "#### Through a Stratified, Moving Medium ####" << '\n';
    cout << '\t' << "#############################################" << '\n' << '\n';
    
    cout << '\n';
    cout << "Usage: GeoAcGlobal [option] profile.met [parameters]" << '\n';
    cout << '\t' << '\t' << "Enter only 1 option." << '\n';
    cout << '\t' << '\t' << "Profile.met is expected to contain columns describing {z[km]  T[K]  u(zonal wind)[m/s]  v(meridional wind)[m/s]  density[g/cm^3]  p[mbar]} " << '\n';
    cout << '\t' << '\t' << '\t' << "Profile format can be modified, see manual document for details." << '\n';
    cout << '\t' << '\t' << "Parameter calls are expected using the format: parameter_name=value." << '\n' << '\n';
    
    cout << "Options and parameters are:" << '\n';
    cout << '\t' << "-prop (generate ray paths for propagations at multiple azimuth and inclination angles)" << '\n';
    cout << '\t' << '\t' << "Parameter"  << '\t' << "Units" << '\t' << '\t' << "Default Value" << '\n';
    cout << '\t' << '\t' << "---------------------------------------------" << '\n';
    cout << '\t' << '\t' << "theta_min"         << '\t' << "degrees"            << '\t' << '\t' << "0.5" << '\n';
    cout << '\t' << '\t' << "theta_max"         << '\t' << "degrees"            << '\t' << '\t' << "45.0" << '\n';
    cout << '\t' << '\t' << "theta_step"        << '\t' << "degrees"            << '\t' << '\t' << "0.5"  << '\n';
    cout << '\t' << '\t' << "phi_min"           << '\t' << '\t' << "degrees"    << '\t' << '\t' << "-90.0" << '\n';
    cout << '\t' << '\t' << "phi_max"           << '\t' << '\t' << "degrees"    << '\t' << '\t' << "-90.0" << '\n';
    cout << '\t' << '\t' << "phi_step"          << '\t' << "degrees"            << '\t' << '\t' << "1.0"  << '\n';
    cout << '\t' << '\t' << "azimuth"           << '\t' << '\t' << "See Manual" << '\t' << "-90.0" << '\n';
    cout << '\t' << '\t' << "bounces"           << '\t' << '\t' << "integer"    << '\t' << '\t' << "2" << '\n';
    cout << '\t' << '\t' << "lat_src"           << '\t' << '\t' << "degrees"    << '\t' << '\t' << "30.0" << '\n';
    cout << '\t' << '\t' << "lon_src"           << '\t' << '\t' << "degrees"    << '\t' << '\t' << "0.0" << '\n';
    cout << '\t' << '\t' << "z_src"             << '\t' << '\t' << "km"         << '\t' << '\t' << "0.0" << '\n';
    cout << '\t' << '\t' << "WriteAtmo"         << '\t' << "True/False"         << '\t' << "False" << '\n';
    cout << '\t' << '\t' << "WriteRays"         << '\t' << "True/False"         << '\t' << "True" << '\n' << '\n';
    
    cout << '\t' << "-interactive (set a fixed source location and select individual ray paths to generate)" << '\n';
    cout << '\t' << '\t' << "Parameter"  << '\t' << "Units" << '\t' << '\t' << "Default Value" << '\n';
    cout << '\t' << '\t' << "---------------------------------------------" << '\n';
    cout << '\t' << '\t' << "lat_src"           << '\t' << '\t' << "degrees"    << '\t' << '\t' << "30.0" << '\n';
    cout << '\t' << '\t' << "lon_src"           << '\t' << '\t' << "degrees"    << '\t' << '\t' << "0.0" << '\n';
    cout << '\t' << '\t' << "z_src"             << '\t' << '\t' << "km"         << '\t' << '\t' << "0.0" << '\n' << '\n';   
    
    cout << '\t' << "-eig_search (Search for all eigenrays connecting a source at (lat_src, lon_src, z_src) to a receiver " << '\n';
    cout << '\t' << '\t' << '\t' << "at (lat_rcvr, lon_rcvr, z_grnd) which have inclinations and ground reflections within specified limits)" << '\n';
    cout << '\t' << '\t' << "Parameter"  << '\t' << "Units" << '\t' << '\t' << "Default Value" << '\n';
    cout << '\t' << '\t' << "---------------------------------------------" << '\n';
    cout << '\t' << '\t' << "theta_min"         << '\t' << "degrees"            << '\t' << '\t' << "1.0" << '\n';
    cout << '\t' << '\t' << "theta_max"         << '\t' << "degrees"            << '\t' << '\t' << "45.0" << '\n';
    cout << '\t' << '\t' << "bnc_min"           << '\t' << '\t' << "integer"    << '\t' << '\t' << "0" << '\n';
    cout << '\t' << '\t' << "bnc_max"           << '\t' << '\t' << "integer"    << '\t' << '\t' << "0" << '\n';
    cout << '\t' << '\t' << "bounces"           << '\t' << '\t' << "See Manual" << '\t' << "0" << '\n';
    cout << '\t' << '\t' << "lat_src"           << '\t' << '\t' << "degrees"    << '\t' << '\t' << "30.0" << '\n';
    cout << '\t' << '\t' << "lon_src"           << '\t' << '\t' << "degrees"    << '\t' << '\t' << "0.0" << '\n';
    cout << '\t' << '\t' << "z_src"             << '\t' << '\t' << "km"         << '\t' << '\t' << "0.0" << '\n';
    cout << '\t' << '\t' << "lat_rcvr"          << '\t' << "degrees"            << '\t' << '\t' << "30" << '\n';
    cout << '\t' << '\t' << "lon_rcvr"          << '\t' << "degrees"            << '\t' << '\t' << "-2.5" << '\n';
    cout << '\t' << '\t' << "Verbose"           << '\t' << '\t' << "True/False" << '\t' << "False" << '\n';
    cout << '\t' << '\t' << "iterations"        << '\t' << "integer"            << '\t' << '\t' << "25" << '\n';
    cout << '\t' << '\t' << "azimuth_err_lim"   << '\t' << "degrees"            << '\t' << '\t' << "2.0" << '\n' << '\n';
    
    cout << '\t' << "-eig_direct (Search for a single eigenray connecting a source at (lat_src, lon_src, z_src) to a receiver " << '\n';
    cout << '\t' << '\t' << '\t' << "at (lat_rcvr, lon_rcvr, z_grnd) near an estiamted azimuth and inclination assuming a specific number of ground reflections)" << '\n';
    cout << '\t' << '\t' << "Parameter"  << '\t' << "Units" << '\t' << '\t' << "Default Value" << '\n';
    cout << '\t' << '\t' << "---------------------------------------------" << '\n';
    cout << '\t' << '\t' << "theta_est"         << '\t' << "degrees"            << '\t' << '\t' << "15.0" << '\n';
    cout << '\t' << '\t' << "phi_est"           << '\t' << '\t' << "degrees"    << '\t' << '\t' << "great circle bearing from source to receiver" << '\n';
    cout << '\t' << '\t' << "bounces"           << '\t' << '\t' << "integer"    << '\t' << '\t' << "2" << '\n';
    cout << '\t' << '\t' << "lat_src"           << '\t' << '\t' << "degrees"    << '\t' << '\t' << "30.0" << '\n';
    cout << '\t' << '\t' << "lon_src"           << '\t' << '\t' << "degrees"    << '\t' << '\t' << "0.0" << '\n';
    cout << '\t' << '\t' << "z_src"             << '\t' << '\t' << "km"         << '\t' << '\t' << "0.0" << '\n';
    cout << '\t' << '\t' << "lat_rcvr"          << '\t' << "degrees"            << '\t' << '\t' << "30" << '\n';
    cout << '\t' << '\t' << "lon_rcvr"          << '\t' << "degrees"            << '\t' << '\t' << "10.0" << '\n';
    cout << '\t' << '\t' << "Verbose"           << '\t' << '\t' << "True/False" << '\t' << "False" << '\n';
    cout << '\t' << '\t' << "iterations"        << '\t' << "integer"            << '\t' << '\t' << "25" << '\n' << '\n';

    cout << '\t' << "Additional Parameters"  << '\t' << "Units/Options" << '\t' << "Default Value" << '\n';
    cout << '\t' << "---------------------------------------------" << '\n';
    cout << '\t' << "freq"              << '\t' << '\t' << '\t' << "Hz"         << '\t' << '\t' << "0.1" << '\n';
    cout << '\t' << "abs_coeff"         << '\t' << '\t' << "scalar"             << '\t' << '\t' << "0.3" << '\n';
    cout << '\t' << "z_grnd"            << '\t' << '\t' << '\t' << "km"         << '\t' << '\t' << "0.0" << '\n';
    cout << '\t' << "profile_format"    << '\t' << '\t' << "See Manual"         << '\t' << "zTuvdp" << '\n';
    cout << '\t' << "WriteCaustics*"    << '\t' << '\t' << "True/False"         << '\t' << "False" << '\n';
    cout << '\t' << "CalcAmp*"          << '\t' << '\t' << "True/False"         << '\t' << "True" << '\n';
    cout << '\t' << "alt_max"           << '\t' << '\t' << '\t' << "km"         << '\t' << '\t' << "Interpolation Max" << '\n';
    cout << '\t' << "rng_max"           << '\t' << '\t' << '\t' << "km"         << '\t' << '\t' << "10,000" << '\n' << '\n';
    cout << '\t' << "* denotes parameters not available in eigenray methods." << '\n' << '\n';
    
    cout << "Examples:" << '\n';
    cout << '\t' << "./GeoAcGlobal -prop ToyAtmo.met bounces=5 azimuth=-90.0 rng_max=1500.0" << '\n';
    cout << '\t' << "./GeoAcGlobal -prop ToyAtmo.met lat_src=41.131 lon_src=-112.896 bounces=0 phi_min=-120.0 phi_max=-60.0 phi_step=2.0 WriteRays=False" << '\n';
    cout << '\t' << "./GeoAcGlobal -eig_search ToyAtmo.met lat_src=41.131 lon_src=-112.896 lat_rcvr=38.430 lon_rcvr=-118.304 verbose=True" << '\n' << '\n';
    
}

void GeoAcGlobal_RunProp(char* inputs[], int count){
    double theta_min = 0.5, theta_max=45.0, theta_step=0.5;
    double phi_min=-90.0, phi_max=-90.0, phi_step=1.0;
    int bounces=2;
    double lat_src=30.0, lon_src=0.0, z_src=0.0;
    bool CalcAmp=true, WriteAtmo=false, WriteRays=true, WriteCaustics=false;
    double freq=0.1;
    char* ProfileFormat = "zTuvdp";
    char input_check;
    z_grnd=0.0;
    tweak_abs=0.3;
   
    // skip executable name, and -prop, and filename
    for(int i = 3; i < count; i++) 
      if (strncmp(inputs[i], "profile_format=",15) == 0){
        ProfileFormat = inputs[i]+15;
      }

    // Create and load a new SplineStruct (see Code/Atmo/G2S_GlobalSpine1D.h)
    // Each thread will get its own copy
    SplineStruct splines;
    Spline_Single_G2S(inputs[2],ProfileFormat, splines); // Load profile into spline
    //cout << sizeof(splines.Temp_Spline.x_vals) / sizeof(splines.Temp_Spline.x_vals[0]) << endl;

    
    for(int i = 3; i < count; i++){
        if (strncmp(inputs[i], "theta_min=",10) == 0){
            theta_min = atof(inputs[i]+10);}
        else if (strncmp(inputs[i], "theta_max=",10) == 0){
            theta_max = atof(inputs[i]+10);}
        else if (strncmp(inputs[i], "theta_step=",11) == 0){
            theta_step = atof(inputs[i]+11);}
        else if (strncmp(inputs[i], "phi_min=",8) == 0){
            phi_min = atof(inputs[i]+8);}
        else if (strncmp(inputs[i], "phi_max=",8) == 0){
            phi_max = atof(inputs[i]+8);}
        else if (strncmp(inputs[i], "phi_step=",9) == 0){
           phi_step = atof(inputs[i]+9);}
        else if (strncmp(inputs[i], "azimuth=",8) == 0){
            phi_min = atof(inputs[i]+8);
            phi_max = atof(inputs[i]+8);
            phi_step = 1.0;
        }else if (strncmp(inputs[i], "bounces=",8) == 0){
            bounces = atoi(inputs[i]+8);
        }else if (strncmp(inputs[i], "lat_src=",8) == 0){
            lat_src = atof(inputs[i]+8);
       }else if (strncmp(inputs[i], "lon_src=",8) == 0){
            lon_src = atof(inputs[i]+8);
       }else if (strncmp(inputs[i], "z_src=",6) == 0){
              z_src = atof(inputs[i]+6);
       } else if (strncmp(inputs[i], "z_grnd=",7) == 0){
             z_grnd = atof(inputs[i]+7);
       } else if (strncmp(inputs[i], "WriteAtmo=",10) == 0){
         WriteAtmo = string2bool(inputs[i]+10);
       } else if (strncmp(inputs[i], "WriteRays=",10) == 0){
         WriteRays = string2bool(inputs[i]+10);
       } else if (strncmp(inputs[i], "freq=",5) == 0){
               freq = atof(inputs[i]+5);
       } else if (strncmp(inputs[i], "abs_coeff=",10) == 0){
         tweak_abs = max(0.0, atof(inputs[i]+10));
       } else if (strncmp(inputs[i], "z_grnd=",7) == 0){
             z_grnd = atof(inputs[i]+7);
      } else if (strncmp(inputs[i], "profile_format=",15) == 0){
          ProfileFormat = inputs[i]+15;
      } else if (strncmp(inputs[i], "WriteCaustics=",14) == 0){
           WriteCaustics = string2bool(inputs[i]+14);
      } else if (strncmp(inputs[i], "CalcAmp=",8) == 0){
              CalcAmp = string2bool(inputs[i]+8);
      } else if (strncmp(inputs[i], "alt_max=",8) == 0){
            GeoAc_vert_limit = atof(inputs[i]+8);
      } else if (strncmp(inputs[i], "rng_max=",8) == 0){
             GeoAc_range_limit = atof(inputs[i]+8);
      } else{
       cout<<"***WARNING*** Unrecognized parameter entry: "<<inputs[i]<< '\n';
       cout << "Continue? (y/n):"; cin >> input_check;
       if(input_check!='y' && input_check!='Y') return; //TODO: No inputs
      }
    }
    z_src=max(z_src,z_grnd);
    if(WriteCaustics) CalcAmp=true;
    // This also sets GeoAc_EqCnt
    GeoAc_ConfigureCalcAmp(CalcAmp);
    
    // Extract the file name from the input and
    // use it to distinguish the resulting output
    char file_title[50];
    for(int m = 0; m < 50; m++){
        if(inputs[2][m]=='.'){
            file_title[m]='\0';
            break;
        }
        file_title[m]=inputs[2][m];
    }
    
    // Define variables used for analysis
    int length = GeoAc_ray_limit * int(1.0/(GeoAc_ds_min*10));
    char output_buffer [60];
	
    // Write the profile to file if neceessary, pass our new splines struct
    if(WriteAtmo) GeoAc_WriteProfile("atmo.dat", 90.0 - phi_min, splines);

    // Get number of threads
    int num_threads = omp_get_max_threads();
     
    // Create arrays of ofstreams, one for each thread  
    ofstream results[num_threads];
    ofstream raypaths[num_threads];
    ofstream caustics[num_threads][bounces + 1];

    // Write header information for the first thread's files
    for (int i = 0; i < num_threads; i++){
        sprintf(output_buffer, "%s_results_%i.dat", file_title, i);
        results[i].open(output_buffer);

        // Check if we should write to raypath files
        if (WriteRays){
            sprintf(output_buffer, "%s_raypaths_%i.dat", file_title, i);
            raypaths[i].open(output_buffer);
        }

        // Check if we should write to caustics files
        if (WriteCaustics){
            // Each thread (i) has a file for each bounce (j)
            for (int j = 0; j < bounces; j++){
                sprintf(output_buffer, "%s_caustics-path%i_%i.dat", file_title, j, i);
                caustics[i][j].open(output_buffer);
            }
        } 
    }

    //cout << omp_get_max_threads() << endl;

    // Convert longitude and latitude to radians
    lat_src *= TO_RAD;
    lon_src *= TO_RAD;
    
    /*double*** solutions;
    solutions = (double***)malloc(sizeof(double**) * num_threads);*/

    //cout << "Got to for loop" << endl;
  
    // Create an array of structs, one for each thread
    // Each thread needs its own struct to modify and read from
    SplineStruct spline_structs[num_threads];
    for (int i = 0; i < num_threads; i++){

        // Load profile into spline
        Spline_Single_G2S(inputs[2],ProfileFormat, spline_structs[i]);  

        //cout << splines.Temp_Spline.length << " = " << spline_structs[i].Temp_Spline.length << endl;
        //cout << sizeof(splines.Temp_Spline.x_vals) / sizeof(splines.Temp_Spline.x_vals[0]) << endl;
    }

    //cout << " Original r_vals = " << splines.r_vals[0] << endl;
 
    //cout << " Copy r_vals = " << spline_structs[0].r_vals[0] << endl;

    // Delete the original struct once it has been copied, we don't need it anymore
    //delete splines;
 
    // Start parallel, set out variables that can be shared - constants, 
    // information variables, angle variables, output_variables
    #pragma omp parallel default(shared)
/*default(none) shared(cout, cerr, r_earth, Pi, \
     solutions, length, bounces, freq, lat_src, lon_src, z_src, \
     phi_min, phi_max, phi_step, theta_min, theta_max, theta_step, \
     WriteRays, WriteCaustics, CalcAmp, results, raypaths, caustics, spline_structs) \
     private(k)*/
    {
      
      int tid = omp_get_thread_num();
      /*GeoAc_BuildSolutionArray(solutions[tid],length);
      double** solution = solutions[tid];*/
      double* solution = new double[GeoAc_EqCnt];

      //Get this thread's struct from the array
      SplineStruct splines = spline_structs[tid];

      //cout << "In Thread r_vals = " << splines.r_vals[0] << endl;

      //cout << "Opened thread " << tid << endl;

      //struct GeoAc_Sources_Struct sources;
      // Each thread gets its own struct (see Code/GeoAc/GeoAc.EquationSets.h)
      struct GeoAc_Sources_Struct sources = {
        {0.0, 0.0, 0.0}, 0.0,
        0.0, {0.0, 0.0, 0.0, 0.0, 0.0}, {{0.0, 0.0}, {0.0, 0.0}, {0.0, 0.0}},
        0.0, {0.0, 0.0, 0.0, 0.0, 0.0}, {{0.0, 0.0}, {0.0, 0.0}, {0.0, 0.0}},
        0.0, {0.0, 0.0, 0.0, 0.0, 0.0}, {{0.0, 0.0}, {0.0, 0.0}, {0.0, 0.0}},
        0.0, {0.0, 0.0, 0.0, 0.0, 0.0}, {{0.0, 0.0}, {0.0, 0.0}, {0.0, 0.0}},
        0.0, 0.0, {0.0, 0.0},
        {0.0, 0.0, 0.0}, 0.0, {{0.0, 0.0}, {0.0, 0.0}, {0.0, 0.0}}, {0.0, 0.0},
        {0.0, 0.0, 0.0}, {{0.0, 0.0}, {0.0, 0.0}, {0.0, 0.0}},
        {0.0, 0.0, 0.0}, {{0.0, 0.0}, {0.0, 0.0}, {0.0, 0.0}}
      };

      const int max_val = phi_max;
      const int step = phi_step;
      #pragma omp for
      for(int phi = phi_min; phi <= max_val; phi+=step){
          //cout << "in phi for loop " << phi << tid << endl;
          //cout << &sources << endl;
          for(int theta = theta_min;   theta <= theta_max; theta+=theta_step){
              int k;
            
              //cout << "in theta for loop " << tid << endl;
              cout << "Plotting ray path w/ theta = " << theta << ", phi = " << phi << '\n';
              double GeoAc_theta = double(theta)*TO_RAD;
              double GeoAc_phi = Pi/2.0 - double(phi)*TO_RAD;
            
              double** temp = &solution;
              GeoAc_SetInitialConditions(temp, z_src, lat_src, lon_src, GeoAc_theta, GeoAc_phi, sources, splines);

              //cout << "\nPrinting sources struct. Thread id: " << tid << endl;
              //PRINTSTRUCT(sources);

              double travel_time_sum = 0.0;
              double attenuation = 0.0;
              double r_max = 0.0;
            
              for(int bnc_cnt = 0; bnc_cnt <= bounces; bnc_cnt++){
                  double* final_vals = GeoAc_Propagate_RK4_2(solution, r_max, travel_time_sum, attenuation,
                                                    GeoAc_theta, GeoAc_phi, freq, CalcAmp, sources, 
                                                    splines, WriteRays ? &(raypaths[tid]) : nullptr,
                                                    WriteCaustics ? &(caustics[tid][bnc_cnt]) : nullptr);

                  if (final_vals == nullptr) break;

                  //cerr << "in bounce for loop " << tid << endl;
                
                  // This gets set to false at the beginining of Propogate_RK4()
/*                  bool BreakCheck;
                  k = GeoAc_Propagate_RK4(solution, BreakCheck, sources, splines);

                  //cerr << "Finished RK4 " << tid << endl;
                
                  if(WriteRays || WriteCaustics){
                      // Used to check for a change in sign from the result of GeoAc_Jacobian()
                      double D, D_prev;
                      if(WriteCaustics){                    
                          D_prev = GeoAc_Jacobian(solution,1, splines);
/Pi
                      }
                    
                      //cerr << "Made it to k for loop " << tid << endl;
                      for(int m = 1; m < k ; m++){     // write profiles to data files and vector arrays
                          if(WriteCaustics) D = GeoAc_Jacobian(solution,m, splines);
                          GeoAc_TravelTimeSegment(travel_time_sum, solution, m-1,m, splines);
                          if (m == 0) PRINTSPLINES(splines);
                          GeoAc_SB_AttenSegment(attenuation, solution, m-1, m, freq, splines);
                        
                          if(WriteRays && m % 25 == 0){
                              raypaths[tid] << solution[m][0] - r_earth;
                              raypaths[tid] << '\t' << setprecision(8) << solution[m][1] * TO_DEG;
                              raypaths[tid] << '\t' << setprecision(8) << solution[m][2] * TO_DEG;
                              if(CalcAmp){    raypaths[tid] << '\t' << 20.0*log10(GeoAc_Amplitude(solution,m,GeoAc_theta,
                                                                                          GeoAc_phi,sources, splines));}
                              else{           raypaths[tid] << '\t' << 0.0;}
                              raypaths[tid] << '\t' << -attenuation;
                              raypaths[tid] << '\t' << travel_time_sum << '\n';
                          }
                        
                          if(WriteCaustics && D*D_prev < 0.0){
                              caustics[tid][bnc_cnt] << solution[m][0] - r_earth;
                              caustics[tid][bnc_cnt] << '\t' << setprecision(8) << solution[m][1] * TO_DEG;
                              caustics[tid][bnc_cnt] << '\t' << setprecision(8) << solution[m][2] * TO_DEG;
                              caustics[tid][bnc_cnt] << '\t' << travel_time_sum << '\n';
                          }
                          if(WriteCaustics) D_prev = D;
                      }
                  } else {
                      travel_time_sum+= GeoAc_TravelTime(solution, k, splines);
                      attenuation+= GeoAc_SB_Atten(solution,k,freq, splines);
                  }
                
                  if(BreakCheck) break;
                  for(int m = 0; m < k ; m++) r_max = max (r_max, solution[m][0] - r_earth);*/
                
                  double GC_Dist1 = pow(sin((final_vals[1] - lat_src)/2.0),2);
                  double GC_Dist2 = cos(lat_src) * cos(final_vals[1]) * pow(sin((final_vals[2] - lon_src)/2.0),2);
                
                  double inclination = - asin(c(final_vals[0], final_vals[1], final_vals[2], splines.Temp_Spline) / c(r_earth + z_src, lat_src, lon_src, splines.Temp_Spline) * final_vals[3]) * TO_DEG;
                  double back_az = 90.0 - atan2(-final_vals[4], -final_vals[5]) * TO_DEG;
                  if(back_az < -180.0) back_az +=360.0;
                  if(back_az >  180.0) back_az -=360.0;
 
                  results[tid] << theta;
                  results[tid] << '\t' << phi;
                  results[tid] << '\t' << bnc_cnt;
                  results[tid] << '\t' << setprecision(8) << final_vals[1] * TO_DEG;
                  results[tid] << '\t' << setprecision(8) << final_vals[2] * TO_DEG;
                  results[tid] << '\t' << travel_time_sum;
                  results[tid] << '\t' << 2.0 * r_earth * asin(sqrt(GC_Dist1+GC_Dist2)) / travel_time_sum;
                  results[tid] << '\t' << r_max;
                  results[tid] << '\t' << inclination;
                  results[tid] << '\t' << back_az;
                  if(CalcAmp){    results[tid] << '\t' << 20.0*log10(GeoAc_Amplitude(&final_vals,0,GeoAc_theta,GeoAc_phi,sources, splines));}
                  else{           results[tid] << '\t' << 0.0;}
                  results[tid] << '\t' << -attenuation;
                  results[tid] << '\n';                
              }
              if(WriteRays){raypaths[tid] << '\n';}
          }
          results[tid] << '\n';
          //GeoAc_ClearSolutionArray(solution, k);
      }
      // Close files for this specific thread
      raypaths[tid].close();
      results[tid].close();
      // Close the caustics files for each bounce
      for (int i = 0; i < bounces; i++){
          caustics[tid][i].close();
      }
      //GeoAc_DeleteSolutionArray(solution, length);
    }// End omp parallelization

    // Create master files to combine each thread's files into
    ofstream final_results, final_raypaths, final_caustics[bounces];

    // Write header information for each file type
    sprintf(output_buffer, "%s_results_%ithreads.dat", file_title, num_threads);
    final_results.open(output_buffer);
    final_results << "# theta [deg]";
    final_results << '\t' << "phi [deg]";
    final_results << '\t' << "n_b";
    final_results << '\t' << "lat_0 [deg]";
    final_results << '\t' << "lon_0 [deg]";
    final_results << '\t' << "Travel Time [s]";
    final_results << '\t' << "Celerity [km/s]";
    final_results << '\t' << "Turning Height [km]";
    final_results << '\t' << "Inclination [deg]";
    final_results << '\t' << "Back Azimuth [deg]";
    final_results << '\t' << "Geo. Atten. [dB]";
    final_results << '\t' << "Atmo. Atten. [dB]";
    final_results << '\n';

    if (WriteRays){
        sprintf(output_buffer, "%s_raypaths_%ithreads.dat", file_title, num_threads);
        final_raypaths.open(output_buffer);
        final_raypaths << "# z [km]";
        final_raypaths << '\t' << "Lat [deg]";
        final_raypaths << '\t' << "Long [deg]";
        final_raypaths << '\t' << "Geo. Atten. [dB]";
        final_raypaths << '\t' << "Atmo. Atten. [dB]";
        final_raypaths << '\t' << "Travel Time [s]";
        final_raypaths << '\n';
    }

    if (WriteCaustics){
        for (int j = 0; j < bounces; j++){
            sprintf(output_buffer, "%s_caustics-path%i_%ithreads.dat", file_title, j, num_threads);
            final_caustics[j].open(output_buffer);
            final_caustics[j] << "# z [km]";
            final_caustics[j] << '\t' << "Lat [deg]";
            final_caustics[j] << '\t' << "Long [deg]";
            final_caustics[j] << '\t' << "Travel Time [s]";
            final_caustics[j] << '\n';
        }
    }

    // Combine all files
    for (int i = 0; i < num_threads; i++){
        // Get the file name
        sprintf(output_buffer, "%s_results_%i.dat", file_title, i);
        // Open the file in read mode
        ifstream temp(output_buffer);
        // Append to our main file
        final_results << temp.rdbuf();
        // Close the file
        temp.close();
        // Delete the file
        remove(output_buffer);

        // Repeat for raypaths
        if (WriteRays){
            sprintf(output_buffer, "%s_raypaths_%i.dat", file_title, i);
            ifstream temp(output_buffer);
            final_raypaths << temp.rdbuf();
            temp.close();
            remove(output_buffer);
        }

        // Repeat for each caustics bounce file
        if (WriteCaustics){
            for (int j = 0; j < bounces; j++){
                sprintf(output_buffer, "%s_caustics-path%i_%i.dat", file_title, j, i);
                ifstream temp(output_buffer);
                final_caustics[j] << temp.rdbuf();
                temp.close();
                remove(output_buffer);
            }
        }
    }

    // Close all files
    final_results.close();
    final_raypaths.close();
    for (int j = 0; j < bounces; j++){
        final_caustics[j].close();
    }
}

/*
void GeoAcGlobal_RunInteractive(char* inputs[], int count){
    double lat_src=30.0, lon_src=0.0, z_src=0.0;
    double freq=0.1, D, D_prev;
    bool CalcAmp=true, WriteCaustics=false;
    char* ProfileFormat = "zTuvdp";
    char input_check;
    z_grnd=0.0;
    
    for(int i = 3; i < count; i++) if (strncmp(inputs[i], "profile_format=",15) == 0){ ProfileFormat = inputs[i]+15;}
    Spline_Single_G2S(inputs[2],ProfileFormat);
    
    for(int i = 3; i < count; i++){
        if (strncmp(inputs[i], "lat_src=",8) == 0){                 lat_src = atof(inputs[i]+8);}
        else if (strncmp(inputs[i], "lon_src=",8) == 0){            lon_src = atof(inputs[i]+8);}
        else if (strncmp(inputs[i], "z_src=",6) == 0){              z_src = atof(inputs[i]+6);}        

        else if (strncmp(inputs[i], "freq=",5) == 0){               freq = atof(inputs[i]+5);}
        else if (strncmp(inputs[i], "abs_coeff=",10) == 0){         tweak_abs = max(0.0, atof(inputs[i]+10));}
        else if (strncmp(inputs[i], "z_grnd=",7) == 0){             z_grnd = atof(inputs[i]+7);}
        else if (strncmp(inputs[i], "profile_format=",15) == 0){    ProfileFormat = inputs[i]+15;}
        else if (strncmp(inputs[i], "WriteCaustics=",14) == 0){     WriteCaustics = string2bool(inputs[i]+14);}
        else if (strncmp(inputs[i], "CalcAmp=",8) == 0){            CalcAmp = string2bool(inputs[i]+8);}
        else if (strncmp(inputs[i], "alt_max=",8) == 0){            GeoAc_vert_limit = atof(inputs[i]+8);}
        else if (strncmp(inputs[i], "rng_max=",8) == 0){            GeoAc_range_limit = atof(inputs[i]+8);}
        else{
            cout << "***WARNING*** Unrecognized parameter entry: " << inputs[i] << '\n';
            cout << "Continue? (y/n):"; cin >> input_check;
            if(input_check!='y' && input_check!='Y') return;
        }
    }
    z_src=max(z_src,z_grnd);
    if(WriteCaustics) CalcAmp=true;
    
    Spline_Single_G2S(inputs[2],ProfileFormat);         // Load profile into spline
    GeoAc_ConfigureCalcAmp(CalcAmp);       // State if amplitude coefficient is to be calculated
    
    // Extract the file name from the input and use it to distinguish the resulting output
    char file_title[50];
    for(int m = 0; m < 50; m++){
        if(inputs[2][m]=='.'){
            file_title[m]='\0';
            break;
        }
        file_title[m]=inputs[2][m];
    }
    
    double theta, phi;
    int bnc_cnt;
    char keepgoing;
    
    // Define variables used for analysis
    double travel_time_sum, attenuation, r_max;
    int k, length = GeoAc_ray_limit * int(1.0/(GeoAc_ds_min*10));
    bool BreakCheck;
    
    ofstream raypath;
    ofstream caustics;
    
    double** solution;
    GeoAc_BuildSolutionArray(solution,length);

    GeoAc_Sources_Struct sources;
    
    keepgoing='y';
    while(keepgoing=='y' || keepgoing=='Y'){
        raypath.open("raypath.dat");
        
        raypath << "# z [km]";
        raypath << '\t' << "lat [deg]";
        raypath << '\t' << "lon [deg]";
        raypath << '\t' << "Geo. Atten. [dB]";
        raypath << '\t' << "Atmo. Atten. [dB]";
        raypath << '\t' << "Travel Time [s]";
        raypath << '\n';
        
        if(WriteCaustics){
            caustics.open("caustics.dat");
            
            caustics << "# z [km]";
            caustics << '\t' << "lat [deg]";
            caustics << '\t' << "lon [deg]";
            caustics << '\t' << "Travel Time [s]";
            caustics << '\n';
        }
        
        cout << '\t' << "Enter inclination angle [degrees]: ";  cin >> theta;
        cout << '\t' << "Enter azimuth angle [degrees]: ";      cin >> phi;
        cout << '\t' << "Enter number of bounces: ";            cin >> bnc_cnt;
        
        cout << '\n';
        cout << '\t' << "Plotting ray path w/ theta = " << theta << ", phi = " << phi << '\n';
        double GeoAc_theta = theta*Pi/180.0;
        double GeoAc_phi = Pi/2.0 - phi*Pi/180.0;
        
        GeoAc_SetInitialConditions(solution, z_src, lat_src*Pi/180.0, lon_src*Pi/180.0, GeoAc_theta, GeoAc_phi, sources);
        travel_time_sum = 0.0;
        attenuation = 0.0;
        r_max = 0.0;
		
        for(int bnc = 0; bnc <= bnc_cnt; bnc++){
            k = GeoAc_Propagate_RK4(solution, BreakCheck, sources);
            if(WriteCaustics){ D_prev = GeoAc_Jacobian(solution,1);}
            
            for(int m = 1; m < k ; m++){     // write profiles to data files and vector arrays
                GeoAc_TravelTimeSegment(travel_time_sum, solution, m-1,m);
                GeoAc_SB_AttenSegment(attenuation, solution, m-1, m, freq);
                r_max = max(r_max, solution[m][0] - r_earth);
                if(WriteCaustics){ D = GeoAc_Jacobian(solution,m);}
                
                if(m % 25 == 0){
                    raypath << solution[m][0] - r_earth;
                    raypath << '\t' << setprecision(8) << solution[m][1] * 180.0/Pi;
                    raypath << '\t' << setprecision(8) << solution[m][2] * 180.0/Pi;
                    if(CalcAmp){    raypath << '\t' << 20.0*log10(GeoAc_Amplitude(solution,m,GeoAc_theta,GeoAc_phi,sources));}
                    else{           raypath << '\t' << 0.0;}
                    raypath << '\t' << -attenuation;
                    raypath << '\t' << travel_time_sum;
                    raypath << '\n';
                }
                if(WriteCaustics && D*D_prev < 0.0){
                    caustics << solution[m][0] - r_earth;
                    caustics << '\t' << setprecision(8) << solution[m][1] * 180.0/Pi;
                    caustics << '\t' << setprecision(8) << solution[m][1] * 180.0/Pi;
                    caustics <<'\t' << travel_time_sum << '\n';
                    caustics << '\n';
                }
                if(WriteCaustics){D_prev = D;}
            }
            if(BreakCheck) break;
            GeoAc_SetReflectionConditions(solution,k, sources);
        }
        
        double GC_Dist1 = pow(sin((solution[k][1] - lat_src*Pi/180.0)/2.0),2);
        double GC_Dist2 = cos(lat_src*Pi/180.0) * cos(solution[k][1]) * pow(sin((solution[k][2] - lon_src*Pi/180.0)/2.0),2);
        double range = 2.0 * r_earth * asin(sqrt(GC_Dist1 + GC_Dist2));
        
        double arg1 = sin((solution[k][2] - lon_src*Pi/180.0));
        double arg2 = cos(lat_src*Pi/180.0)*tan(solution[k][1]) - sin(lat_src*Pi/180.0)*cos((solution[k][2]-lon_src*Pi/180.0));
        double bearing = atan2(arg1, arg2)*180.0/Pi;
        
        double back_az = 90.0 - atan2(-solution[k][4], -solution[k][5]) * 180.0 / Pi;
        if(back_az < -180.0) back_az +=360.0;
        if(back_az >  180.0) back_az -=360.0;
        
        if(!BreakCheck){
            cout << '\t' << '\t' << "Ray path arrived at " << solution[k][1]*180.0/Pi << " degrees latitude, " << solution[k][2]*180.0/Pi << " degrees longitude." << '\n';
            cout << '\t' << '\t' << "Arrival range = " << range << " km at azimuth " << bearing << " degrees from N." << '\n';
            if(CalcAmp) cout << '\t' << '\t' << "Geometric attenuation = " << 20.0*log10(GeoAc_Amplitude(solution,k,GeoAc_theta,GeoAc_phi,sources)) << " dB." << '\n';
            cout << '\t' << '\t' << "Atmospheric attenuation = " << -attenuation << " dB." << '\n';
            cout << '\t' << '\t' << "Arrival celerity = " << range/travel_time_sum << "km/sec." << '\n';
            cout << '\t' << '\t' << "Back azimuth of the arrival = " << back_az  << " degrees from N. " << '\n' << '\n';
        } else {
            cout << '\t' << '\t' << "Ray path does not return to the ground." << '\n' << '\n';
        }
        raypath.close();
        if(WriteCaustics) caustics.close();

        cout << "Continue plotting other ray paths? (y/n): ";
        cin >> keepgoing;
    }
    GeoAc_DeleteSolutionArray(solution, length);
    
}

void GeoAcGlobal_RunEigSearch(char* inputs[], int count){
    double Source_Loc [3]   = {30.0, 0.0, 0.0};
    double Receiver_Loc [2] = {30.0, -2.5};
    double theta_min = 0.5, theta_max = 45.0;
    int bnc_min = 0, bnc_max = 0;
    int iterations=25;
    double azimuth_err_lim=2.0;
    verbose_output=false;
    double freq = 0.1;
    char* ProfileFormat = "zTuvdp";
    char input_check;
    z_grnd=0.0;
    tweak_abs=0.3;
    
    for(int i = 3; i < count; i++) if (strncmp(inputs[i], "profile_format=",15) == 0){ ProfileFormat = inputs[i]+15;}
    Spline_Single_G2S(inputs[2],ProfileFormat);
    
    for(int i = 3; i < count; i++){
        if (strncmp(inputs[i], "theta_min=",10) == 0){              theta_min = atof(inputs[i]+10);}
        else if (strncmp(inputs[i], "theta_max=",10) == 0){         theta_max = atof(inputs[i]+10);}
        else if (strncmp(inputs[i], "bnc_min=",8) == 0){            bnc_min = atoi(inputs[i]+8);}
        else if (strncmp(inputs[i], "bnc_max=",8) == 0){            bnc_max = atoi(inputs[i]+8);}
        else if (strncmp(inputs[i], "bounces=",8) == 0){
            bnc_min = atoi(inputs[i]+8);
            bnc_max = atoi(inputs[i]+8);
        }
        else if (strncmp(inputs[i], "lat_src=",8) == 0){            Source_Loc[0] = atof(inputs[i]+8);}
        else if (strncmp(inputs[i], "lon_src=",8) == 0){            Source_Loc[1] = atof(inputs[i]+8);}
        else if (strncmp(inputs[i], "z_src=",6) == 0){              Source_Loc[2] = atof(inputs[i]+6);}
        else if (strncmp(inputs[i], "lat_rcvr=",9) == 0){           Receiver_Loc[0] = atof(inputs[i]+9);}
        else if (strncmp(inputs[i], "lon_rcvr=",9) == 0){           Receiver_Loc[1] = atof(inputs[i]+9);}
        
        else if (strncmp(inputs[i], "Verbose=",8) == 0){            verbose_output = string2bool(inputs[i]+8);}
        else if (strncmp(inputs[i], "verbose=",8) == 0){            verbose_output = string2bool(inputs[i]+8);}
        else if (strncmp(inputs[i], "azimuth_err_lim=",16) == 0){   azimuth_err_lim=atof(inputs[i]+16);}
        else if (strncmp(inputs[i], "iterations=",11) == 0){        iterations=atof(inputs[i]+11);}
        
        else if (strncmp(inputs[i], "freq=",5) == 0){               freq = atof(inputs[i]+5);}
        else if (strncmp(inputs[i], "abs_coeff=",10) == 0){         tweak_abs = max(0.0, atof(inputs[i]+10));}
        else if (strncmp(inputs[i], "z_grnd=",7) == 0){             z_grnd = atof(inputs[i]+7);}
        else if (strncmp(inputs[i], "profile_format=",15) == 0){    ProfileFormat = inputs[i]+15;}
        else if (strncmp(inputs[i], "alt_max=",8) == 0){            GeoAc_vert_limit = atof(inputs[i]+8);}
        else if (strncmp(inputs[i], "rng_max=",8) == 0){            GeoAc_range_limit = atof(inputs[i]+8);}
        else{
            cout << "***WARNING*** Unrecognized parameter entry: " << inputs[i] << '\n';
            cout << "Continue? (y/n):"; cin >> input_check;
            if(input_check!='y' && input_check!='Y') return;
        }
    }
    Source_Loc[2] = max(Source_Loc[2], z_grnd);
    
    Spline_Single_G2S(inputs[2],ProfileFormat);       // Load profile into spline
    
    // Extract the file name from the input and use it to distinguish the resulting output
    char output_buffer[60];
    char file_title[50];
    for(int m = 0; m < 50; m++){
        if(inputs[2][m]=='.'){
            file_title[m]='\0';
            break;
        }
        file_title[m]=inputs[2][m];
    }
    
    double theta_start, theta_next, theta_est, phi_est;
    bool estimate_success;
    
    sprintf(output_buffer, "%s_results.dat", file_title);
    results.open(output_buffer);
    
    results << "GeoAcGlobal - Eigenray Run Summary:" << '\n';
    results << '\t' << "Profile used: " << inputs[2] << '\n';
    results << '\t' << "Source Location (lat, lon, elev) : (" << Source_Loc[0] << ", " << Source_Loc[1] << ", " <<  Source_Loc[2] << ")." << '\n';
    results << '\t' << "Receiver Location (lat, lon, elev) : (" << Receiver_Loc[0] << ", " << Receiver_Loc[1] << ", " << z_grnd << ")." << '\n';
    results << '\t' << "Inclination range (degrees): " << theta_min << " - " << theta_max << "." << '\n';
    results << '\t' << "Ground reflection (bounce) limits: " << bnc_min << " - " << bnc_max << "." << '\n' << '\n';
 
    GeoAc_Sources_Struct sources;   
    for(int n_bnc = bnc_min; n_bnc <= bnc_max; n_bnc++){
        cout << "Searching for " << n_bnc << " bounce eigenrays." << '\n';
        
        theta_start = theta_min;
        while(theta_start < theta_max){
            estimate_success = GeoAc_EstimateEigenray(Source_Loc, Receiver_Loc, theta_start, theta_max, theta_est, phi_est, 
                                                      theta_next, n_bnc, azimuth_err_lim, sources);
            if(estimate_success)  GeoAc_3DEigenray_LM(Source_Loc, Receiver_Loc, theta_est, phi_est, freq, n_bnc, iterations, file_title, sources);
            
            theta_start = theta_next;
        }
    }

    results.close();
    cout << "Identified " << eigenray_count << " eigenray(s)." << '\n';
    
}

void GeoAcGlobal_RunEigDirect(char* inputs[], int count){
    double Source_Loc [3]   = {30.0, 0.0, 0.0};
    double Receiver_Loc [2] = {30.0, -2.5};
    double theta_est = 10.0, phi_est=45.0;
    int bounces = 0;
    int iterations=25;
    verbose_output=false;
    double freq = 0.1;
    char* ProfileFormat = "zTuvdp";
    char input_check;
    z_grnd=0.0;
    tweak_abs=0.3;
    
    for(int i = 3; i < count; i++) if (strncmp(inputs[i], "profile_format=",15) == 0){ ProfileFormat = inputs[i]+15;}
    Spline_Single_G2S(inputs[2],ProfileFormat);
    
    for(int i = 3; i < count; i++){
        if (strncmp(inputs[i], "theta_est=",10) == 0){              theta_est = atof(inputs[i]+10);}
        else if (strncmp(inputs[i], "bounces=",8) == 0){            bounces = atoi(inputs[i]+8);}
        else if (strncmp(inputs[i], "lat_src=",8) == 0){            Source_Loc[0] = atof(inputs[i]+8);}
        else if (strncmp(inputs[i], "lon_src=",8) == 0){            Source_Loc[1] = atof(inputs[i]+8);}
        else if (strncmp(inputs[i], "z_src=",6) == 0){              Source_Loc[2] = atof(inputs[i]+6);}
        else if (strncmp(inputs[i], "lat_rcvr=",9) == 0){           Receiver_Loc[0] = atof(inputs[i]+9);}
        else if (strncmp(inputs[i], "lon_rcvr=",9) == 0){           Receiver_Loc[1] = atof(inputs[i]+9);}
        else if (strncmp(inputs[i], "Verbose=",8) == 0){            verbose_output = string2bool(inputs[i]+8);}
        else if (strncmp(inputs[i], "verbose=",8) == 0){            verbose_output = string2bool(inputs[i]+8);}
        else if (strncmp(inputs[i], "iterations=",11) == 0){        iterations=atof(inputs[i]+11);}
        
        else if (strncmp(inputs[i], "freq=",5) == 0){               freq = atof(inputs[i]+5);}
        else if (strncmp(inputs[i], "abs_coeff=",10) == 0){         tweak_abs = max(0.0, atof(inputs[i]+10));}
        else if (strncmp(inputs[i], "z_grnd=",7) == 0){             z_grnd = atof(inputs[i]+7);}
        else if (strncmp(inputs[i], "profile_format=",15) == 0){    ProfileFormat = inputs[i]+15;}
        else if (strncmp(inputs[i], "alt_max=",8) == 0){            GeoAc_vert_limit = atof(inputs[i]+8);}
        else if (strncmp(inputs[i], "rng_max=",8) == 0){            GeoAc_range_limit = atof(inputs[i]+8);}
        else{
            cout << "***WARNING*** Unrecognized parameter entry: " << inputs[i] << '\n';
            cout << "Continue? (y/n):"; cin >> input_check;
            if(input_check!='y' && input_check!='Y') return;
        }
    }
    Source_Loc[2] = max(Source_Loc[2], z_grnd);

    // Set the phi_start angle by the great circle bearing to the receiver and then change it if it's been input
    phi_est=90.0 - Calc_Bearing(Source_Loc[0], Source_Loc[1], Receiver_Loc[0], Receiver_Loc[1]);
    for(int i = 3; i < count; i++){
        if (strncmp(inputs[i], "phi_est=",8) == 0){                 phi_est = 90.0 - atof(inputs[i]+8);}
    }
    
    Spline_Single_G2S(inputs[2], ProfileFormat);         // Load profile into spline
    
    // Extract the file name from the input and use it to distinguish the resulting output
    char file_title[50];
    for(int m = 0; m < 50; m++){
        if(inputs[2][m]=='.'){
            file_title[m]='\0';
            break;
        }
        file_title[m]=inputs[2][m];
    }

    GeoAc_Sources_Struct sources;
    GeoAc_3DEigenray_LM(Source_Loc, Receiver_Loc, theta_est, phi_est, freq, bounces, iterations, file_title, sources);
}*/



int main(int argc, char* argv[]){
    int skip = 3;
    
    if(argc < 3){
        GeoAcGlobal_Usage();
        return 0;
    }
    
    if (strncmp(argv[1], "-prop",5) == 0){
        GeoAcGlobal_RunProp(argv, argc);
    
    } else if (strncmp(argv[1], "-interactive",12) == 0){
        //GeoAcGlobal_RunInteractive(argv, argc);
        
    } else if (strncmp(argv[1], "-eig_search",11) == 0){
        //GeoAcGlobal_RunEigSearch(argv, argc);
        
    } else if (strncmp(argv[1], "-eig_direct",11) == 0){
        //GeoAcGlobal_RunEigDirect(argv, argc);
        
    } else {
        cout << "Unrecognized option: " << argv[1] << '\n';
    }
    
    
    
    return 0;
}
