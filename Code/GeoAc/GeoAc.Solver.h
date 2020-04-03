#ifndef GEOAC_SOLVER_H_
#define GEOAC_SOLVER_H_

#include <math.h>

#include "GeoAc.EquationSets.h"
#include "../Atmo/G2S_GlobalSpline1D.h"

using namespace std;

int GeoAc_Propagate_RK4(double ** &, bool &, GeoAc_Sources_Struct&, SplineStruct&);


#endif /* GEOAC_SOLVER_H_ */
