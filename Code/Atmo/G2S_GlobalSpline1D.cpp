# ifndef G2S_GLOBALSPLINE1D_CPP_
# define G2S_GLOBALSPLINE1D_CPP_

#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <sstream>
#include <math.h>

#include "G2S_GlobalSpline1D.h"
#include "Atmo_State.h"
#include "GeoAc.Parameters.h"

using namespace std;
//-----------------------------------------------//
//---------Define the Propagation Region---------//
//-----------------------------------------------//
// These values are only set once
double r_min, r_max;

// Modified to pass in Windu_Spline by reference
void GeoAc_SetPropRegion(NaturalCubicSpline_1D &Windu_Spline){
    r_min = Windu_Spline.x_vals[0];
    r_max = Windu_Spline.x_vals[Windu_Spline.length-1];
    
    GeoAc_vert_limit  =	r_max;
    GeoAc_range_limit = 1500.0;
    GeoAc_lat_min_limit = -Pi/2.0;  GeoAc_lat_max_limit = Pi/2.0;
    GeoAc_lon_min_limit = -Pi;      GeoAc_lon_max_limit = Pi;
}

//-----------------------------------------------//
//---------Topographical Ground Function---------//
//-----------------------------------------------//
// Constants, don't worry about them
double r_earth = 6370.0;
double z_grnd = 0.0;

double GroundTopography(double lat, double lon){
    return r_earth + z_grnd;
}

//----------------------------------------//
//----------File IO Manipulation----------//
//----------------------------------------//
int file_length(string file_name){
	ifstream file_in;	file_in.open(file_name.c_str() );
	if(!file_in.is_open()){
		cout << "Error opening file, check file name" << '\n';
		return 0;
	} else {
		int count = 0;
		string line;
        
		while(!file_in.eof()) {
			getline (file_in, line);
			count++;
		}
		file_in.close();
		return count - 1;
	}
}

int file_width(string file_name){
	double temp;
	int known_length = file_length(file_name);
	int count = 0;
    ifstream file_in;   file_in.open(file_name.c_str() );
    if(!file_in.is_open()){
		cout << "Error opening file, check file name" << '\n';
		return 0;
	} else {
		file_in.close();
		file_in.open(file_name.c_str() );
		while(!file_in.eof()) {
			file_in >> temp;
			count++;
		}
		file_in.close();
		return (count - 1)/known_length;
	}
}

bool Check_G2S_Format(string file_name){
    int width = file_width(file_name);
    if(width==6){ return true;}
    else{         return false;}
}

//----------------------------------------//
//---------G2S Array Manipulation---------//
//----------------------------------------//
// Modified to pass in Splines_Struct by reference
void SetUp_G2S_Arrays(char* file_name, Splines_Struct &splines){
    splines.r_cnt = file_length(file_name);
    
    splines.r_vals = new double [splines.r_cnt];
    splines.T_vals = new double [splines.r_cnt];   splines.rho_vals = new double [splines.r_cnt];
    splines.u_vals = new double [splines.r_cnt];   splines.v_vals = new double [splines.r_cnt];
}

