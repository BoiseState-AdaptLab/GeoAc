#ifndef GEOAC_SOLVER_H_
#define GEOAC_SOLVER_H_

#include <math.h>

// Add this include to access Splines_Struct
#include "../Atmo/G2S_GlobalSpline1D.h"

using namespace std;

/* Generic version of GeoAc_Propogate_RK4 that doesn't perform any extra
 * calculations. It produces that final row of data and the new initial conditions
 *
 * @return bool check - True if we are done with this ray entirely
 *                    - False if we are just done with this segment
 *
 * @param initial_conds - the initial conditions. new initial conditions
 *                      - are calculated at the end at written to this variable
 * @param final_row - final row of values
 * @param sources, splines - structs containing information about the ray
 */
bool GeoAc_Propogate_RK4(double* &, double* &, GeoAc_Sources_Struct&,
                        Splines_Struct&);


/* Performs most of our calculations and file I/O for GeoAcGlobal_main
 *
 * @return bool check - True if we are done with this ray entirely
 *                    - False if we are just done with this segment
 *
 * @param initial_conds - the initial conditions. new initial conditions
 *                      - are calculated at the end at written to this variable
 * @param CalcAmp - should amplitude calculation be performed
 * @param bnc_cnt - current bounce number
 * @param freq - frequency
 * @param GeoAc_theta, GeoAc_phi - current angles of propogation
 * @param lat_src, lon_src, z_src - spherical coords of the source location
 * @param sources, splines - structs containing information about the ray
 * @param results, raypaths, caustics - file output streams
 */
bool GeoAc_Propagate_RK4(double* &, bool, int, double, double, double,
                         double, double, double, GeoAc_Sources_Struct&, Splines_Struct&,
                         ofstream&, ofstream&, ofstream&);


#endif /* GEOAC_SOLVER_H_ */
