#ifndef GEOAC_SOLVER_H_
#define GEOAC_SOLVER_H_

#include <math.h>

#include "GeoAc.EquationSets.h"

using namespace std;

int GeoAc_Propagate_RK4(double ** &, bool &, GeoAc_Sources_Struct&);


#endif /* GEOAC_SOLVER_H_ */