// Modified to pass in Splines_Struct by reference
void Load_G2S(char* file_name, char* option, Splines_Struct &splines){
    ifstream file_in; double temp;
    file_in.open(file_name);
    
    if (strncmp(option, "zTuvdp",6) == 0){
        for (int nr = 0; nr < splines.r_cnt; nr++){
            file_in >> splines.r_vals[nr];      // Extract r_i value
            file_in >> splines.T_vals[nr];      // Extract T(r_i)
            file_in >> splines.u_vals[nr];      // Extract u(r_i)
            file_in >> splines.v_vals[nr];      // Extract v(r_i)
            file_in >> splines.rho_vals[nr];    // Extract rho(r_i)
            file_in >> temp;            // Extract p(r_i)
            
            
            // Convert to global radius and convert winds m/s -> km/s and scale near the ground to guarantee u(r_g), v(r_g) = 0
            splines.r_vals[nr] += r_earth;
            splines.u_vals[nr] *= (2.0 / (1.0 + exp(-(splines.r_vals[nr] - r_earth - z_grnd)/0.2)) - 1.0) / 1000.0;
            splines.v_vals[nr] *= (2.0 / (1.0 + exp(-(splines.r_vals[nr] - r_earth - z_grnd)/0.2)) - 1.0) / 1000.0;
        }
    } else if (strncmp(option, "zuvwTdp",7) == 0){
        for (int nr = 0; nr < splines.r_cnt; nr++){
            file_in >> splines.r_vals[nr];      // Extract r_i value
            file_in >> splines.u_vals[nr];      // Extract u(r_i)
            file_in >> splines.v_vals[nr];      // Extract v(r_i)
            file_in >> temp;            // Extract w(r_i) but don't store it
            file_in >> splines.T_vals[nr];      // Extract T(r_i)
            file_in >> splines.rho_vals[nr];    // Extract rho(r_i)
            file_in >> temp;            // Extract p(r_i) but don't store it
            
            // Convert to global radius and convert winds m/s -> km/s and scale near the ground to guarantee u(r_g), v(r_g) = 0
            splines.r_vals[nr] += r_earth;
            splines.u_vals[nr] *= (2.0 / (1.0 + exp(-(splines.r_vals[nr] - r_earth - z_grnd)/0.2)) - 1.0) / 1000.0;
            splines.v_vals[nr] *= (2.0 / (1.0 + exp(-(splines.r_vals[nr] - r_earth - z_grnd)/0.2)) - 1.0) / 1000.0;
        }
    } else {
        cout << "Unrecognized profile option: " << option << ".  Valid options are: zTuvdp and zuvwTdp" << '\n';
    }
    file_in.close();
}

// Modified to pass in Splines_Struct by reference
void Clear_G2S_Arrays(Splines_Struct &splines){
    delete splines.r_vals;
    delete splines.T_vals;      delete splines.rho_vals;
    delete splines.u_vals;      delete splines.v_vals;
}

//----------------------------------------------//
//------------Functions to Build and------------//
//-------Clear the Input and Slope Arrays-------//
//----------------------------------------------//
void BuildSlopeArray(struct NaturalCubicSpline_1D & Spline){
    Spline.slopes = new double [Spline.length];
}

void ClearSlopeArray(struct NaturalCubicSpline_1D & Spline){
    delete Spline.slopes;
}

//--------------------------------------//
//-----------Functions to Set-----------//
//-------the Interpolation Slopes-------//
//--------------------------------------//
void Set_Slopes(struct NaturalCubicSpline_1D & Spline){
    double ai, bi, ci, di;
    double new_c[Spline.length-1];
    double new_d[Spline.length];
    
    bi = 2.0 / (Spline.x_vals[1] - Spline.x_vals[0]);
    ci = 1.0 / (Spline.x_vals[1] - Spline.x_vals[0]);
    di = 3.0 * (Spline.f_vals[1] - Spline.f_vals[0]) / pow(Spline.x_vals[1] - Spline.x_vals[0], 2);
    
    new_c[0] = ci/bi;
    new_d[0] = di/bi;
    
    for(int i = 1; i < Spline.length - 1; i++) {
        ai = 1.0/(Spline.x_vals[i] - Spline.x_vals[i-1]);
        bi = 2.0 * (1.0/(Spline.x_vals[i] - Spline.x_vals[i-1]) + 1.0/(Spline.x_vals[i+1] - Spline.x_vals[i]));
        ci = 1.0/(Spline.x_vals[i+1] - Spline.x_vals[i]);
        di = 3.0 * ((Spline.f_vals[i] - Spline.f_vals[i-1]) / pow(Spline.x_vals[i] - Spline.x_vals[i-1], 2)
                    + (Spline.f_vals[i+1] - Spline.f_vals[i]) / pow(Spline.x_vals[i+1] - Spline.x_vals[i], 2) );
        
        new_c[i] = ci/(bi - new_c[i-1]*ai);
        new_d[i] = (di - new_d[i-1]*ai)/(bi - new_c[i-1]*ai);
    }
    
    ai = 1.0/(Spline.x_vals[Spline.length-1] - Spline.x_vals[Spline.length-2]);
    bi = 2.0/(Spline.x_vals[Spline.length-1] - Spline.x_vals[Spline.length-2]);
    di = 3.0 * (Spline.f_vals[Spline.length-1] - Spline.f_vals[Spline.length-2])
            / pow(Spline.x_vals[Spline.length-1] - Spline.x_vals[Spline.length-2], 2);
    
    new_d[Spline.length-1] = (di - new_d[Spline.length - 2]*ai)/(bi - new_c[Spline.length - 2]*ai);
    
    Spline.slopes[Spline.length - 1] = new_d[Spline.length - 1];
    for(int i = Spline.length - 2; i > -1; i--){
        Spline.slopes[i] = new_d[i] - new_c[i] * Spline.slopes[i+1];
    }

}

