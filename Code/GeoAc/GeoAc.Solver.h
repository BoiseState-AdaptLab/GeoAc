#ifndef GEOAC_SOLVER_H_
#define GEOAC_SOLVER_H_

#include <math.h>

// Add this include to access Splines_Struct
#include "../Atmo/G2S_GlobalSpline1D.h"

using namespace std;

// Modified to pass GeoAc_Sources_Struct and Splines_Struct by reference
int GeoAc_Propagate_RK4(double ** &, bool &, GeoAc_Sources_Struct&, Splines_Struct&);


#endif /* GEOAC_SOLVER_H_ */
