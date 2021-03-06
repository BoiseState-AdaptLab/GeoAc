#ifndef GEOAC_EIGENRAY_H_
#define GEOAC_EIGENRAY_H_

#include <math.h>
#include <iostream>
#include <fstream>

#include "GeoAc.EquationSets.h"
#include "../Atmo/G2S_GlobalSpline1D.h"

using namespace std;

extern bool verbose_output;
extern int eigenray_count;
extern double d_theta_big;
extern double d_theta_small;
extern ofstream results;

double Calc_Bearing(double, double, double, double);        // Function to calculate bearing between two lat/long locations
double Calc_GC_Distance(double, double, double, double);    // Function to calculate great circle distance between two lat/long locations

double Modify_d_theta(double, double);                      // Function to modify d_theta in GeoAc_EstimateEigenray function

// Function to identify inclination at fixed azimuth for specified arrival range
bool GeoAc_EstimateEigenray(double [3], double [2], double, double, double &, double &, double &, int, double, GeoAc_Sources_Struct&, SplineStruct&);
void GeoAc_3DEigenray_LM(double [3], double [2], double &, double &, double, int, int, char [], GeoAc_Sources_Struct&, SplineStruct&); // Function to identify exact eigenray

#endif /* GEOAC_EIGENRAY_H_ */