//-----------------------------------------------//
//------Functions to Find the Segment Index------//
//-----and Evaluate the 1D Vertical Splines------//
//-----------------------------------------------//
int Find_Segment(double x, double* x_vals, int length, int & prev){
    int index = length + 1;
    bool done = false;
    
    if(x > x_vals[length-1] || x < x_vals[0]){
        cout << "Cannot interpolate outside of given bounds.  x = " << x << " is invalid." << '\n';
    } else {
        
        // Check previous index and bounding segments
        if(x >= x_vals[prev] && x <= x_vals[prev+1]){
            done = true;
        }

        if(!done && prev+2 <= length-1){
            if(x >= x_vals[prev+1] && x <= x_vals[prev+2]){
                done = true;
                prev = prev + 1;
            }
        }
        if(!done && prev-1 >= 0){
            if(x >= x_vals[prev-1] && x <= x_vals[prev]){
                done = true;
                prev = prev - 1;
            }
        }
    
        if(!done){
            for(int i = 0; i < length; i++){
                if(x >= x_vals[i] && x <= x_vals[i+1]){
                    index = i;
                    break;
                }
                if (x >= x_vals[length - 2 - i] && x < x_vals[length - 1 - i]){
                    index = (length - 2) - i;
                    break;
                }
            }
            prev = index;
        }
        return prev;
    }
}

double Eval_Spline_f(double x, struct NaturalCubicSpline_1D & Spline){
    int k = Find_Segment(x, Spline.x_vals, Spline.length, Spline.accel);
    
    if(k < Spline.length){
        double X = (x - Spline.x_vals[k])/(Spline.x_vals[k+1] - Spline.x_vals[k]);
        double A = Spline.slopes[k] * (Spline.x_vals[k+1] - Spline.x_vals[k]) - (Spline.f_vals[k+1] - Spline.f_vals[k]);
        double B = -Spline.slopes[k+1] * (Spline.x_vals[k+1] - Spline.x_vals[k]) + (Spline.f_vals[k+1] - Spline.f_vals[k]);
        
        return (1.0 - X) * Spline.f_vals[k] + X * Spline.f_vals[k+1] + X * (1.0 - X) * (A * (1.0 - X ) + B * X);
    } else { return 0.0;}
}

double Eval_Spline_df(double x, struct NaturalCubicSpline_1D & Spline){
    int k = Find_Segment(x, Spline.x_vals, Spline.length, Spline.accel);
    
    if(k < Spline.length){
        double X = (x - Spline.x_vals[k])/(Spline.x_vals[k+1] - Spline.x_vals[k]);
        double A = Spline.slopes[k] * (Spline.x_vals[k+1] - Spline.x_vals[k]) - (Spline.f_vals[k+1] - Spline.f_vals[k]);
        double B = -Spline.slopes[k+1] * (Spline.x_vals[k+1] - Spline.x_vals[k]) + (Spline.f_vals[k+1] - Spline.f_vals[k]);
        
        return (Spline.f_vals[k+1] - Spline.f_vals[k])/(Spline.x_vals[k+1] - Spline.x_vals[k])
        + (1.0 - 2.0 * X) * (A * (1.0 - X) + B * X)/(Spline.x_vals[k+1] - Spline.x_vals[k])
        + X * (1.0 - X) * (B - A)/(Spline.x_vals[k+1] - Spline.x_vals[k]);
    } else { return 0.0;}
}

