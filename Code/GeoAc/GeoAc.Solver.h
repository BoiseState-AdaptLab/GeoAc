#ifndef GEOAC_SOLVER_H_
#define GEOAC_SOLVER_H_

#include <math.h>

#include "GeoAc.EquationSets.h"
#include "../Atmo/G2S_GlobalSpline1D.h"

using namespace std;

int GeoAc_Propagate_RK4(double ** &, bool &, GeoAc_Sources_Struct&, SplineStruct&);

/**
 * Modified version of the GeoAc_Propagate_RK4() function
 *
 * @param double*&              The initial conditions
 * @param double&               r_max
 * @param double&               travel_time
 * @param double&               attenuation
 * @param double                GeoAc_theta
 * @param double                GeoAc_phi
 * @param double                freq
 * @param bool                  CalcAmp
 * @param GeoAc_Sources_Struct& GeoAc_Sources struct
 * @param SplineStruct&         SplineStruct struct
 * @param ofstream*             results ofstream
 * @param ofstream*             caustics ofstream
 * @param int                   rayCount
 * @param int                   maxPoints
 *
 * @return double* The last row of the solution that was filled
 *
 */
double* GeoAc_Propagate_RK4_2(double*&, double&, double&, double&, 
        double, double, double, bool, 
        GeoAc_Sources_Struct&, SplineStruct&, 
        ofstream*, ofstream*, int, int*);


#endif /* GEOAC_SOLVER_H_ */
