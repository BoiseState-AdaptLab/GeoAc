# ifndef G2S_SPLINE1D_H_
# define G2S_SPLINE1D_H_

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <math.h>

using namespace std;

//----------------------------------------//
//------Parameters for Interpolation------//
//----------------------------------------//
extern int z_cnt;           // Number of vertical points
extern double* z_vals;      // z_k elements

//-------------------------------------//
////-----------One-Dimensional-----------//
////-------Interpolation Structure-------//
////-------------------------------------//
struct NaturalCubicSpline_1D{
    int length;                     // Length of input files (x and f(x))
    int accel;          // Index of previous table look up; used to increase spline speed
    double* x_vals;     // 1D array of x values
    double* f_vals;     // 1D array of f(x) values, f_vals[i] = f(x[i])
    double* slopes;     // Slopes used to generate natural cubic spline solution
};

#define PRINTSPLINE(s) cout << "length = " << s.length << endl;\
cout << "accel = " << s.accel << endl;\
cout << "x_vals | f_vals:" << endl;\
for (int i = 0; i < s.length; i++) cout << s.x_vals[i] << " " << s.f_vals[i] << endl;\
cout << "slopes = ";\
for (int i = 0; i < int(sizeof(s.slopes) / sizeof(double)); i++) cout << s.slopes[i] << " ";\
cout << endl;



// Struct to contain variables that were previously global
// Each thread gets their own
struct SplineStruct{
    //----------------------------------------//
    //------Parameters for Interpolation------//
    //----------------------------------------//
    int r_cnt;          // Number of vertical points
    int accel = 0;          // Acceleration index
    double* r_vals;     // r_k elements (r_cnt length)
    double* T_vals;    // Temperature at r_k
    double* u_vals;    // E-W winds at r_k
    double* v_vals;    // N-S winds at r_k
    double* rho_vals;  // Density at r_k
    //----------------------------------------------------//
    ////-------------Combined Function to Input-------------//
    ////------G2S Files and Generate the Interpolation------//
    ////----------------------------------------------------//
    struct NaturalCubicSpline_1D Temp_Spline;
    struct NaturalCubicSpline_1D Windu_Spline;
    struct NaturalCubicSpline_1D Windv_Spline;
    struct NaturalCubicSpline_1D Density_Spline;
};


#define PRINTSPLINES(s) cout << "r_cnt = " << s.r_cnt << endl;\
cout << "accel = " << s.accel << endl;\
cout << "r_vals | T_vals | u_vals | v_vals | rho_vals" << endl;\
for (int i = 0; i < s.r_cnt and i < 5; i++){\
cout << s.r_vals[i] << " " << s.T_vals[i] << " " << s.u_vals[i] << " " << s.v_vals[i] << " " << s.rho_vals[i] << endl;}\
cout << "Temp_Spline: " << endl;\
PRINTSPLINE(s.Temp_Spline);\
cout << "Windu_Spline: " << endl;\
PRINTSPLINE(s.Windu_Spline);\
cout << "Windv_Spline: " << endl;\
PRINTSPLINE(s.Windv_Spline);\
cout << "Density_Spline: " << endl;\
PRINTSPLINE(s.Density_Spline);\


//----------------------------------------//
//----------File IO Manipulation----------//
//----------------------------------------//
int file_length(string);            // Function to determine length (number of rows) in input file
int file_width(string);             // Function to determine width (number of columns) in input file
bool Check_G2S_Format(string);      // Function to check that there are columns for z, u, v, T, p, rho
                                    // Currently only check number of columns; might program to check for "realistic" values

//----------------------------------------//
//---------G2S Array Manipulation---------//
//----------------------------------------//
void SetUp_G2S_Arrays(char*, SplineStruct&);// Take the file prefix in char* and determine r_cnt, z_cnt; Set arrays to appropriate sizes
void Load_G2S_Single(char*,char*, SplineStruct&);// Take the file prefix in char* and r values in file name (string) and load all data into the arrays
void Clear_G2S_Arrays(SplineStruct&);       // Clear and delete the G2S arrays

//----------------------------------------------//
//------------Functions to Build and------------//
//-------Clear the Input and Slope Arrays-------//
//----------------------------------------------//
void BuildSlopeArrays(struct NaturalCubicSpline_1D &);
void ClearSlopeArrays(struct NaturalCubicSpline_1D &);

//--------------------------------------//
//-----------Functions to Set-----------//
//-------the Interpolation Slopes-------//
//--------------------------------------//
void Set_Slopes(struct NaturalCubicSpline_1D &);                        // Set the slopes at all constant r values in the f_vals array

//-----------------------------------------------//
//------Functions to Find the Segment Index------//
//-----and Evaluate the 1D Vertical Splines------//
//-----------------------------------------------//
int Find_Segment(double, double*, int, int &);                   // Find k such that x[k] <= x <= x[k+1]
double Eval_Spline_f(double, struct NaturalCubicSpline_1D &);    // Evaluate f @ x
double Eval_Spline_df(double, struct NaturalCubicSpline_1D &);   // Evaluate df/dx
double Eval_Spline_ddf(double, struct NaturalCubicSpline_1D &);  // Evaluate d^2f/dx^2

void Spline_Single_G2S(char*, char*, SplineStruct&);// Input the profile prefix and r_vals information to create splines of 2D G2S data
void ClearAll(SplineStruct&);                       // Function to clear the G2S arrays and slopes from interpolation


#endif /* G2S_SPLINE2D_H_ */