double Eval_Spline_ddf(double x, struct NaturalCubicSpline_1D & Spline){
    int k = Find_Segment(x, Spline.x_vals, Spline.length, Spline.accel);
    
    if(k < Spline.length){
        double X = (x - Spline.x_vals[k])/(Spline.x_vals[k+1] - Spline.x_vals[k]);
        double A = Spline.slopes[k] * (Spline.x_vals[k+1] - Spline.x_vals[k]) - (Spline.f_vals[k+1] - Spline.f_vals[k]);
        double B = -Spline.slopes[k+1] * (Spline.x_vals[k+1] - Spline.x_vals[k]) + (Spline.f_vals[k+1] - Spline.f_vals[k]);
        
        return 2.0 * (B - 2.0 * A + (A - B) * 3.0 * X)/pow(Spline.x_vals[k+1] - Spline.x_vals[k],2);
    } else { return 0.0;}
}

// Modified to pass in Splines_Struct by reference
void Spline_Single_G2S(char* file_name, char* option, Splines_Struct &splines){
    SetUp_G2S_Arrays(file_name, splines);
    Load_G2S(file_name, option, splines);
    
    splines.Temp_Spline.length = splines.r_cnt;     splines.Windu_Spline.length = splines.r_cnt;
    splines.Windv_Spline.length = splines.r_cnt;    splines.Density_Spline.length = splines.r_cnt;

    splines.Temp_Spline.accel = splines.accel;      splines.Windu_Spline.accel = splines.accel;
    splines.Windv_Spline.accel = splines.accel;     splines.Density_Spline.accel = splines.accel;

    splines.Temp_Spline.x_vals = splines.r_vals;    splines.Windu_Spline.x_vals = splines.r_vals;
    splines.Windv_Spline.x_vals = splines.r_vals;   splines.Density_Spline.x_vals = splines.r_vals;

    splines.Temp_Spline.f_vals = splines.T_vals;    splines.Windu_Spline.f_vals = splines.u_vals;
    splines.Windv_Spline.f_vals = splines.v_vals;   splines.Density_Spline.f_vals = splines.rho_vals;

    GeoAc_SetPropRegion(splines.Windu_Spline);
    
    BuildSlopeArray(splines.Temp_Spline);       BuildSlopeArray(splines.Windu_Spline); 
    BuildSlopeArray(splines.Density_Spline);    BuildSlopeArray(splines.Windv_Spline);
    
    Set_Slopes(splines.Temp_Spline);            Set_Slopes(splines.Windu_Spline);
    Set_Slopes(splines.Density_Spline);         Set_Slopes(splines.Windv_Spline);
}

// Modified to pass in Splines_Struct by reference
void ClearAll(Splines_Struct &splines){
    ClearSlopeArray(splines.Temp_Spline);       ClearSlopeArray(splines.Windu_Spline);
    ClearSlopeArray(splines.Density_Spline);    ClearSlopeArray(splines.Windv_Spline);
    Clear_G2S_Arrays(splines);
}


//-------------------------------------//
//---------Atmospheric Density---------//
//-------------------------------------//
// Modified to pass in NaturalCubicSpline_1D by reference
double rho(double r, double theta, double phi, NaturalCubicSpline_1D &Density_Spline){
    double r_eval = min(r, r_max);  r_eval = max(r_eval, r_min);    // Check that r_min <= r_eval <= r_max
    
    return Eval_Spline_f(r_eval,Density_Spline);
}

//-------------------------------------------//
//---------Thermodynamic Sound Speed---------//
//------------and its Derivatives------------//
//-------------------------------------------//

double gamR = 0.00040187; // gamma * R in km^2/s^2 * 1/K, c(x,y,z) = sqrt(gamma*r*T(x,y,z))

// Modified to pass in NaturalCubicSpline_1D by reference
double c(double r, double theta, double phi, NaturalCubicSpline_1D &Temp_Spline){
    double r_eval = min(r, r_max);  r_eval = max(r_eval, r_min);    // Check that r_min <= r_eval <= r_max
    
    return sqrt(gamR * Eval_Spline_f(r_eval,Temp_Spline));
}

