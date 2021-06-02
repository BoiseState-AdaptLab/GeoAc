#undef s0
#undef s1
#undef s2
#undef s3
#undef s4
#undef s5
#undef s6
#undef s7
#undef s8
#undef s9
#undef s10
#undef s11
#undef s12
#undef s13
#undef s14
#undef s15
#undef s16
#undef s17
#undef s18
#undef s19
#undef s20
#undef s21
#undef s22
#undef s23
#undef s24
#undef s25
#undef s26
#undef s27
#undef s28
#undef s29
#undef s30
#undef s31
#undef s32
#undef s33
#undef s34
#undef s35
#undef s36
#undef s37
#undef s38
#undef s39
#undef s40
#undef s41
#undef s42
#undef s43
#undef s44
#undef s45
#undef s46
#undef s47
#undef s48
#undef s49
#undef s50
#define s0(__x0)   double _iegen_2r = r; 
#define s1(__x0)   double _iegen_2theta = theta; 
#define s2(__x0)   double _iegen_2phi = phi; 
#define s3(__x0)   NaturalCubicSpline_1D & _iegen_2Temp_Spline = spl.Temp_Spline; 
#define s4(__x0)   double _iegen_2r_eval = min(_iegen_2r, r_max); 
#define s5(__x0)   _iegen_2r_eval = max(_iegen_2r_eval, r_min); 
#define s6(__x0)   double _iegen_2_iegen_1x = _iegen_2r_eval; 
#define s7(__x0)   struct NaturalCubicSpline_1D & _iegen_2_iegen_1Spline = _iegen_2Temp_Spline; 
#define s8(__x0)   double _iegen_2_iegen_1_iegen_0x = _iegen_2_iegen_1x; 
#define s9(__x0)   double* _iegen_2_iegen_1_iegen_0x_vals = _iegen_2_iegen_1Spline.x_vals; 
#define s10(__x0)   int _iegen_2_iegen_1_iegen_0length = _iegen_2_iegen_1Spline.length; 
#define s11(__x0)   int& _iegen_2_iegen_1_iegen_0prev = _iegen_2_iegen_1Spline.accel; 
#define s12(__x0, i, __x2)   if(_iegen_2_iegen_1_iegen_0x >= _iegen_2_iegen_1_iegen_0x_vals[i] && _iegen_2_iegen_1_iegen_0x <= _iegen_2_iegen_1_iegen_0x_vals[i+1]) _iegen_2_iegen_1_iegen_0prev = i; 
#define s13(__x0)   int _iegen_2_iegen_1k = _iegen_2_iegen_1_iegen_0prev; 
#define s14(__x0)   double _iegen_2_iegen_1result = 0.0; 
#define s15(__x0)   if(_iegen_2_iegen_1k < _iegen_2_iegen_1Spline.length) { double _iegen_2_iegen_1X = (_iegen_2_iegen_1x - _iegen_2_iegen_1Spline.x_vals[_iegen_2_iegen_1k])/(_iegen_2_iegen_1Spline.x_vals[_iegen_2_iegen_1k+1] - _iegen_2_iegen_1Spline.x_vals[_iegen_2_iegen_1k]); double _iegen_2_iegen_1A = _iegen_2_iegen_1Spline.slopes[_iegen_2_iegen_1k] * (_iegen_2_iegen_1Spline.x_vals[_iegen_2_iegen_1k+1] - _iegen_2_iegen_1Spline.x_vals[_iegen_2_iegen_1k]) - (_iegen_2_iegen_1Spline.f_vals[_iegen_2_iegen_1k+1] - _iegen_2_iegen_1Spline.f_vals[_iegen_2_iegen_1k]); double _iegen_2_iegen_1B = -_iegen_2_iegen_1Spline.slopes[_iegen_2_iegen_1k+1] * (_iegen_2_iegen_1Spline.x_vals[_iegen_2_iegen_1k+1] - _iegen_2_iegen_1Spline.x_vals[_iegen_2_iegen_1k]) + (_iegen_2_iegen_1Spline.f_vals[_iegen_2_iegen_1k+1] - _iegen_2_iegen_1Spline.f_vals[_iegen_2_iegen_1k]); _iegen_2_iegen_1result = (1.0 - _iegen_2_iegen_1X) * _iegen_2_iegen_1Spline.f_vals[_iegen_2_iegen_1k] + _iegen_2_iegen_1X * _iegen_2_iegen_1Spline.f_vals[_iegen_2_iegen_1k+1] + _iegen_2_iegen_1X * (1.0 - _iegen_2_iegen_1X) * (_iegen_2_iegen_1A * (1.0 - _iegen_2_iegen_1X ) + _iegen_2_iegen_1B * _iegen_2_iegen_1X);} 
#define s16(__x0)   double _iegen_2c_result = sqrt(gamR * _iegen_2_iegen_1result); 
#define s17(__x0, __x1, __x2)   sources.c = _iegen_2c_result; 
#define s18(__x0, __x1, __x2)   sources.w = 0; 
#define s19(__x0)   double _iegen_5r = r; 
#define s20(__x0)   double _iegen_5theta = theta; 
#define s21(__x0)   double _iegen_5phi = phi; 
#define s22(__x0)   NaturalCubicSpline_1D & _iegen_5Windv_Spline = spl.Windv_Spline; 
#define s23(__x0)   double _iegen_5r_eval = min(_iegen_5r, r_max); _iegen_5r_eval = max(_iegen_5r_eval, r_min) 
#define s24(__x0)   double _iegen_5_iegen_4x = _iegen_5r_eval; 
#define s25(__x0)   struct NaturalCubicSpline_1D & _iegen_5_iegen_4Spline = _iegen_5Windv_Spline; 
#define s26(__x0)   double _iegen_5_iegen_4_iegen_3x = _iegen_5_iegen_4x; 
#define s27(__x0)   double* _iegen_5_iegen_4_iegen_3x_vals = _iegen_5_iegen_4Spline.x_vals; 
#define s28(__x0)   int _iegen_5_iegen_4_iegen_3length = _iegen_5_iegen_4Spline.length; 
#define s29(__x0)   int& _iegen_5_iegen_4_iegen_3prev = _iegen_5_iegen_4Spline.accel; 
#define s30(__x0, i, __x2)   if(_iegen_5_iegen_4_iegen_3x >= _iegen_5_iegen_4_iegen_3x_vals[i] && _iegen_5_iegen_4_iegen_3x <= _iegen_5_iegen_4_iegen_3x_vals[i+1]) _iegen_5_iegen_4_iegen_3prev = i; 
#define s31(__x0)   int _iegen_5_iegen_4k = _iegen_5_iegen_4_iegen_3prev; 
#define s32(__x0)   double _iegen_5_iegen_4result = 0.0; 
#define s33(__x0)   if(_iegen_5_iegen_4k < _iegen_5_iegen_4Spline.length) { double _iegen_5_iegen_4X = (_iegen_5_iegen_4x - _iegen_5_iegen_4Spline.x_vals[_iegen_5_iegen_4k])/(_iegen_5_iegen_4Spline.x_vals[_iegen_5_iegen_4k+1] - _iegen_5_iegen_4Spline.x_vals[_iegen_5_iegen_4k]); double _iegen_5_iegen_4A = _iegen_5_iegen_4Spline.slopes[_iegen_5_iegen_4k] * (_iegen_5_iegen_4Spline.x_vals[_iegen_5_iegen_4k+1] - _iegen_5_iegen_4Spline.x_vals[_iegen_5_iegen_4k]) - (_iegen_5_iegen_4Spline.f_vals[_iegen_5_iegen_4k+1] - _iegen_5_iegen_4Spline.f_vals[_iegen_5_iegen_4k]); double _iegen_5_iegen_4B = -_iegen_5_iegen_4Spline.slopes[_iegen_5_iegen_4k+1] * (_iegen_5_iegen_4Spline.x_vals[_iegen_5_iegen_4k+1] - _iegen_5_iegen_4Spline.x_vals[_iegen_5_iegen_4k]) + (_iegen_5_iegen_4Spline.f_vals[_iegen_5_iegen_4k+1] - _iegen_5_iegen_4Spline.f_vals[_iegen_5_iegen_4k]); _iegen_5_iegen_4result = (1.0 - _iegen_5_iegen_4X) * _iegen_5_iegen_4Spline.f_vals[_iegen_5_iegen_4k] + _iegen_5_iegen_4X * _iegen_5_iegen_4Spline.f_vals[_iegen_5_iegen_4k+1] + _iegen_5_iegen_4X * (1.0 - _iegen_5_iegen_4X) * (_iegen_5_iegen_4A * (1.0 - _iegen_5_iegen_4X ) + _iegen_5_iegen_4B * _iegen_5_iegen_4X);} 
#define s34(__x0)   sources.v = _iegen_5_iegen_4result; 
#define s35(__x0)   double _iegen_8r = r; 
#define s36(__x0)   double _iegen_8theta = theta; 
#define s37(__x0)   double _iegen_8phi = phi; 
#define s38(__x0)   NaturalCubicSpline_1D & _iegen_8Windu_Spline = spl.Windu_Spline; 
#define s39(__x0)   double _iegen_8r_eval = min(_iegen_8r, r_max); _iegen_8r_eval = max(_iegen_8r_eval, r_min) 
#define s40(__x0)   double _iegen_8_iegen_7x = _iegen_8r_eval; 
#define s41(__x0)   struct NaturalCubicSpline_1D & _iegen_8_iegen_7Spline = _iegen_8Windu_Spline; 
#define s42(__x0)   double _iegen_8_iegen_7_iegen_6x = _iegen_8_iegen_7x; 
#define s43(__x0)   double* _iegen_8_iegen_7_iegen_6x_vals = _iegen_8_iegen_7Spline.x_vals; 
#define s44(__x0)   int _iegen_8_iegen_7_iegen_6length = _iegen_8_iegen_7Spline.length; 
#define s45(__x0)   int& _iegen_8_iegen_7_iegen_6prev = _iegen_8_iegen_7Spline.accel; 
#define s46(__x0, i, __x2)   if(_iegen_8_iegen_7_iegen_6x >= _iegen_8_iegen_7_iegen_6x_vals[i] && _iegen_8_iegen_7_iegen_6x <= _iegen_8_iegen_7_iegen_6x_vals[i+1]) _iegen_8_iegen_7_iegen_6prev = i; 
#define s47(__x0)   int _iegen_8_iegen_7k = _iegen_8_iegen_7_iegen_6prev; 
#define s48(__x0)   double _iegen_8_iegen_7result = 0.0; 
#define s49(__x0)   if(_iegen_8_iegen_7k < _iegen_8_iegen_7Spline.length) { double _iegen_8_iegen_7X = (_iegen_8_iegen_7x - _iegen_8_iegen_7Spline.x_vals[_iegen_8_iegen_7k])/(_iegen_8_iegen_7Spline.x_vals[_iegen_8_iegen_7k+1] - _iegen_8_iegen_7Spline.x_vals[_iegen_8_iegen_7k]); double _iegen_8_iegen_7A = _iegen_8_iegen_7Spline.slopes[_iegen_8_iegen_7k] * (_iegen_8_iegen_7Spline.x_vals[_iegen_8_iegen_7k+1] - _iegen_8_iegen_7Spline.x_vals[_iegen_8_iegen_7k]) - (_iegen_8_iegen_7Spline.f_vals[_iegen_8_iegen_7k+1] - _iegen_8_iegen_7Spline.f_vals[_iegen_8_iegen_7k]); double _iegen_8_iegen_7B = -_iegen_8_iegen_7Spline.slopes[_iegen_8_iegen_7k+1] * (_iegen_8_iegen_7Spline.x_vals[_iegen_8_iegen_7k+1] - _iegen_8_iegen_7Spline.x_vals[_iegen_8_iegen_7k]) + (_iegen_8_iegen_7Spline.f_vals[_iegen_8_iegen_7k+1] - _iegen_8_iegen_7Spline.f_vals[_iegen_8_iegen_7k]); _iegen_8_iegen_7result = (1.0 - _iegen_8_iegen_7X) * _iegen_8_iegen_7Spline.f_vals[_iegen_8_iegen_7k] + _iegen_8_iegen_7X * _iegen_8_iegen_7Spline.f_vals[_iegen_8_iegen_7k+1] + _iegen_8_iegen_7X * (1.0 - _iegen_8_iegen_7X) * (_iegen_8_iegen_7A * (1.0 - _iegen_8_iegen_7X ) + _iegen_8_iegen_7B * _iegen_8_iegen_7X);} 
#define s50(__x0)   sources.u = _iegen_8_iegen_7result; 


