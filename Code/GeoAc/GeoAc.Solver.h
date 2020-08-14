#ifndef GEOAC_SOLVER_H_
#define GEOAC_SOLVER_H_

#include <math.h>

using namespace std;

// Modified to take in GeoAc_Sources_Struct by reference
int GeoAc_Propagate_RK4(double ** &, bool &, GeoAc_Sources_Struct&);


#endif /* GEOAC_SOLVER_H_ */
