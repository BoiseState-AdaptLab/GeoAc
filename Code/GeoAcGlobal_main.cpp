// Added this include to access OpenMP
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
//#include "GeoAc/GeoAc.Eigenray.h"

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
    
    for(int i = 3; i < count; i++) if (strncmp(inputs[i], "profile_format=",15) == 0){ ProfileFormat = inputs[i]+15;}

    // Create and set up the Splines_Struct here
    Splines_Struct _splines;
    Spline_Single_G2S(inputs[2],ProfileFormat, _splines); // Load profile into spline
    
    for(int i = 3; i < count; i++){
        if (strncmp(inputs[i], "theta_min=",10) == 0){              theta_min = atof(inputs[i]+10);}
        else if (strncmp(inputs[i], "theta_max=",10) == 0){         theta_max = atof(inputs[i]+10);}
        else if (strncmp(inputs[i], "theta_step=",11) == 0){        theta_step = atof(inputs[i]+11);}
        else if (strncmp(inputs[i], "phi_min=",8) == 0){            phi_min = atof(inputs[i]+8);}
        else if (strncmp(inputs[i], "phi_max=",8) == 0){            phi_max = atof(inputs[i]+8);}
        else if (strncmp(inputs[i], "phi_step=",9) == 0){           phi_step = atof(inputs[i]+9);}
        else if (strncmp(inputs[i], "azimuth=",8) == 0){
            phi_min = atof(inputs[i]+8);
            phi_max = atof(inputs[i]+8);
            phi_step = 1.0;
        }
        else if (strncmp(inputs[i], "bounces=",8) == 0){            bounces = atoi(inputs[i]+8);}
        else if (strncmp(inputs[i], "lat_src=",8) == 0){            lat_src = atof(inputs[i]+8);}
        else if (strncmp(inputs[i], "lon_src=",8) == 0){            lon_src = atof(inputs[i]+8);}
        else if (strncmp(inputs[i], "z_src=",6) == 0){              z_src = atof(inputs[i]+6);}
        else if (strncmp(inputs[i], "z_grnd=",7) == 0){             z_grnd = atof(inputs[i]+7);}
        else if (strncmp(inputs[i], "WriteAtmo=",10) == 0){         WriteAtmo = string2bool(inputs[i]+10);}
        else if (strncmp(inputs[i], "WriteRays=",10) == 0){         WriteRays = string2bool(inputs[i]+10);}

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
    GeoAc_ConfigureCalcAmp(CalcAmp);
    
    // Extract the file name from the input and use it to distinguish the resulting output
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
	
    // Write the profile to file if neceessary
    if(WriteAtmo) GeoAc_WriteProfile("atmo.dat", 90.0 - phi_min, _splines);
       
    // Get number of threads
    int num_threads = omp_get_max_threads();
     

    // Split into multiple threads here
    // Each thread gets its own splines struct
    #pragma omp parallel
    {
      // Get this thread's id
      int tid = omp_get_thread_num();

      // This is our initial conditions array
      double* initial_conds = new double[GeoAc_EqCnt];
  
      // Create a local instance of thise struct to be passed to other functions
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
 
      // Copy Splines_Struct set up earlier
      Splines_Struct splines = _splines;

      // Set up output files
      ofstream results;
      ofstream raypaths;
      // For the caustics file, a file is created for each bounce
      // However only one file needs to be written to at a time so
      // this ofstream will just be reused
      ofstream caustics;

      // Open each file and set its decimal precision to 8
      sprintf(output_buffer, "%s_results_%i.dat", file_title, tid);
      results.open(output_buffer);
      results << setprecision(8);

      // Check if we should write to raypathsfiles
      if (WriteRays){
          sprintf(output_buffer, "%s_raypaths%i.dat", file_title, tid);
          raypaths.open(output_buffer);
          raypaths << setprecision(8);
      }

      // Check if we should write to caustics files
      if (WriteCaustics) {
          // We don't need to open the caustics file as it is opened autmatically
          // in the bounce for loop
          // However we do need to clear each caustics file
          for (int bnc = 0; bnc <= bounces; bnc++) {
              sprintf(output_buffer, "%s_caustics-path%i_%i.dat", file_title, bnc, tid);
              caustics.open(output_buffer);
              caustics << setprecision(8);
              caustics.close();
          }
      }


      // Split up for loop
      #pragma omp for 
      // Openmp won't allow non-integer increments like phi_step
      // Instead we define 0 <= t <= int((phi_max - phi_min) / phi_step), t++
      // where phi = phi_min + phi_step * t
      for(int t = 0; t <= int((phi_max - phi_min) / phi_step); t++){
          // Perform substituion
          double phi = phi_min + phi_step * t;

          // Calculate our phi angle
          double GeoAc_phi = Pi/2.0 - phi*Pi/180.0;
          for(double theta = theta_min; theta <= theta_max; theta += theta_step){
              cout << "Plotting ray path w/ theta = " << theta << ", phi = " << phi << '\n';

              // Calculate our theta angle
              double GeoAc_theta = theta*Pi/180.0;
              
	      double** temp = &initial_conds;
              GeoAc_SetInitialConditions(temp, z_src, lat_src*Pi/180.0, lon_src*Pi/180.0,
                                         GeoAc_theta, GeoAc_phi, sources, splines);
 
              // This variable have been moved to this context
              int k;
              
              for(int bnc_cnt = 0; bnc_cnt <= bounces; bnc_cnt++){ 
                  if (WriteCaustics) {
                      // Open the caustics file for this bounce
                      sprintf(output_buffer, "%s_caustics-path%i_%i.dat", file_title, bnc_cnt, tid);
                      caustics.open(output_buffer,fstream::app);
                  }
                 
                  if (GeoAc_Propagate_RK4(initial_conds, CalcAmp, bnc_cnt,
                                          freq, GeoAc_theta, GeoAc_phi,
                                          lat_src, lon_src, z_src,
                                          sources, splines,
                                          results, raypaths, caustics)) {
                      break;
                  }                  
              } // End bounce loop
              if(WriteRays){raypaths << '\n';}
          } // End theta loop
          results << '\n';
      } // End phi loop

      // Close files for this specific thread
      raypaths.close();
      results.close();
      // We don't need to close the caustics file as it is automatically closed
      // in the bounce for loop

    } // End omp parallelization	

    // Create master files to combine each thread's files into
    ofstream final_results, final_raypaths,  final_caustics[bounces];

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
        ifstream temp;

        // Get the file name
        sprintf(output_buffer, "%s_results_%i.dat", file_title, i);
        // Open the file in read mode
        temp.open(output_buffer);
        // Append to our main file
        final_results << temp.rdbuf();
        // Close the file
        temp.close();
        // Delete the file
        remove(output_buffer);

        // Repeat for raypath
        if (WriteRays){
            sprintf(output_buffer, "%s_raypaths%i.dat", file_title, i);
            temp.open(output_buffer);
            final_raypaths << temp.rdbuf();
            temp.close();
            remove(output_buffer);
        }

        // Repeat for each caustics bounce file
        if (WriteCaustics){
            for (int j = 0; j < bounces; j++){
                sprintf(output_buffer, "%s_caustics-path%i_%i.dat", file_title, j, i);
                temp.open(output_buffer);
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

/* This code has been commented out to avoid compiling errors
 * To enable this code, all changes made for the above code
 * need to be applied to this code
 */

/*void GeoAcGlobal_RunInteractive(char* inputs[], int count){
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
    
    ofstream raypaths.
    ofstream caustics;
    
    double** solution;
    GeoAc_BuildSolutionArray(solution,length);
    
    keepgoing='y';
    while(keepgoing=='y' || keepgoing=='Y'){
        raypaths.open("raypath.dat");
        
        raypaths.<< "# z [km]";
        raypaths.<< '\t' << "lat [deg]";
        raypaths.<< '\t' << "lon [deg]";
        raypaths.<< '\t' << "Geo. Atten. [dB]";
        raypaths.<< '\t' << "Atmo. Atten. [dB]";
        raypaths.<< '\t' << "Travel Time [s]";
        raypaths.<< '\n';
        
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
        GeoAc_theta = theta*Pi/180.0;
        GeoAc_phi = Pi/2.0 - phi*Pi/180.0;
        
        GeoAc_SetInitialConditions(solution, z_src, lat_src*Pi/180.0, lon_src*Pi/180.0);
        travel_time_sum = 0.0;
        attenuation = 0.0;
        r_max = 0.0;
		
        for(int bnc = 0; bnc <= bnc_cnt; bnc++){
            k = GeoAc_Propagate_RK4(solution, BreakCheck);
            if(WriteCaustics){ D_prev = GeoAc_Jacobian(solution,1);}
            
            for(int m = 1; m < k ; m++){     // write profiles to data files and vector arrays
                GeoAc_TravelTimeSegment(travel_time_sum, solution, m-1,m);
                GeoAc_SB_AttenSegment(attenuation, solution, m-1, m, freq);
                r_max = max(r_max, solution[m][0] - r_earth);
                if(WriteCaustics){ D = GeoAc_Jacobian(solution,m);}
                
                if(m % 25 == 0){
                    raypaths.<< solution[m][0] - r_earth;
                    raypaths.<< '\t' << setprecision(8) << solution[m][1] * 180.0/Pi;
                    raypaths.<< '\t' << setprecision(8) << solution[m][2] * 180.0/Pi;
                    if(CalcAmp){    raypaths.<< '\t' << 20.0*log10(GeoAc_Amplitude(solution,m));}
                    else{           raypaths.<< '\t' << 0.0;}
                    raypaths.<< '\t' << -attenuation;
                    raypaths.<< '\t' << travel_time_sum;
                    raypaths.<< '\n';
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
            GeoAc_SetReflectionConditions(solution,k);
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
            if(CalcAmp) cout << '\t' << '\t' << "Geometric attenuation = " << 20.0*log10(GeoAc_Amplitude(solution,k)) << " dB." << '\n';
            cout << '\t' << '\t' << "Atmospheric attenuation = " << -attenuation << " dB." << '\n';
            cout << '\t' << '\t' << "Arrival celerity = " << range/travel_time_sum << "km/sec." << '\n';
            cout << '\t' << '\t' << "Back azimuth of the arrival = " << back_az  << " degrees from N. " << '\n' << '\n';
        } else {
            cout << '\t' << '\t' << "Ray path does not return to the ground." << '\n' << '\n';
        }
        raypaths.close();
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
    
    for(int n_bnc = bnc_min; n_bnc <= bnc_max; n_bnc++){
        cout << "Searching for " << n_bnc << " bounce eigenrays." << '\n';
        
        theta_start = theta_min;
        while(theta_start < theta_max){
            estimate_success = GeoAc_EstimateEigenray(Source_Loc, Receiver_Loc, theta_start, theta_max, theta_est, phi_est, theta_next, n_bnc, azimuth_err_lim);
            if(estimate_success)  GeoAc_3DEigenray_LM(Source_Loc, Receiver_Loc, theta_est, phi_est, freq, n_bnc, iterations, file_title);
            
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

    GeoAc_3DEigenray_LM(Source_Loc, Receiver_Loc, theta_est, phi_est, freq, bounces, iterations, file_title);
}
*/


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
        cout << "Unrecognized option." << '\n';
    }
    
    
    
    return 0;
}
