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
double r_min, r_max;

// For GeoAcGlobal_main, called once in Spline_Single_G2S()
void GeoAc_SetPropRegion(NaturalCubicSpline_1D &Windu_Spline){
    r_min = Windu_Spline.x_vals[0];
    r_max = Windu_Spline.x_vals[Windu_Spline.length-1];

    //cout << "Setting r bounds: " << r_min << " -> " << r_max << endl;
    
    GeoAc_vert_limit  =	r_max;
    GeoAc_range_limit = 1500.0;
    GeoAc_lat_min_limit = -Pi/2.0;  GeoAc_lat_max_limit = Pi/2.0;
    GeoAc_lon_min_limit = -Pi;      GeoAc_lon_max_limit = Pi;
}

//-----------------------------------------------//
//---------Topographical Ground Function---------//
//-----------------------------------------------//
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
void SetUp_G2S_Arrays(char* file_name, SplineStruct &spline){
    spline.r_cnt = file_length(file_name);
    
    spline.r_vals = new double [spline.r_cnt];
    spline.T_vals = new double [spline.r_cnt];
    spline.rho_vals = new double [spline.r_cnt];
    spline.u_vals = new double [spline.r_cnt];
    spline.v_vals = new double [spline.r_cnt];
}

void Load_G2S(char* file_name, char* option, SplineStruct &spline){
    ifstream file_in; double temp;
    file_in.open(file_name);

    //cout << "Load G2S: r_earth = " << r_earth << " z_grnd = " << z_grnd << endl;
    
    if (strncmp(option, "zTuvdp",6) == 0){
        for (int nr = 0; nr < spline.r_cnt; nr++){
            file_in >> spline.r_vals[nr];      // Extract r_i value
            file_in >> spline.T_vals[nr];      // Extract T(r_i)
            file_in >> spline.u_vals[nr];      // Extract u(r_i)
            file_in >> spline.v_vals[nr];      // Extract v(r_i)
            file_in >> spline.rho_vals[nr];    // Extract rho(r_i)
            file_in >> temp;            // Extract p(r_i)
            
            
            // Convert to global radius and convert winds m/s -> km/s and scale near the ground to guarantee u(r_g), v(r_g) = 0
            spline.r_vals[nr] += r_earth;
            spline.u_vals[nr] *= (2.0 / (1.0 + exp(-(spline.r_vals[nr] - r_earth - z_grnd)/0.2)) - 1.0) / 1000.0;
            spline.v_vals[nr] *= (2.0 / (1.0 + exp(-(spline.r_vals[nr] - r_earth - z_grnd)/0.2)) - 1.0) / 1000.0;
        }
    } else if (strncmp(option, "zuvwTdp",7) == 0){
        for (int nr = 0; nr < spline.r_cnt; nr++){
            file_in >> spline.r_vals[nr];      // Extract r_i value
            file_in >> spline.u_vals[nr];      // Extract u(r_i)
            file_in >> spline.v_vals[nr];      // Extract v(r_i)
            file_in >> temp;            // Extract w(r_i) but don't store it
            file_in >> spline.T_vals[nr];      // Extract T(r_i)
            file_in >> spline.rho_vals[nr];    // Extract rho(r_i)
            file_in >> temp;            // Extract p(r_i) but don't store it
            
            // Convert to global radius and convert winds m/s -> km/s and scale near the ground to guarantee u(r_g), v(r_g) = 0
            spline.r_vals[nr] += r_earth;
            spline.u_vals[nr] *= (2.0 / (1.0 + exp(-(spline.r_vals[nr] - r_earth - z_grnd)/0.2)) - 1.0) / 1000.0;
            spline.v_vals[nr] *= (2.0 / (1.0 + exp(-(spline.r_vals[nr] - r_earth - z_grnd)/0.2)) - 1.0) / 1000.0;
        }
    } else {
        cout << "Unrecognized profile option: " << option << ".  Valid options are: zTuvdp and zuvwTdp" << '\n';
    }

    //cout << " First and Last of r_vals = " << spline.r_vals[0] << " " << spline.r_vals[spline.r_cnt] << endl;

    file_in.close();
}

