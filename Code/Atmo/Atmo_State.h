# ifndef ATMO_STATE_H_
# define ATMO_STATE_H_

using namespace std;

#include <string>
#include "G2S_GlobalSpline1D.h"

//-----------------------------------------------------------//
//---------Functions Defining the Propagation Medium---------//
//-----------------------------------------------------------//
void GeoAc_SetPropRegion(NaturalCubicSpline_1D&);        // Function to set the propagation region limits

extern double r_earth;                                  // Earth radius for global propagation
extern double z_grnd;                                   // Difference between ground level and sea level (z = 0 in G2S file)
extern double tweak_abs;                                // Coefficient to scale Sutherland Bass attenuation

double rho(double, double, double, NaturalCubicSpline_1D&);// Atmospheric density

double c(double, double, double, NaturalCubicSpline_1D&);// Thermodynamic sound speed and derivatives
double c_diff(double, double, double, int, NaturalCubicSpline_1D&);
double c_ddiff(double, double, double, int, int, NaturalCubicSpline_1D&);

double u(double, double, double, NaturalCubicSpline_1D&);// \hat{x} component of the winds and derivatives
double u_diff(double, double, double, int, NaturalCubicSpline_1D&);
double u_ddiff(double, double, double, int, int, NaturalCubicSpline_1D&);

double v(double, double, double, NaturalCubicSpline_1D&);// \hat{y} component of the winds and derivatives
double v_diff(double, double, double, int, NaturalCubicSpline_1D&);
double v_ddiff(double, double, double, int, int, NaturalCubicSpline_1D&);

double w(double, double, double);                       // \hat{Z} component of the winds and derivatives
double w_diff(double, double, double, int);
double w_ddiff(double, double, double, int, int);

double SuthBass_Alpha(double, double, double, double, SplineStruct&);  // Attenuation model from Sutherland Bass
double Atten_Other(double, double, double, double);     // Any other attenuation model

#endif  /*ATMO_STATE_H_*/
