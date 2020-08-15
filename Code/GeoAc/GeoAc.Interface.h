#ifndef _GEOAC_INTERFACE_H_
#define _GEOAC_INTERFACE_H_

#include <math.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

// Add this include to acces Splines_Struct
#include "../Atmo/G2S_GlobalSpline1D.h"

using namespace std;

//--------------------------------------//
//----Functions To Set Up The Solver----//
//--------------------------------------//
void GeoAc_SetEqCnt();
void GeoAc_ConfigureCalcAmp(bool);

//----------------------------------------------------------------//
//----Functions To Build, Clear, and Delete the Solution Array----//
//----------------------------------------------------------------//
void GeoAc_BuildSolutionArray(double ** &, int);
void GeoAc_ClearSolutionArray(double ** &, int);
void GeoAc_DeleteSolutionArray(double ** &, int);

//-------------------------------------------------//
//---------Functions To Output The Profile---------//
//-------------------------------------------------//
// Modified to take in Splines_Struct by reference
void GeoAc_WriteProfile(string, double, Splines_Struct&);
void GeoAc_WriteProfile(string, double, double, double, Splines_Struct&);

//------------------------------------------------------//
//---------Functions To Use Command Line Inputs---------//
//------------------------------------------------------//
bool string2bool (std::string v);

#endif /* _GEOAC_INTERFACE_H_ */