void Clear_G2S_Arrays(SplineStruct &spline){
    delete spline.r_vals;
    delete spline.T_vals;      delete spline.rho_vals;
    delete spline.u_vals;      delete spline.v_vals;
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
    //cout << "Called Find_Segment()" << endl;
    int index = length + 1;
    bool done = false;
    
    //cout << sizeof(x_vals) / sizeof(x_vals[0])  << " " << length << endl;

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
    //cout << "Called Eval_Spline_f" << endl;

    //cout << "Eval: x = " << x << endl;

    int k = Find_Segment(x, Spline.x_vals, Spline.length, Spline.accel);
 
    //cout << "Eval: k = " << k << " spline length = " << Spline.length << endl;   

    //cout << "Passed Find_Segment()" << endl;
    
    if(k < Spline.length){
        double X = (x - Spline.x_vals[k])/(Spline.x_vals[k+1] - Spline.x_vals[k]);
        double A = Spline.slopes[k] * (Spline.x_vals[k+1] - Spline.x_vals[k]) - (Spline.f_vals[k+1] - Spline.f_vals[k]);
        double B = -Spline.slopes[k+1] * (Spline.x_vals[k+1] - Spline.x_vals[k]) + (Spline.f_vals[k+1] - Spline.f_vals[k]);

        //cout << "Eval: X = " << X << " A = " << A << " B = " << B << endl;
       	
        //cout << "Ready to return" << endl;

        double result = (1.0 - X) * Spline.f_vals[k] + X * Spline.f_vals[k+1] + X * (1.0 - X) * (A * (1.0 - X ) + B * X);
        //cout << "Eval: result = " << result << endl;
        return result;
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


//----------------------------------------------------//
//-------------Combined Function to Input-------------//
//------G2S Files and Generate the Interpolation------//
//----------------------------------------------------//
// Called once at the beginning of GeoAcGlobal_main
void Spline_Single_G2S(char* file_name, char* option, SplineStruct &spline){
    SetUp_G2S_Arrays(file_name, spline);
    Load_G2S(file_name, option, spline);
 
    spline.Temp_Spline.length = spline.r_cnt;     spline.Windu_Spline.length = spline.r_cnt;
    //cout << "Temp Spline length " << spline.Temp_Spline.length << endl;
    spline.Windv_Spline.length = spline.r_cnt;    spline.Density_Spline.length = spline.r_cnt;
    spline.Temp_Spline.accel = spline.accel;      spline.Windu_Spline.accel = spline.accel;
    spline.Windv_Spline.accel = spline.accel;     spline.Density_Spline.accel = spline.accel;
    spline.Temp_Spline.x_vals = spline.r_vals;    spline.Windu_Spline.x_vals = spline.r_vals;
    spline.Windv_Spline.x_vals = spline.r_vals;   spline.Density_Spline.x_vals = spline.r_vals;
    spline.Temp_Spline.f_vals = spline.T_vals;    spline.Windu_Spline.f_vals = spline.u_vals;
    spline.Windv_Spline.f_vals = spline.v_vals;   spline.Density_Spline.f_vals = spline.rho_vals;
    GeoAc_SetPropRegion(spline.Windu_Spline);
    
    BuildSlopeArray(spline.Temp_Spline);       BuildSlopeArray(spline.Windu_Spline); 
    BuildSlopeArray(spline.Density_Spline);    BuildSlopeArray(spline.Windv_Spline);
    
    Set_Slopes(spline.Temp_Spline);            Set_Slopes(spline.Windu_Spline);
    Set_Slopes(spline.Density_Spline);         Set_Slopes(spline.Windv_Spline);
}

void ClearAll(SplineStruct &spline){
    ClearSlopeArray(spline.Temp_Spline);    ClearSlopeArray(spline.Windu_Spline);
    ClearSlopeArray(spline.Density_Spline); ClearSlopeArray(spline.Windv_Spline);
    Clear_G2S_Arrays(spline);
}


//-------------------------------------//
//---------Atmospheric Density---------//
//-------------------------------------//
double rho(double r, double theta, double phi, NaturalCubicSpline_1D &Density_Spline){
    double r_eval = min(r, r_max);  r_eval = max(r_eval, r_min);    // Check that r_min <= r_eval <= r_max
    
    return Eval_Spline_f(r_eval,Density_Spline);
}

//-------------------------------------------//
//---------Thermodynamic Sound Speed---------//
//------------and its Derivatives------------//
//-------------------------------------------//

double gamR = 0.00040187; // gamma * R in km^2/s^2 * 1/K, c(x,y,z) = sqrt(gamma*r*T(x,y,z))

double c(double r, double theta, double phi, NaturalCubicSpline_1D &Temp_Spline){
    //cout << "c: r_max = " << r_max << ", r_min = " << r_min << ", gamR = " << gamR << endl;
    double r_eval = min(r, r_max);  r_eval = max(r_eval, r_min);    // Check that r_min <= r_eval <= r_max
    //cout << "c: r_eval = " << r_eval << endl;
    double result = sqrt(gamR * Eval_Spline_f(r_eval,Temp_Spline));
    //cout << "c: result = " << result << endl;
    return result;
}

double c_diff(double r, double theta, double phi, int n, NaturalCubicSpline_1D &Temp_Spline){
    double r_eval = min(r, r_max);  r_eval = max(r_eval, r_min);    // Check that r_min <= r_eval <= r_max
    
    if(n==0){   return gamR / (2.0 * c(r,theta,phi, Temp_Spline)) * Eval_Spline_df(r_eval,Temp_Spline);}
    else {      return 0.0;}
}

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
double u(double r, double theta, double phi, NaturalCubicSpline_1D &Windu_Spline){
    double r_eval = min(r, r_max);  r_eval = max(r_eval, r_min);    // Check that r_min <= r_eval <= r_max
    
    return Eval_Spline_f(r_eval, Windu_Spline);
}


double u_diff(double r, double theta, double phi, int n, NaturalCubicSpline_1D &Windu_Spline){
    double r_eval = min(r, r_max);  r_eval = max(r_eval, r_min);    // Check that r_min <= r_eval <= r_max
    
    if(n==0)  return Eval_Spline_df(r_eval, Windu_Spline);
    else        return 0.0;
}

double u_ddiff(double r, double theta, double phi, int n1, int n2, NaturalCubicSpline_1D &Windu_Spline){
    double r_eval = min(r, r_max);  r_eval = max(r_eval, r_min);    // Check that r_min <= r_eval <= r_max
    
    if(n1==0&&n2==0)    return Eval_Spline_ddf(r_eval, Windu_Spline);
    else                return 0.0;
}


//--------------------------------------------//
//---------North-South Wind Component---------//
//-------------and its Derivatives------------//
//--------------------------------------------//
double v(double r, double theta, double phi, NaturalCubicSpline_1D &Windv_Spline){
    double r_eval = min(r, r_max);  r_eval = max(r_eval, r_min);    // Check that r_min <= r_eval <= r_max
    
    return Eval_Spline_f(r_eval, Windv_Spline);
}

double v_diff(double r, double theta, double phi, int n, NaturalCubicSpline_1D &Windv_Spline){
    double r_eval = min(r, r_max);  r_eval = max(r_eval, r_min);    // Check that r_min <= r_eval <= r_max
    
    if(n==0)   return Eval_Spline_df(r_eval, Windv_Spline);
    else       return 0.0;
}

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
