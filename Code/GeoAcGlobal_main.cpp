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

#include <netcdf>
using namespace netCDF;
using namespace netCDF::exceptions;

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
    
    cout << '\t' << "Additional Parameters"  << '\t' << "Units/Options" << '\t' << "Default Value" << '\n';
    cout << '\t' << "---------------------------------------------" << '\n';
    cout << '\t' << "freq"              << '\t' << '\t' << '\t' << "Hz"         << '\t' << '\t' << "0.1" << '\n';
    cout << '\t' << "abs_coeff"         << '\t' << '\t' << "scalar"             << '\t' << '\t' << "0.3" << '\n';
    cout << '\t' << "z_grnd"            << '\t' << '\t' << '\t' << "km"         << '\t' << '\t' << "0.0" << '\n';
    cout << '\t' << "profile_format"    << '\t' << '\t' << "See Manual"         << '\t' << "zTuvdp" << '\n';
    cout << '\t' << "CalcAmp"          << '\t' << '\t' << "True/False"         << '\t' << "True" << '\n';
    cout << '\t' << "alt_max"           << '\t' << '\t' << '\t' << "km"         << '\t' << '\t' << "Interpolation Max" << '\n';
    cout << '\t' << "rng_max"           << '\t' << '\t' << '\t' << "km"         << '\t' << '\t' << "10,000" << '\n' << '\n';
    
    cout << "Examples:" << '\n';
    cout << '\t' << "./GeoAcGlobal -prop ToyAtmo.met bounces=5 azimuth=-90.0 rng_max=1500.0" << '\n';
    cout << '\t' << "./GeoAcGlobal -prop ToyAtmo.met lat_src=41.131 lon_src=-112.896 bounces=0 phi_min=-120.0 phi_max=-60.0 phi_step=2.0 WriteRays=False" << '\n';
    
}