// Modified to pass in NaturalCubicSpline_1D by reference
double c_diff(double r, double theta, double phi, int n, NaturalCubicSpline_1D &Temp_Spline){
    double r_eval = min(r, r_max);  r_eval = max(r_eval, r_min);    // Check that r_min <= r_eval <= r_max
    
    if(n==0){   return gamR / (2.0 * c(r,theta,phi, Temp_Spline)) * Eval_Spline_df(r_eval,Temp_Spline);}
    else {      return 0.0;}
}

// Modified to pass in NaturalCubicSpline_1D by reference
double c_ddiff(double r, double theta, double phi, int n1, int n2, NaturalCubicSpline_1D &Temp_Spline){
    double r_eval = min(r, r_max);  r_eval = max(r_eval, r_min);    // Check that r_min <= r_eval <= r_max
    double SndSpd = c(r, theta, phi, Temp_Spline);
    
    if(n1==0 && n2==0){
        return gamR / (2.0 * SndSpd) * Eval_Spline_ddf(r_eval,Temp_Spline)
                - pow(gamR,2)/(4.0 * pow(SndSpd,3)) * pow(Eval_Spline_df(r_eval,Temp_Spline),2);
    } else {
        return 0.0;
    }
}


//------------------------------------------//
//---------East-West Wind Component---------//
//------------and its Derivatives-----------//
//------------------------------------------//
// Modified to pass in NaturalCubicSpline_1D by reference
double u(double r, double theta, double phi, NaturalCubicSpline_1D &Windu_Spline){
    double r_eval = min(r, r_max);  r_eval = max(r_eval, r_min);    // Check that r_min <= r_eval <= r_max
    
    return Eval_Spline_f(r_eval, Windu_Spline);
}


// Modified to pass in NaturalCubicSpline_1D by reference
double u_diff(double r, double theta, double phi, int n, NaturalCubicSpline_1D &Windu_Spline){
    double r_eval = min(r, r_max);  r_eval = max(r_eval, r_min);    // Check that r_min <= r_eval <= r_max
    
    if(n==0)  return Eval_Spline_df(r_eval, Windu_Spline);
    else        return 0.0;
}

// Modified to pass in NaturalCubicSpline_1D by reference
double u_ddiff(double r, double theta, double phi, int n1, int n2, NaturalCubicSpline_1D &Windu_Spline){
    double r_eval = min(r, r_max);  r_eval = max(r_eval, r_min);    // Check that r_min <= r_eval <= r_max
    
    if(n1==0&&n2==0)    return Eval_Spline_ddf(r_eval, Windu_Spline);
    else                return 0.0;
}


//--------------------------------------------//
//---------North-South Wind Component---------//
//-------------and its Derivatives------------//
//--------------------------------------------//
// Modified to pass in NaturalCubicSpline_1D by reference
double v(double r, double theta, double phi, NaturalCubicSpline_1D &Windv_Spline){
    double r_eval = min(r, r_max);  r_eval = max(r_eval, r_min);    // Check that r_min <= r_eval <= r_max
    
    return Eval_Spline_f(r_eval, Windv_Spline);
}

// Modified to pass in NaturalCubicSpline_1D by reference
double v_diff(double r, double theta, double phi, int n, NaturalCubicSpline_1D &Windv_Spline){
    double r_eval = min(r, r_max);  r_eval = max(r_eval, r_min);    // Check that r_min <= r_eval <= r_max
    
    if(n==0)   return Eval_Spline_df(r_eval, Windv_Spline);
    else       return 0.0;
}

// Modified to pass in NaturalCubicSpline_1D by reference
double v_ddiff(double r, double theta, double phi, int n1, int n2, NaturalCubicSpline_1D &Windv_Spline){
    double r_eval = min(r, r_max);  r_eval = max(r_eval, r_min);    // Check that r_min <= r_eval <= r_max
    
    if(n1==0&&n2==0)    return Eval_Spline_ddf(r_eval, Windv_Spline);
    else                return 0.0;
}


//-----------------------------------------//
//---------Vertical Wind Component---------//
//-----------and its Derivatives-----------//
//-----------------------------------------//
double w(double r, double theta, double phi){                         return 0.0;}
double w_diff(double r, double theta, double phi, int n){             return 0.0;}
double w_ddiff(double r, double theta, double phi, int n1, int n2){   return 0.0;}

#endif /* G2S_GLOBALSPLINE1D_CPP_ */
