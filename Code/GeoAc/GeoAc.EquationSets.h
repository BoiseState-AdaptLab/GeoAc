#ifndef GEOAC_EQSETS_H_
#define GEOAC_EQSETS_H_

using namespace std;

//-----------------------------------------------------------//
//-------Structure containing source functions which are-----//
//-------called multiple times in the solver-----------------//
//-----------------------------------------------------------//
// This struct has been moved here to allow access by other files
struct GeoAc_Sources_Struct{

    double src_loc[3];  // Location of the source (r, theta, phi)
	double c0;			// Thermodynamic sound speed at source 

	double c;			// Thermodynamic sound speed
	double dc[5];		// Dc_r, Dc_t, Dc_p, dc_lt, dc_lp (derivatives with respect to radius, theta, phi, launch theta, launch phi)
	double ddc[3][2];	// ddc_rlt, ddc_rlp; ddc_tlt, ddc_tlp; ddc_plt, ddc_plp (derivatives with respect to r and lt, r and lp; etc.)
    
	double w;			// Vertical wind speed (r component, positive values upward)
	double dw[5];		// dw_r, dw_t, dw_p, dw_lt, dw_lp
    double ddw[3][2];	// ddw_rlt, ddw_rlp; ddw_tlt, ddw_tlp; ddw_plt, ddw_plp
    
	double v;			// N-S wind speed (theta component, positive values toward south pole)
	double dv[5];		// dv_r, dv_t, dv_p, dv_lt, dv_lp
    double ddv[3][2];	// ddv_rlt, ddv_rlp; ddv_tlt, ddv_tlp; ddv_plt, ddv_plp
    
	double u;			// E-W wind speed (phi component, positive values to the west)
	double du[5];		// du_r, du_t, du_p, du_lt, du_lp
    double ddu[3][2];	// ddu_rlt, ddu_rlp; ddu_tlt, ddu_tlp; ddu_plt, ddu_plp
    
    double nu0;         // Eikonal vector magnitude at the source
    double nu_mag;		// Eikonal vector magnitude
	double dnu_mag[2];	// Derivative of |nu| with respect to lt, lp

	double c_gr[3];         // Group velocity cg = c {nu_x,nu_y,nu_z}/|nu} + {u,v,w}
	double c_gr_mag;        // Group velocity magnitude |cp| = c sqrt(1 + 2 nu/|nu| dot v/c + v^2/c^2)
    double dc_gr[3][2];     // Derivatives of c_gr components with respect to lt and lp
	double dc_gr_mag[2];	// Derivatives of c_gr magnitude with respect to lt and lp
    
    double GeoCoeff[3];         // Scalar coefficients for coordiante transformation (spherical -> 1.0, 1.0/r, 1.0/(r*sin(theta)))
    double d_GeoCoeff[3][2];    // Angular derivatives of the coefficients for a coordiante transformation
    
    double GeoTerms[3];         // Extra terms which keep the eikonal vector direction constant as the unit vectors vary with position
    double d_GeoTerms[3][2];    // Angular derivatives of the extra terms keeping the eikonal vector direction constant
};

void    GeoAc_SetSystem();                                              // Function to set dimensions and stratified

void    GeoAc_SetInitialConditions(double**&);                          // Function sets initial conditions for a source at the origin with launch angles GeoAc_theta, GeoAc_phi
void    GeoAc_SetInitialConditions(double**&, double, double);          // Function sets initial conditions for a source at (r_0, z_0) with launch angles GeoAc_theta, GeoAc_phi
// Modified to take GeoAc_ angles by value and GeoAc_Sources_Struct by reference
void    GeoAc_SetInitialConditions(double**&, double, double, double, double, double, GeoAc_Sources_Struct&);  // Function sets initial conditions for a source at (x_0, y_0, z_0) with launch angles GeoAc_theta, GeoAc_phi

void    GeoAc_ApproximateIntercept(double**, int, double*&);            // Function uses linear interpolation to estimate ground intercept values
// Modified to take in GeoAc_Sources_Struct by reference
void    GeoAc_SetReflectionConditions(double**&, int, GeoAc_Sources_Struct&);                  // Function sets reflection conditions

// Modified to take in GeoAc_Sources_Struct by reference
void    GeoAc_UpdateSources(double, double*, GeoAc_Sources_Struct&);                           // Function to update source equation parameters which are used multiple times
double  GeoAc_Set_ds(double*);                                          // Function to modify the solver step size
// Modified to take in GeoAc_Sources_Struct by reference
double  GeoAc_EvalSrcEq(double, double*, int, GeoAc_Sources_Struct&);                          // Function to evaluate the source equations

double  GeoAc_EvalHamiltonian(double, double*);                         // Function to evaluate the hamiltonian (eikonal) at s, current_values
// Modified to take in GeoAc_Sources_Struct by reference
double  GeoAc_EvalHamiltonian(double**, int, GeoAc_Sources_Struct&);                           // Function to evaluate the hamiltonian at index of solution**

// Modified to take in GeoAc_Sources_Struct by reference
bool    GeoAc_BreakCheck(double **, int, GeoAc_Sources_Struct&);                               // Function to check for ray leaving propagation region
bool    GeoAc_GroundCheck(double **, int);                              // Function to check for ray returning to ground

double  GeoAc_TravelTime(double **, int);                               // Function to calculate travel time from ray origin to s = ds * index
void    GeoAc_TravelTimeSegment(double&, double**, int, int);           // Function increment travel time from ds*k_1 to d2*k_2
double  GeoAc_SB_Atten(double **, int, double);                         // Function to calculate atmospheric attenuation through a ray path
void    GeoAc_SB_AttenSegment(double&, double **, int , int, double);   // Function to increment atmospheric attenuation through a ray path
double  GeoAc_Jacobian(double **, int);                                 // Function to calculate the Jacobian determinant
// Modified to take GeoAc_ angles by value and GeoAc_Sources_Struct by reference
double  GeoAc_Amplitude(double **, int, double, double, GeoAc_Sources_Struct&);                                // Function to calculate the transport equation coefficient
int     GeoAc_CausticCnt(double **, int, int);                          // Function to count caustics from ray origin to s = ds * index

#endif /* GEOAC_EQSETS_H_ */