// Combine all dat files and write to netCDF
void GeoAcGlobal_NetCdf(int* maxPoints, int* phi_bounds, int* theta_bounds, 
                        int* bounces, char* file_title, int* num_threads, 
                        bool WriteRays, bool WriteCaustics){


    // Create master files to combine each thread's files into
    ofstream final_results, final_raypaths;
    char output_buffer[60]; // File name

    // Write header information for each file type
    sprintf(output_buffer, "%s_results_%ithreads.dat", file_title, *num_threads);
    final_results.open(output_buffer);
    final_results << "# theta [deg]";
    final_results << '\t' << "wasp_takeoff_angle [deg]"; //phi
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
        sprintf(output_buffer, "%s_raypaths_%ithreads.dat", file_title, *num_threads);
        final_raypaths.open(output_buffer);
        final_raypaths << "# wasp_altitude [km]"; //z
        final_raypaths << '\t' << "wasp_colatitude [deg]"; //lat
        final_raypaths << '\t' << "wasp_longitude [deg]"; //lon
        final_raypaths << '\t' << "wasp_kr [deg]";
        final_raypaths << '\t' << "wasp_kt [deg]";
        final_raypaths << '\t' << "wasp_kf [deg]";
        final_raypaths << '\t' << "wasp_amplitude [dB]"; //Geo. Atten.
        final_raypaths << '\t' << "wasp_Veff [dB]"; //Atmo. Atten
        final_raypaths << '\t' << "wasp_arrival_time [s]"; //Travel time
        final_raypaths << '\n';
    }


    // These doubles contain a ray's metadata
    double thetaVar;
    double wasp_takeoff_angleVar;  // phi
    int n_bVar;
    double lat_0Var;
    double lon_0Var;
    double travelTimeVar;
    double celerityVar;
    double turningHeightVar;
    double inclinationVar;
    double backAzimuthVar;
    double geoAttenVar;
    double atmoAttenVar;

    // These double arrays contain information about 
    // each point along a ray
    double wasp_altitudeArr[*maxPoints];
    double wasp_colatitudeArr[*maxPoints];
    double wasp_longitudeArr[*maxPoints];
    double wasp_krArr[*maxPoints];
    double wasp_ktArr[*maxPoints];
    double wasp_kfArr[*maxPoints];
    double wasp_amplitudeArr[*maxPoints];
    double wasp_VeffArr[*maxPoints];
    double wasp_arrival_timeArr[*maxPoints];
    
    string line;            // Keep track of each line in the stringstream
    int rayNumber = 0;      // Keep track of the ray for results
    int pointRayNumber = 0; // Keep track of the ray for raypaths
    int pointCount = 0;     // Keep track of each point

    //Begin netCDF writing
    static const int NRAYS = (*phi_bounds+1) * (*theta_bounds+1);
    static const int NC_ERR = 2;

    try{
        // Create the file. The Replace parameter tells netCDF to overwrite
        // this file, if it already exists.
        NcFile dataFile("GeoAcResultsAndRaypaths.nc", NcFile::replace);

        // Create netCDF dimensions
        NcDim nRaysDim = dataFile.addDim("nRays", NRAYS); //Number of unique rays
        NcDim maxPointsDim = dataFile.addDim("maxPointsAlongRay", 600);  // We are interested in 600 points only!
        // cout << "length  = " << length;

        // Variables for each ray(unique phi and theta)
        vector<NcDim> dims1;
        dims1.push_back(nRaysDim);

        NcVar thetaNcVar = dataFile.addVar("theta", ncDouble, dims1);
        NcVar wasp_takeoff_angleNcVar = dataFile.addVar("wasp_takeoff_angle", ncDouble, dims1); //phi
        NcVar n_bNcVar = dataFile.addVar("n_b", ncInt, dims1);
        NcVar lat_0NcVar = dataFile.addVar("lat_0_deg", ncDouble, dims1);
        NcVar lon_0NcVar = dataFile.addVar("lon_0_deg", ncDouble, dims1);
        NcVar travelTimeNcVar = dataFile.addVar("TravelTime_s", ncDouble, dims1);
        NcVar celerityNcVar = dataFile.addVar("Celerity_kmps", ncDouble, dims1);
        NcVar turningHeightNcVar = dataFile.addVar("TurningHeight_km", ncDouble, dims1);
        NcVar inclinationNcVar = dataFile.addVar("Inclination_deg", ncDouble, dims1);
        NcVar backAzimuthNcVar = dataFile.addVar("BackAzimuth_deg", ncDouble, dims1);
        NcVar geoAttenNcVar = dataFile.addVar("GeoAtten_dB", ncDouble, dims1);
        NcVar atmoAttenNcVar = dataFile.addVar("AtmoAtten_dB", ncDouble, dims1);

        //Variables for every point along a ray
        vector<NcDim> dims2;
        dims2.push_back(nRaysDim);
        dims2.push_back(maxPointsDim);
        
        NcVar wasp_altitudeVar = dataFile.addVar("wasp_altitude_km", ncDouble, dims2);   //z
        NcVar wasp_colatitudeVar = dataFile.addVar("wasp_colatitude_deg", ncDouble, dims2);
        NcVar wasp_longitudeVar = dataFile.addVar("wasp_longitude_deg", ncDouble, dims2);
        NcVar wasp_krVar = dataFile.addVar("wasp_kr_deg", ncDouble, dims2);
        NcVar wasp_ktVar = dataFile.addVar("wasp_kt_deg", ncDouble, dims2);
        NcVar wasp_kfVar = dataFile.addVar("wasp_kf_deg", ncDouble, dims2);
        NcVar wasp_amplitudeVar = dataFile.addVar("wasp_amplitude_dB", ncDouble, dims2);
        NcVar wasp_VeffVar = dataFile.addVar("wasp_Veff_dB", ncDouble, dims2);
        NcVar wasp_arrival_timeVar = dataFile.addVar("wasp_arrival_time_s", ncDouble, dims2); 

        vector<size_t> rayStartIdx;
        vector<size_t> rayCountIdx;

        vector<size_t> pointStartIdx;
        vector<size_t> pointCountIdx;

        // Combine all files
        for (int i = 0; i < *num_threads; i++){
            // Get the file name
            sprintf(output_buffer, "%s_results_%i.dat", file_title, i);
            
            //cout << "top pointCount: " << pointCount << endl;
            
            // Open the file in read mode
            ifstream temp(output_buffer);
            if(!temp.is_open()) {
                perror("Error opening the file \n");
                exit(EXIT_FAILURE);
            }
        
            while(!temp.eof()){
                getline(temp, line);
                if(!line.empty()){
                    // cout << "ray number: " << rayNumber << endl;
                    // cout << "line: " << line << endl;
                    stringstream rst(line);
                    rst.precision(8);

                    double temp_f;
                    int temp_b;

                    rst >> temp_f;
                    thetaVar=temp_f;
                    
                    rst >> temp_f;
                    wasp_takeoff_angleVar=temp_f;
                    
                    rst >> temp_b;
                    n_bVar=temp_b;
                    
                    rst >> temp_f;
                    lat_0Var=temp_f;
                    
                    rst >> temp_f;
                    lon_0Var=temp_f;
                    
                    rst >> temp_f;
                    travelTimeVar=temp_f;
                    
                    rst >> temp_f;
                    celerityVar=temp_f;
                    
                    rst >> temp_f;
                    turningHeightVar=temp_f;
                    
                    rst >> temp_f;
                    inclinationVar=temp_f;
                    
                    rst >> temp_f;
                    backAzimuthVar=temp_f;
                    
                    rst >> temp_f;
                    geoAttenVar=temp_f;
                    
                    rst >> temp_f;
                    atmoAttenVar=temp_f;
                    
                    //Stream to netCDF
                    rayStartIdx.push_back(rayNumber);
                    rayCountIdx.push_back(1);
            
                    thetaNcVar.putVar(rayStartIdx, rayCountIdx, &thetaVar);    
                    wasp_takeoff_angleNcVar.putVar(rayStartIdx, rayCountIdx, &wasp_takeoff_angleVar);
                    n_bNcVar.putVar(rayStartIdx, rayCountIdx, &n_bVar);
                    lat_0NcVar.putVar(rayStartIdx, rayCountIdx, &lat_0Var);
                    lon_0NcVar.putVar(rayStartIdx, rayCountIdx, &lon_0Var);
                    travelTimeNcVar.putVar(rayStartIdx, rayCountIdx, &travelTimeVar);
                    celerityNcVar.putVar(rayStartIdx, rayCountIdx, &celerityVar);
                    turningHeightNcVar.putVar(rayStartIdx, rayCountIdx, &turningHeightVar);
                    inclinationNcVar.putVar(rayStartIdx, rayCountIdx, &inclinationVar);
                    backAzimuthNcVar.putVar(rayStartIdx, rayCountIdx, &backAzimuthVar);
                    geoAttenNcVar.putVar(rayStartIdx, rayCountIdx, &geoAttenVar);
                    atmoAttenNcVar.putVar(rayStartIdx, rayCountIdx, &atmoAttenVar);

                    rayNumber++;
                    rayStartIdx.clear();
                    rayCountIdx.clear();
                }
            }

            // Clear the eof bit and rewind
            temp.clear();
            temp.seekg(0);
            // Append to the final results file
            final_results << temp.rdbuf();
            // Close the file
            temp.close();
            // Delete the file
            remove(output_buffer);
            
            cout << "pointCount after results: " << pointCount << " rayNumber: " << rayNumber <<endl;

            // Repeat for raypaths
            if (WriteRays){
                sprintf(output_buffer, "%s_raypaths_%i.dat", file_title, i);
                ifstream temp(output_buffer);
                if(!temp.is_open()) {
                    perror("Error opening the file \n");
                    exit(EXIT_FAILURE);
                }

                line.clear();
                bool moreData = false; //Is there data to be written?
                        
                pointStartIdx.clear();
                pointCountIdx.clear();
                pointCount = 0;
                
                getline(temp, line);
                while(!temp.eof()){
                    //The line subsequent to an empty line signals the start of the next ray
                    if(line.empty() && moreData){
                        //Stream to netCDF
                        pointStartIdx.push_back(pointRayNumber);
                        pointStartIdx.push_back(0);
                        pointCountIdx.push_back(1);
                        // We need only 600 points at this time.
                        // If the ray has <600 points, use the min
                        // number of points found
                        pointCountIdx.push_back(min(600, pointCount)); 

                        // Write the data to the file
                        wasp_altitudeVar.putVar(pointStartIdx, pointCountIdx, wasp_altitudeArr);
                        wasp_colatitudeVar.putVar(pointStartIdx, pointCountIdx, wasp_colatitudeArr);
                        wasp_longitudeVar.putVar(pointStartIdx, pointCountIdx, wasp_longitudeArr);
                        wasp_krVar.putVar(pointStartIdx, pointCountIdx, wasp_krArr);
                        wasp_ktVar.putVar(pointStartIdx, pointCountIdx, wasp_ktArr);
                        wasp_kfVar.putVar(pointStartIdx, pointCountIdx, wasp_kfArr);
                        wasp_amplitudeVar.putVar(pointStartIdx, pointCountIdx, wasp_amplitudeArr);
                        wasp_VeffVar.putVar(pointStartIdx, pointCountIdx, wasp_VeffArr);
                        wasp_arrival_timeVar.putVar(pointStartIdx, pointCountIdx, wasp_arrival_timeArr);

                        // The file will be automatically close when the NcFile object goes
                        // out of scope. This frees up any internal netCDF resources
                        // associated with the file, and flushes any buffers.
                        
                        pointStartIdx.clear();
                        pointCountIdx.clear();
                        
                        pointCount = 0; 
                        pointRayNumber++;
                        moreData = false;
                    }
                    else{
                        stringstream rpst(line);
                        //cout << "line: " << line << endl;
                        rpst.precision(8);
                        double f;
                        
                        rpst >> f;
                        wasp_altitudeArr[pointCount] = f;
                        
                        rpst >> f;
                        wasp_colatitudeArr[pointCount] = f;
                        
                        rpst >> f;
                        wasp_longitudeArr[pointCount] = f;

                        rpst >> f;
                        wasp_krArr[pointCount] = f;

                        rpst >> f;
                        wasp_ktArr[pointCount] = f;

                        rpst >> f;
                        wasp_kfArr[pointCount] = f;
                        
                        rpst >> f;
                        wasp_amplitudeArr[pointCount] = f;
                        
                        rpst >> f;
                        wasp_VeffArr[pointCount] = f;
                        
                        rpst >> f;
                        wasp_arrival_timeArr[pointCount] = f;
                        
                        moreData = true;
                        pointCount++;
                    }
                    getline(temp, line);
                }
            
                // Clear the eof bit and rewind
                temp.clear();
                temp.seekg(0);
                // Append to the final raypaths file
                final_raypaths << temp.rdbuf();
                temp.close();
                remove(output_buffer);
            }

        }
    }
    catch(NcException& e)
      {e.what();
        cout << "e.what(): " << e.what() <<endl;
        cout << "NC_ERR: " << NC_ERR <<endl;
    }

    // Close all files
    final_results.close();
    final_raypaths.close();
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
    }

    //cout << omp_get_max_threads() << endl;

    // Convert longitude and latitude to radians
    lat_src *= TO_RAD;
    lon_src *= TO_RAD;
    
  
    // Create an array of structs, one for each thread
    // Each thread needs its own struct to modify and read from
    SplineStruct spline_structs[num_threads];
    for (int i = 0; i < num_threads; i++){
        // Load profile into spline
        spline_structs[i] = splines;
    }

    int rayCount; //Keep track of the ray
    int maxPoints; //Keep track of the max number of points

    //calculate loop bounds for outer phi loop
    int phi_bounds = int((phi_max - phi_min) / phi_step);

    //calculate loop bounds for inner theta loop
    int theta_bounds = ceil((theta_max - theta_min) / theta_step);
 
    // Start parallel, set out variables that can be shared - constants, 
    // information variables, angle variables, output_variables
    #pragma omp parallel default(shared) reduction(+:rayCount) reduction(max:maxPoints)
    {
        rayCount = 0;
        maxPoints = 0;

        int tid = omp_get_thread_num();
        double* solution = new double[GeoAc_EqCnt];

        // Get this thread's struct from the array
        SplineStruct spl = spline_structs[tid];


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

        double theta = theta_min;

        #pragma omp for 
        for(int i = 0; i  <= phi_bounds; i++){
          
          double phi = phi_min + phi_step*i;
          cout << "In phi loop: phi= " << phi << " phi_step=" << phi_step << endl;
          theta = theta_min;
          
          for(int j = 0; j <= theta_bounds; j++){
              
              int k;
            
              cout << "Plotting ray path w/ theta = " << theta << ", phi = " << phi << '\n';
              double GeoAc_theta = theta*TO_RAD;
              double GeoAc_phi = Pi/2.0 - (phi*TO_RAD);
            
              double** temp = &solution;
              GeoAc_SetInitialConditions(temp, z_src, lat_src, lon_src, GeoAc_theta, GeoAc_phi, sources, spl);

              double travel_time_sum = 0.0;
              double attenuation = 0.0;
              double r_max = 0.0;
              
              for(int bnc_cnt = 0; bnc_cnt <= bounces; bnc_cnt++){
                  double* final_vals = GeoAc_Propagate_RK4_2(solution, r_max, travel_time_sum, attenuation,
                                                    GeoAc_theta, GeoAc_phi, freq, CalcAmp, sources, 
                                                    spl, WriteRays ? &(raypaths[tid]) : nullptr,
                                                    WriteCaustics ? &(caustics[tid][bnc_cnt]) : nullptr,
                                                    rayCount, &maxPoints);

                  if (final_vals == nullptr) {
                    break;
                  }

                  double GC_Dist1 = pow(sin((final_vals[1] - lat_src)/2.0),2);
                  double GC_Dist2 = cos(lat_src) * cos(final_vals[1]) * pow(sin((final_vals[2] - lon_src)/2.0),2);
                
                  double inclination = - asin(c(final_vals[0], final_vals[1], final_vals[2], spl.Temp_Spline) / c(r_earth + z_src, lat_src, lon_src, spl.Temp_Spline) * final_vals[3]) * TO_DEG;
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
                  if(CalcAmp){    results[tid] << '\t' << 20.0*log10(GeoAc_Amplitude(&final_vals,0,GeoAc_theta,GeoAc_phi,sources, spl));}
                  else{           results[tid] << '\t' << 0.0;}
                  results[tid] << '\t' << -attenuation;
                  results[tid] << '\n';                
              }
              if(WriteRays){raypaths[tid] << '\n';}
              theta += theta_step;
              //cout << "New theta= " << theta << endl;
              rayCount++;
          }
          results[tid] << '\n';
        }

        // Close files for this specific thread
        raypaths[tid].close();
        results[tid].close();
        
        // Close the caustics files for each bounce
        for (int i = 0; i < bounces; i++){
          caustics[tid][i].close();
        }

    }// End omp parallelization

    cout << "Parallel section complete. \nTotal number of rays: " << rayCount << ". \nMax points propogated along an a ray: " << maxPoints <<endl;

    GeoAcGlobal_NetCdf(&maxPoints, &phi_bounds, &theta_bounds, &bounces, file_title, &num_threads, WriteRays, WriteCaustics);

}



int main(int argc, char* argv[]){
    int skip = 3;
    
    if(argc < 3){
        GeoAcGlobal_Usage();
        return 0;
    }
    
    if (strncmp(argv[1], "-prop",5) == 0){
        GeoAcGlobal_RunProp(argv, argc);
    
    } else if (strncmp(argv[1], "-interactive",12) == 0){
        cout << "Not supported. " << endl;
        
    } else if (strncmp(argv[1], "-eig_search",11) == 0){
        cout << "Not supported. " << endl;
        
    } else if (strncmp(argv[1], "-eig_direct",11) == 0){
        cout << "Not supported. " << endl;
        
    } else {
        cout << "Unrecognized option: " << argv[1] << '\n';
    }
    
    
    
    return 0;
}