//t1 = 0; 
unsigned int t2 = 0; 
//t3 = 0; 

s0(0);
s1(1);
s2(2);
s3(3);
s4(4);
s5(5);
s6(6);
s7(7);
s8(8);
s9(9);
s10(10);
s11(11);
for(t2 = 0; t2 <= _iegen_2_iegen_1_iegen_0length-1; t2++) {
  s12(12,t2,0);
}
s13(13);
s14(14);
s15(15);
s16(16);
s17(17,0,0);
s18(18,0,0);
s19(19);
s20(20);
s21(21);
s22(22);
s23(23);
s24(24);
s25(25);
s26(26);
s27(27);
s28(28);
s29(29);
for(t2 = 0; t2 <= _iegen_5_iegen_4_iegen_3length-1; t2++) {
  s30(30,t2,0);
}
s31(31);
s32(32);
s33(33);
s34(34);
s35(35);
s36(36);
s37(37);
s38(38);
s39(39);
s40(40);
s41(41);
s42(42);
s43(43);
s44(44);
s45(45);
for(t2 = 0; t2 <= _iegen_8_iegen_7_iegen_6length-1; t2++) {
  s46(46,t2,0);
}
s47(47);
s48(48);
s49(49);
s50(50);

#undef s0
#undef s1
#undef s2
#undef s3
#undef s4
#undef s5
#undef s6
#undef s7
#undef s8
#undef s9
#undef s10
#undef s11
#undef s12
#undef s13
#undef s14
#undef s15
#undef s16
#undef s17
#undef s18
#undef s19
#undef s20
#undef s21
#undef s22
#undef s23
#undef s24
#undef s25
#undef s26
#undef s27
#undef s28
#undef s29
#undef s30
#undef s31
#undef s32
#undef s33
#undef s34
#undef s35
#undef s36
#undef s37
#undef s38
#undef s39
#undef s40
#undef s41
#undef s42
#undef s43
#undef s44
#undef s45
#undef s46
#undef s47
#undef s48
#undef s49
#undef s50
