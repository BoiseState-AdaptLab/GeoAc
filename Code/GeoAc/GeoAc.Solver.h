#ifndef GEOAC_SOLVER_H_
#define GEOAC_SOLVER_H_

#include <math.h>

#include "GeoAc.EquationSets.h"
#include "../Atmo/G2S_GlobalSpline1D.h"

using namespace std;

int GeoAc_Propagate_RK4(double ** &, bool &, GeoAc_Sources_Struct&, SplineStruct&);
// Parameters: double **& - solution array
//             double& X3 - r_max, travel_time, attenuation
//             double X3 - GeoAc_theta, GeoAc_phi, freq
//             bool - CalcAmp
//             struct X2 - sources & splines structs
//             ofstream* X2 - pointers to the results and caustics ofstreams. These can be null pointers
// Returns: index of the last row in solution that we filled
int GeoAc_Propagate_RK4_2(double ** &, double&, double&, double&, double, double, double, bool,
                          GeoAc_Sources_Struct&, SplineStruct&, ofstream*, ofstream*);


#endif /* GEOAC_SOLVER_H_ */
