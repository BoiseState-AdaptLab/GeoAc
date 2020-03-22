#ifndef _GEOAC_INTERFACE_CPP_
#define _GEOAC_INTERFACE_CPP_

#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>

#include "GeoAc.Parameters.h"
#include "../Atmo/Atmo_State.h"
#include "../Atmo/G2S_GlobalSpline1D.h"
#include "GeoAc.EquationSets.h"
#include "GeoAc.Solver.h"

using namespace std;

//--------------------------------------//
//----Functions To Set Up The Solver----//
//--------------------------------------//
void GeoAc_SetEqCnt(){
	switch(GeoAc_dim){
		case(2):
			if(GeoAc_CalcAmp && GeoAc_AtmoStrat){               GeoAc_EqCnt = 6;}	// 2D propagation solving for rays and amplitude in stratified atmosphere
            else if(!(GeoAc_CalcAmp) && GeoAc_AtmoStrat){       GeoAc_EqCnt = 3;}	// 2D propagation solving for rays only in stratified atmosphere
            else if(GeoAc_CalcAmp && !(GeoAc_AtmoStrat)){       GeoAc_EqCnt = 8;}   // 2D propagation solving for rays and amplitude in horizontally varying atmosphere
            else if(!(GeoAc_CalcAmp) && !(GeoAc_AtmoStrat)){    GeoAc_EqCnt = 4;} 	// 2D propagation solving for rays only in horizontally varying atmosphere
			break;
            
		case(3):
			if(GeoAc_CalcAmp && GeoAc_AtmoStrat){               GeoAc_EqCnt = 12;}	// 3D propagation solving for rays and amplitude in stratified atmosphere
            else if(!(GeoAc_CalcAmp) && GeoAc_AtmoStrat){		GeoAc_EqCnt = 4;}   // 3D propagation solving for rays only in stratified atmosphere
            else if(GeoAc_CalcAmp && !(GeoAc_AtmoStrat)){		GeoAc_EqCnt = 18;}  // 3D propagation solving for rays and amplitude in horizontally varying atmosphere
			else if(!(GeoAc_CalcAmp) && !(GeoAc_AtmoStrat)){    GeoAc_EqCnt = 6;}   // 3D propagation solving for rays only in horizontally varying atmosphere
			break;
            
		default:
            cout << "***WARNING*** GeoAc Not Properly Configured" << '\n';
			break;
	}
}

void GeoAc_ConfigureCalcAmp(bool calc_amp){
	GeoAc_CalcAmp = calc_amp;
    GeoAc_SetSystem();
	GeoAc_SetEqCnt();
}


//----------------------------------------------------------------//
//----Functions To Build, Clear, and Delete the Solution Array----//
//----------------------------------------------------------------//
void GeoAc_BuildSolutionArray(double ** & solution, int length){
	solution = new double* [length];
	for(int n = 0; n < length; n++){
		solution[n] = new double [GeoAc_EqCnt];
	}
}

void GeoAc_ClearSolutionArray(double ** & solution, int index){
	for(int n1 = 0; n1 < index; n1++){
		for(int n2 = 0; n2 < GeoAc_EqCnt; n2++){
			solution[n1][n2] = 0.0;
		}
	}
}

void GeoAc_DeleteSolutionArray(double ** & solution, int length){
	for(int n = 0; n < length; n++){
		delete [] solution[n];
	}
	delete [] solution;
}

//-------------------------------------------------//
//---------Functions To Output The Profile---------//
//-------------------------------------------------//
void GeoAc_WriteProfile(string file_name, double azimuth, SplineStruct &splines){
	ofstream file_out;	file_out.open(file_name.c_str() );
    
	if(!file_out.is_open()){
		cout << "Error opening file, check file name." << '\n';
	} else {
            // Convert azimuth to radians
            double azi_rad = azimuth*Pi/180.0;
            for(int m = 0; m < 1400; m++){
                double r0 = r_earth + m/10.0;
                // Get results from c(), u(), v(), and rho() to write to files
                double c_ = c(r0, Pi/4.0, 0, splines.Temp_Spline);
                double u_ = u(r0, Pi/4.0, 0, splines.Windu_Spline);
                double v_ = v(r0, Pi/4.0, 0, splines.Windv_Spline);
                double rho_ = rho(r0, Pi/4.0, 0, splines.Density_Spline);
                file_out << r0 << '\t';
                file_out << pow(c_*1000.0,2)/(R*gam) << '\t';
                file_out << u_*1000.0 << '\t';
                file_out << v_*1000.0 << '\t';
                file_out << rho_ << '\t';
                file_out << rho_ * pow(c_ * 1000.0, 2) / gam * 10.0 << '\t';
                file_out << c_ << '\t';
                file_out << c_ + cos(azi_rad)*u_ + sin(azi_rad)*v_ << '\n';
        }
        file_out.close();
    }
}

void GeoAc_WriteProfile(string file_name, double lat_src, double lon_src, double azimuth, SplineStruct &splines){
	ofstream file_out;	file_out.open(file_name.c_str() );
    
	if(!file_out.is_open()){
		cout << "Error opening file, check file name." << '\n';
	} else {
            // Convert azimuth to radians
            double azi_rad = azimuth*Pi/180.0;
            for(int m = 0; m < 1400; m++){
                double r0 = r_earth + m/10.0;
                // Get results from c(), u(), v(), and rho() to write to files
                double c_ = c(r0, lat_src, lon_src, splines.Temp_Spline);
                double u_ = u(r0, lat_src, lon_src, splines.Windu_Spline);
                double v_ = v(r0, lat_src, lon_src, splines.Windv_Spline);
                double rho_ = rho(r0, lat_src, lon_src, splines.Density_Spline);
                file_out << r0 << '\t';
                file_out << pow(c_*1000.0,2)/(R*gam) << '\t';
                file_out << u_*1000.0 << '\t';
                file_out << v_*1000.0 << '\t';
                file_out << rho_ << '\t';
                file_out << rho_ * pow(c_ * 1000.0, 2) / gam * 10.0 << '\t';
                file_out << c_ << '\t';
                file_out << c_ + cos(azi_rad)*u_ + sin(azi_rad)*v_ << '\n';
        }
        file_out.close();
    }
}

//-------------------------------------------------//
//---------Functions To Output The Profile---------//
//-------------------------------------------------//
bool string2bool (std::string v){
    return !v.empty () &&
    (strcasecmp (v.c_str (), "true") == 0 || atoi (v.c_str ()) != 0);
}


#endif /* _GEOAC_INTERFACE_CPP_ */
