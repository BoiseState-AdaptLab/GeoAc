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
#undef s51
#undef s52
#undef s53
#undef s54
#undef s55
#undef s56
#undef s57
#undef s58
#undef s59
#undef s60
#undef s61
#undef s62
#undef s63
#undef s64
#undef s65
#undef s66
#undef s67
#undef s68
#undef s69
#undef s70
#undef s71
#undef s72
#undef s73
#undef s74
#undef s75
#undef s76
#undef s77
#undef s78
#undef s79
#undef s80
#undef s81
#undef s82
#undef s83
#undef s84
#undef s85
#undef s86
#undef s87
#undef s88
#undef s89
#undef s90
#undef s91
#undef s92
#undef s93
#undef s94
#undef s95
#undef s96
#undef s97
#undef s98
#undef s99
#undef s100
#undef s101
#undef s102
#undef s103
#undef s104
#undef s105
#undef s106
#undef s107
#undef s108
#undef s109
#undef s110
#undef s111
#undef s112
#undef s113
#undef s114
#undef s115
#undef s116
#undef s117
#undef s118
#undef s119
#undef s120
#undef s121
#undef s122
#undef s123
#undef s124
#undef s125
#undef s126
#undef s127
#undef s128
#undef s129
#undef s130
#undef s131
#undef s132
#undef s133
#undef s134
#undef s135
#undef s136
#undef s137
#undef s138
#undef s139
#undef s140
#undef s141
#undef s142
#undef s143
#undef s144
#undef s145
#undef s146
#undef s147
#undef s148
#undef s149
#undef s150
#undef s151
#undef s152
#undef s153
#undef s154
#undef s155
#undef s156
#undef s157
#undef s158
#undef s159
#undef s160
#undef s161
#undef s162
#undef s163
#undef s164
#undef s165
#undef s166
#undef s167
#undef s168
#undef s169
#undef s170
#undef s171
#undef s172
#undef s173
#undef s174
#undef s175
#undef s176
#undef s177
#undef s178
#undef s179
#undef s180
#undef s181
#undef s182
#undef s183
#undef s184
#undef s185
#undef s186
#undef s187
#undef s188
#undef s189
#undef s190
#undef s191
#undef s192
#undef s193
#undef s194
#undef s195
#undef s196
#undef s197
#undef s198
#undef s199
#undef s200
#undef s201
#undef s202
#undef s203
#undef s204
#undef s205
#undef s206
#undef s207
#undef s208
#undef s209
#undef s210
#undef s211
#undef s212
#undef s213
#undef s214
#undef s215
#undef s216
#undef s217
#undef s218
#undef s219
#undef s220
#undef s221
#undef s222
#undef s223
#undef s224
#undef s225
#undef s226
#undef s227
#undef s228
#undef s229
#undef s230
#undef s231
#undef s232
#undef s233
#undef s234
#undef s235
#undef s236
#undef s237
#undef s238
#undef s239
#undef s240
#undef s241
#undef s242
#undef s243
#undef s244
#undef s245
#undef s246
#undef s247
#undef s248
#undef s249
#undef s250
#undef s251
#undef s252
#undef s253
#undef s254
#undef s255
#undef s256
#undef s257
#undef s258
#undef s259
#undef s260
#undef s261
#undef s262
#undef s263
#undef s264
#undef s265
#undef s266
#undef s267
#undef s268
#undef s269
#undef s270
#undef s271
#undef s272
#undef s273
#undef s274
#undef s275
#undef s276
#undef s277
#undef s278
#undef s279
#undef s280
#undef s281
#undef s282
#undef s283
#undef s284
#undef s285
#undef s286
#undef s287
#undef s288
#undef s289
#undef s290
#undef s291
#undef s292
#undef s293
#undef s294
#undef s295
#undef s296
#undef s297
#undef s298
#undef s299
#undef s300
#undef s301
#undef s302
#undef s303
#undef s304
#undef s305
#undef s306
#undef s307
#undef s308
#undef s309
#define s0(__x0)   double r = current_values[0], theta=current_values[1], phi=current_values[2]; 
#define s1(__x0)   double nu[3] = {current_values[3], current_values[4], current_values[5]}; 
#define s2(__x0)   double _iegen_2r = r; 
#define s3(__x0)   double _iegen_2theta = theta; 
#define s4(__x0)   double _iegen_2phi = phi; 
#define s5(__x0)   NaturalCubicSpline_1D & _iegen_2Temp_Spline = spl.Temp_Spline; 
#define s6(__x0)   double _iegen_2r_eval = min(_iegen_2r, r_max); 
#define s7(__x0)   _iegen_2r_eval = max(_iegen_2r_eval, r_min); 
#define s8(__x0)   double _iegen_2_iegen_1x = _iegen_2r_eval; 
#define s9(__x0)   struct NaturalCubicSpline_1D & _iegen_2_iegen_1Spline = _iegen_2Temp_Spline; 
#define s10(__x0)   double _iegen_2_iegen_1_iegen_0x = _iegen_2_iegen_1x; 
#define s11(__x0)   double* _iegen_2_iegen_1_iegen_0x_vals = _iegen_2_iegen_1Spline.x_vals; 
#define s12(__x0)   int _iegen_2_iegen_1_iegen_0length = _iegen_2_iegen_1Spline.length; 
#define s13(__x0)   int& _iegen_2_iegen_1_iegen_0prev = _iegen_2_iegen_1Spline.accel; 
#define s14(__x0, i, __x2)   if(_iegen_2_iegen_1_iegen_0x >= _iegen_2_iegen_1_iegen_0x_vals[i] && _iegen_2_iegen_1_iegen_0x <= _iegen_2_iegen_1_iegen_0x_vals[i+1]) _iegen_2_iegen_1_iegen_0prev = i; 
#define s15(__x0)   int _iegen_2_iegen_1k = _iegen_2_iegen_1_iegen_0prev; 
#define s16(__x0)   double _iegen_2_iegen_1result = 0.0; 
#define s17(__x0)   if(_iegen_2_iegen_1k < _iegen_2_iegen_1Spline.length) { double _iegen_2_iegen_1X = (_iegen_2_iegen_1x - _iegen_2_iegen_1Spline.x_vals[_iegen_2_iegen_1k])/(_iegen_2_iegen_1Spline.x_vals[_iegen_2_iegen_1k+1] - _iegen_2_iegen_1Spline.x_vals[_iegen_2_iegen_1k]); double _iegen_2_iegen_1A = _iegen_2_iegen_1Spline.slopes[_iegen_2_iegen_1k] * (_iegen_2_iegen_1Spline.x_vals[_iegen_2_iegen_1k+1] - _iegen_2_iegen_1Spline.x_vals[_iegen_2_iegen_1k]) - (_iegen_2_iegen_1Spline.f_vals[_iegen_2_iegen_1k+1] - _iegen_2_iegen_1Spline.f_vals[_iegen_2_iegen_1k]); double _iegen_2_iegen_1B = -_iegen_2_iegen_1Spline.slopes[_iegen_2_iegen_1k+1] * (_iegen_2_iegen_1Spline.x_vals[_iegen_2_iegen_1k+1] - _iegen_2_iegen_1Spline.x_vals[_iegen_2_iegen_1k]) + (_iegen_2_iegen_1Spline.f_vals[_iegen_2_iegen_1k+1] - _iegen_2_iegen_1Spline.f_vals[_iegen_2_iegen_1k]); _iegen_2_iegen_1result = (1.0 - _iegen_2_iegen_1X) * _iegen_2_iegen_1Spline.f_vals[_iegen_2_iegen_1k] + _iegen_2_iegen_1X * _iegen_2_iegen_1Spline.f_vals[_iegen_2_iegen_1k+1] + _iegen_2_iegen_1X * (1.0 - _iegen_2_iegen_1X) * (_iegen_2_iegen_1A * (1.0 - _iegen_2_iegen_1X ) + _iegen_2_iegen_1B * _iegen_2_iegen_1X);} 
#define s18(__x0)   double _iegen_2c_result = sqrt(gamR * _iegen_2_iegen_1result); 
#define s19(__x0)   sources.c = _iegen_2c_result; 
#define s20(__x0)   sources.w = 0; 
#define s21(__x0)   double _iegen_5r = r; 
#define s22(__x0)   double _iegen_5theta = theta; 
#define s23(__x0)   double _iegen_5phi = phi; 
#define s24(__x0)   NaturalCubicSpline_1D & _iegen_5Windv_Spline = spl.Windv_Spline; 
#define s25(__x0)   double _iegen_5r_eval = min(_iegen_5r, r_max); _iegen_5r_eval = max(_iegen_5r_eval, r_min) 
#define s26(__x0)   double _iegen_5_iegen_4x = _iegen_5r_eval; 
#define s27(__x0)   struct NaturalCubicSpline_1D & _iegen_5_iegen_4Spline = _iegen_5Windv_Spline; 
#define s28(__x0)   double _iegen_5_iegen_4_iegen_3x = _iegen_5_iegen_4x; 
#define s29(__x0)   double* _iegen_5_iegen_4_iegen_3x_vals = _iegen_5_iegen_4Spline.x_vals; 
#define s30(__x0)   int _iegen_5_iegen_4_iegen_3length = _iegen_5_iegen_4Spline.length; 
#define s31(__x0)   int& _iegen_5_iegen_4_iegen_3prev = _iegen_5_iegen_4Spline.accel; 
#define s32(__x0, i, __x2)   if(_iegen_5_iegen_4_iegen_3x >= _iegen_5_iegen_4_iegen_3x_vals[i] && _iegen_5_iegen_4_iegen_3x <= _iegen_5_iegen_4_iegen_3x_vals[i+1]) _iegen_5_iegen_4_iegen_3prev = i; 
#define s33(__x0)   int _iegen_5_iegen_4k = _iegen_5_iegen_4_iegen_3prev; 
#define s34(__x0)   double _iegen_5_iegen_4result = 0.0; 
#define s35(__x0)   if(_iegen_5_iegen_4k < _iegen_5_iegen_4Spline.length) { double _iegen_5_iegen_4X = (_iegen_5_iegen_4x - _iegen_5_iegen_4Spline.x_vals[_iegen_5_iegen_4k])/(_iegen_5_iegen_4Spline.x_vals[_iegen_5_iegen_4k+1] - _iegen_5_iegen_4Spline.x_vals[_iegen_5_iegen_4k]); double _iegen_5_iegen_4A = _iegen_5_iegen_4Spline.slopes[_iegen_5_iegen_4k] * (_iegen_5_iegen_4Spline.x_vals[_iegen_5_iegen_4k+1] - _iegen_5_iegen_4Spline.x_vals[_iegen_5_iegen_4k]) - (_iegen_5_iegen_4Spline.f_vals[_iegen_5_iegen_4k+1] - _iegen_5_iegen_4Spline.f_vals[_iegen_5_iegen_4k]); double _iegen_5_iegen_4B = -_iegen_5_iegen_4Spline.slopes[_iegen_5_iegen_4k+1] * (_iegen_5_iegen_4Spline.x_vals[_iegen_5_iegen_4k+1] - _iegen_5_iegen_4Spline.x_vals[_iegen_5_iegen_4k]) + (_iegen_5_iegen_4Spline.f_vals[_iegen_5_iegen_4k+1] - _iegen_5_iegen_4Spline.f_vals[_iegen_5_iegen_4k]); _iegen_5_iegen_4result = (1.0 - _iegen_5_iegen_4X) * _iegen_5_iegen_4Spline.f_vals[_iegen_5_iegen_4k] + _iegen_5_iegen_4X * _iegen_5_iegen_4Spline.f_vals[_iegen_5_iegen_4k+1] + _iegen_5_iegen_4X * (1.0 - _iegen_5_iegen_4X) * (_iegen_5_iegen_4A * (1.0 - _iegen_5_iegen_4X ) + _iegen_5_iegen_4B * _iegen_5_iegen_4X);} 
#define s36(__x0)   double _iegen_5v_return =_iegen_5_iegen_4result; 
#define s37(__x0)   sources.v = _iegen_5v_return; 
#define s38(__x0)   double _iegen_8r = r; 
#define s39(__x0)   double _iegen_8theta = theta; 
#define s40(__x0)   double _iegen_8phi = phi; 
#define s41(__x0)   NaturalCubicSpline_1D & _iegen_8Windu_Spline = spl.Windu_Spline; 
#define s42(__x0)   double _iegen_8r_eval = min(_iegen_8r, r_max); _iegen_8r_eval = max(_iegen_8r_eval, r_min) 
#define s43(__x0)   double _iegen_8_iegen_7x = _iegen_8r_eval; 
#define s44(__x0)   struct NaturalCubicSpline_1D & _iegen_8_iegen_7Spline = _iegen_8Windu_Spline; 
#define s45(__x0)   double _iegen_8_iegen_7_iegen_6x = _iegen_8_iegen_7x; 
#define s46(__x0)   double* _iegen_8_iegen_7_iegen_6x_vals = _iegen_8_iegen_7Spline.x_vals; 
#define s47(__x0)   int _iegen_8_iegen_7_iegen_6length = _iegen_8_iegen_7Spline.length; 
#define s48(__x0)   int& _iegen_8_iegen_7_iegen_6prev = _iegen_8_iegen_7Spline.accel; 
#define s49(__x0, i, __x2)   if(_iegen_8_iegen_7_iegen_6x >= _iegen_8_iegen_7_iegen_6x_vals[i] && _iegen_8_iegen_7_iegen_6x <= _iegen_8_iegen_7_iegen_6x_vals[i+1]) _iegen_8_iegen_7_iegen_6prev = i; 
#define s50(__x0)   int _iegen_8_iegen_7k = _iegen_8_iegen_7_iegen_6prev; 
#define s51(__x0)   double _iegen_8_iegen_7result = 0.0; 
#define s52(__x0)   if(_iegen_8_iegen_7k < _iegen_8_iegen_7Spline.length) { double _iegen_8_iegen_7X = (_iegen_8_iegen_7x - _iegen_8_iegen_7Spline.x_vals[_iegen_8_iegen_7k])/(_iegen_8_iegen_7Spline.x_vals[_iegen_8_iegen_7k+1] - _iegen_8_iegen_7Spline.x_vals[_iegen_8_iegen_7k]); double _iegen_8_iegen_7A = _iegen_8_iegen_7Spline.slopes[_iegen_8_iegen_7k] * (_iegen_8_iegen_7Spline.x_vals[_iegen_8_iegen_7k+1] - _iegen_8_iegen_7Spline.x_vals[_iegen_8_iegen_7k]) - (_iegen_8_iegen_7Spline.f_vals[_iegen_8_iegen_7k+1] - _iegen_8_iegen_7Spline.f_vals[_iegen_8_iegen_7k]); double _iegen_8_iegen_7B = -_iegen_8_iegen_7Spline.slopes[_iegen_8_iegen_7k+1] * (_iegen_8_iegen_7Spline.x_vals[_iegen_8_iegen_7k+1] - _iegen_8_iegen_7Spline.x_vals[_iegen_8_iegen_7k]) + (_iegen_8_iegen_7Spline.f_vals[_iegen_8_iegen_7k+1] - _iegen_8_iegen_7Spline.f_vals[_iegen_8_iegen_7k]); _iegen_8_iegen_7result = (1.0 - _iegen_8_iegen_7X) * _iegen_8_iegen_7Spline.f_vals[_iegen_8_iegen_7k] + _iegen_8_iegen_7X * _iegen_8_iegen_7Spline.f_vals[_iegen_8_iegen_7k+1] + _iegen_8_iegen_7X * (1.0 - _iegen_8_iegen_7X) * (_iegen_8_iegen_7A * (1.0 - _iegen_8_iegen_7X ) + _iegen_8_iegen_7B * _iegen_8_iegen_7X);} 
#define s53(__x0)   sources.u = _iegen_8_iegen_7result; 
#define s54(__x0)   double _iegen_14r = r; 
#define s55(__x0)   double _iegen_14theta = theta; 
#define s56(__x0)   double _iegen_14phi = phi; 
#define s57(__x0)   int _iegen_14n = 0; 
#define s58(__x0)   NaturalCubicSpline_1D & _iegen_14Temp_Spline = spl.Temp_Spline; 
#define s59(__x0)   double _iegen_14r_eval = min(_iegen_14r, r_max); _iegen_14r_eval = max(_iegen_14r_eval, r_min); 
#define s60(__x0)   double _iegen_14c_diff_return = 0.0 
#define s61(__x0)   double _iegen_14_iegen_11r = _iegen_14r; 
#define s62(__x0)   double _iegen_14_iegen_11theta = _iegen_14theta; 
#define s63(__x0)   double _iegen_14_iegen_11phi = _iegen_14phi; 
#define s64(__x0)   NaturalCubicSpline_1D & _iegen_14_iegen_11Temp_Spline = _iegen_14Temp_Spline; 
#define s65(__x0)   double _iegen_14_iegen_11r_eval = min(_iegen_14_iegen_11r, r_max); 
#define s66(__x0)   _iegen_14_iegen_11r_eval = max(_iegen_14_iegen_11r_eval, r_min); 
#define s67(__x0)   double _iegen_14_iegen_11_iegen_10x = _iegen_14_iegen_11r_eval; 
#define s68(__x0)   struct NaturalCubicSpline_1D & _iegen_14_iegen_11_iegen_10Spline = _iegen_14_iegen_11Temp_Spline; 
#define s69(__x0)   double _iegen_14_iegen_11_iegen_10_iegen_9x = _iegen_14_iegen_11_iegen_10x; 
#define s70(__x0)   double* _iegen_14_iegen_11_iegen_10_iegen_9x_vals = _iegen_14_iegen_11_iegen_10Spline.x_vals; 
#define s71(__x0)   int _iegen_14_iegen_11_iegen_10_iegen_9length = _iegen_14_iegen_11_iegen_10Spline.length; 
#define s72(__x0)   int& _iegen_14_iegen_11_iegen_10_iegen_9prev = _iegen_14_iegen_11_iegen_10Spline.accel; 
#define s73(__x0, i, __x2)   if(_iegen_14_iegen_11_iegen_10_iegen_9x >= _iegen_14_iegen_11_iegen_10_iegen_9x_vals[i] && _iegen_14_iegen_11_iegen_10_iegen_9x <= _iegen_14_iegen_11_iegen_10_iegen_9x_vals[i+1]) _iegen_14_iegen_11_iegen_10_iegen_9prev = i; 
#define s74(__x0)   int _iegen_14_iegen_11_iegen_10k = _iegen_14_iegen_11_iegen_10_iegen_9prev; 
#define s75(__x0)   double _iegen_14_iegen_11_iegen_10result = 0.0; 
#define s76(__x0)   if(_iegen_14_iegen_11_iegen_10k < _iegen_14_iegen_11_iegen_10Spline.length) { double _iegen_14_iegen_11_iegen_10X = (_iegen_14_iegen_11_iegen_10x - _iegen_14_iegen_11_iegen_10Spline.x_vals[_iegen_14_iegen_11_iegen_10k])/(_iegen_14_iegen_11_iegen_10Spline.x_vals[_iegen_14_iegen_11_iegen_10k+1] - _iegen_14_iegen_11_iegen_10Spline.x_vals[_iegen_14_iegen_11_iegen_10k]); double _iegen_14_iegen_11_iegen_10A = _iegen_14_iegen_11_iegen_10Spline.slopes[_iegen_14_iegen_11_iegen_10k] * (_iegen_14_iegen_11_iegen_10Spline.x_vals[_iegen_14_iegen_11_iegen_10k+1] - _iegen_14_iegen_11_iegen_10Spline.x_vals[_iegen_14_iegen_11_iegen_10k]) - (_iegen_14_iegen_11_iegen_10Spline.f_vals[_iegen_14_iegen_11_iegen_10k+1] - _iegen_14_iegen_11_iegen_10Spline.f_vals[_iegen_14_iegen_11_iegen_10k]); double _iegen_14_iegen_11_iegen_10B = -_iegen_14_iegen_11_iegen_10Spline.slopes[_iegen_14_iegen_11_iegen_10k+1] * (_iegen_14_iegen_11_iegen_10Spline.x_vals[_iegen_14_iegen_11_iegen_10k+1] - _iegen_14_iegen_11_iegen_10Spline.x_vals[_iegen_14_iegen_11_iegen_10k]) + (_iegen_14_iegen_11_iegen_10Spline.f_vals[_iegen_14_iegen_11_iegen_10k+1] - _iegen_14_iegen_11_iegen_10Spline.f_vals[_iegen_14_iegen_11_iegen_10k]); _iegen_14_iegen_11_iegen_10result = (1.0 - _iegen_14_iegen_11_iegen_10X) * _iegen_14_iegen_11_iegen_10Spline.f_vals[_iegen_14_iegen_11_iegen_10k] + _iegen_14_iegen_11_iegen_10X * _iegen_14_iegen_11_iegen_10Spline.f_vals[_iegen_14_iegen_11_iegen_10k+1] + _iegen_14_iegen_11_iegen_10X * (1.0 - _iegen_14_iegen_11_iegen_10X) * (_iegen_14_iegen_11_iegen_10A * (1.0 - _iegen_14_iegen_11_iegen_10X ) + _iegen_14_iegen_11_iegen_10B * _iegen_14_iegen_11_iegen_10X);} 
#define s77(__x0)   double _iegen_14_iegen_11c_result = sqrt(gamR * _iegen_14_iegen_11_iegen_10result); 
#define s78(__x0)   double _iegen_14c_return = _iegen_14_iegen_11c_result; 
#define s79(__x0)   double _iegen_14_iegen_13x = _iegen_14r_eval; 
#define s80(__x0)   NaturalCubicSpline_1D & _iegen_14_iegen_13Spline = _iegen_14Temp_Spline; 
#define s81(__x0)   double _iegen_14_iegen_13_iegen_12x = _iegen_14_iegen_13x; 
#define s82(__x0)   double* _iegen_14_iegen_13_iegen_12x_vals = _iegen_14_iegen_13Spline.x_vals; 
#define s83(__x0)   int _iegen_14_iegen_13_iegen_12length = _iegen_14_iegen_13Spline.length; 
#define s84(__x0)   int& _iegen_14_iegen_13_iegen_12prev = _iegen_14_iegen_13Spline.accel; 
#define s85(__x0, i, __x2)   if(_iegen_14_iegen_13_iegen_12x >= _iegen_14_iegen_13_iegen_12x_vals[i] && _iegen_14_iegen_13_iegen_12x <= _iegen_14_iegen_13_iegen_12x_vals[i+1]) _iegen_14_iegen_13_iegen_12prev = i; 
#define s86(__x0)   int _iegen_14_iegen_13k = _iegen_14_iegen_13_iegen_12prev; 
#define s87(__x0)   double _iegen_14_iegen_13eval_spline_df_return = 0.0; 
#define s88(__x0)   if(_iegen_14_iegen_13k < _iegen_14_iegen_13Spline.length){double _iegen_14_iegen_13X = (_iegen_14_iegen_13x - _iegen_14_iegen_13Spline.x_vals[_iegen_14_iegen_13k])/(_iegen_14_iegen_13Spline.x_vals[_iegen_14_iegen_13k+1] - _iegen_14_iegen_13Spline.x_vals[_iegen_14_iegen_13k]); double _iegen_14_iegen_13A = _iegen_14_iegen_13Spline.slopes[_iegen_14_iegen_13k] * (_iegen_14_iegen_13Spline.x_vals[_iegen_14_iegen_13k+1] -_iegen_14_iegen_13Spline.x_vals[_iegen_14_iegen_13k]) - (_iegen_14_iegen_13Spline.f_vals[_iegen_14_iegen_13k+1] - _iegen_14_iegen_13Spline.f_vals[_iegen_14_iegen_13k]); double _iegen_14_iegen_13B = -_iegen_14_iegen_13Spline.slopes[_iegen_14_iegen_13k+1] * (_iegen_14_iegen_13Spline.x_vals[_iegen_14_iegen_13k+1] - _iegen_14_iegen_13Spline.x_vals[_iegen_14_iegen_13k]) + (_iegen_14_iegen_13Spline.f_vals[_iegen_14_iegen_13k+1] - _iegen_14_iegen_13Spline.f_vals[_iegen_14_iegen_13k]); _iegen_14_iegen_13eval_spline_df_return = (_iegen_14_iegen_13Spline.f_vals[_iegen_14_iegen_13k+1] - _iegen_14_iegen_13Spline.f_vals[_iegen_14_iegen_13k])/(_iegen_14_iegen_13Spline.x_vals[_iegen_14_iegen_13k+1] - _iegen_14_iegen_13Spline.x_vals[_iegen_14_iegen_13k]) + (1.0 - 2.0 * _iegen_14_iegen_13X) * (_iegen_14_iegen_13A * (1.0 - _iegen_14_iegen_13X) + _iegen_14_iegen_13B * _iegen_14_iegen_13X)/(_iegen_14_iegen_13Spline.x_vals[_iegen_14_iegen_13k+1] - _iegen_14_iegen_13Spline.x_vals[_iegen_14_iegen_13k])+ _iegen_14_iegen_13X * (1.0 - _iegen_14_iegen_13X) * (_iegen_14_iegen_13B - _iegen_14_iegen_13A)/(_iegen_14_iegen_13Spline.x_vals[_iegen_14_iegen_13k+1] - _iegen_14_iegen_13Spline.x_vals[_iegen_14_iegen_13k]);} 
#define s89(__x0)   double _iegen_14eval_spline_df_return = _iegen_14_iegen_13eval_spline_df_return; 
#define s90(__x0)   if(_iegen_14n==0){_iegen_14c_diff_return = gamR / (2.0 * _iegen_14c_return) * _iegen_14eval_spline_df_return;} 
#define s91(__x0)   sources.dc[0] = _iegen_14c_diff_return; 
#define s92(__x0)   sources.dw[0] = 0; 
#define s93(__x0)   double _iegen_17r = r; 
#define s94(__x0)   double _iegen_17theta = theta; 
#define s95(__x0)   double _iegen_17phi = phi; 
#define s96(__x0)   int _iegen_17n = 0; 
#define s97(__x0)   NaturalCubicSpline_1D & _iegen_17Windv_Spline = spl.Windv_Spline; 
#define s98(__x0)   double _iegen_17r_eval = min(_iegen_17r, r_max); _iegen_17r_eval = max(_iegen_17r_eval, r_min); 
#define s99(__x0)   double _iegen_17v_diff_return = 0.0 
#define s100(__x0)   double _iegen_17_iegen_16x = _iegen_17r_eval; 
#define s101(__x0)   NaturalCubicSpline_1D & _iegen_17_iegen_16Spline = _iegen_17Windv_Spline; 
#define s102(__x0)   double _iegen_17_iegen_16_iegen_15x = _iegen_17_iegen_16x; 
#define s103(__x0)   double* _iegen_17_iegen_16_iegen_15x_vals = _iegen_17_iegen_16Spline.x_vals; 
#define s104(__x0)   int _iegen_17_iegen_16_iegen_15length = _iegen_17_iegen_16Spline.length; 
#define s105(__x0)   int& _iegen_17_iegen_16_iegen_15prev = _iegen_17_iegen_16Spline.accel; 
#define s106(__x0, i, __x2)   if(_iegen_17_iegen_16_iegen_15x >= _iegen_17_iegen_16_iegen_15x_vals[i] && _iegen_17_iegen_16_iegen_15x <= _iegen_17_iegen_16_iegen_15x_vals[i+1]) _iegen_17_iegen_16_iegen_15prev = i; 
#define s107(__x0)   int _iegen_17_iegen_16k = _iegen_17_iegen_16_iegen_15prev; 
#define s108(__x0)   double _iegen_17_iegen_16eval_spline_df_return = 0.0; 
#define s109(__x0)   if(_iegen_17_iegen_16k < _iegen_17_iegen_16Spline.length){double _iegen_17_iegen_16X = (_iegen_17_iegen_16x - _iegen_17_iegen_16Spline.x_vals[_iegen_17_iegen_16k])/(_iegen_17_iegen_16Spline.x_vals[_iegen_17_iegen_16k+1] - _iegen_17_iegen_16Spline.x_vals[_iegen_17_iegen_16k]); double _iegen_17_iegen_16A = _iegen_17_iegen_16Spline.slopes[_iegen_17_iegen_16k] * (_iegen_17_iegen_16Spline.x_vals[_iegen_17_iegen_16k+1] -_iegen_17_iegen_16Spline.x_vals[_iegen_17_iegen_16k]) - (_iegen_17_iegen_16Spline.f_vals[_iegen_17_iegen_16k+1] - _iegen_17_iegen_16Spline.f_vals[_iegen_17_iegen_16k]); double _iegen_17_iegen_16B = -_iegen_17_iegen_16Spline.slopes[_iegen_17_iegen_16k+1] * (_iegen_17_iegen_16Spline.x_vals[_iegen_17_iegen_16k+1] - _iegen_17_iegen_16Spline.x_vals[_iegen_17_iegen_16k]) + (_iegen_17_iegen_16Spline.f_vals[_iegen_17_iegen_16k+1] - _iegen_17_iegen_16Spline.f_vals[_iegen_17_iegen_16k]); _iegen_17_iegen_16eval_spline_df_return = (_iegen_17_iegen_16Spline.f_vals[_iegen_17_iegen_16k+1] - _iegen_17_iegen_16Spline.f_vals[_iegen_17_iegen_16k])/(_iegen_17_iegen_16Spline.x_vals[_iegen_17_iegen_16k+1] - _iegen_17_iegen_16Spline.x_vals[_iegen_17_iegen_16k]) + (1.0 - 2.0 * _iegen_17_iegen_16X) * (_iegen_17_iegen_16A * (1.0 - _iegen_17_iegen_16X) + _iegen_17_iegen_16B * _iegen_17_iegen_16X)/(_iegen_17_iegen_16Spline.x_vals[_iegen_17_iegen_16k+1] - _iegen_17_iegen_16Spline.x_vals[_iegen_17_iegen_16k])+ _iegen_17_iegen_16X * (1.0 - _iegen_17_iegen_16X) * (_iegen_17_iegen_16B - _iegen_17_iegen_16A)/(_iegen_17_iegen_16Spline.x_vals[_iegen_17_iegen_16k+1] - _iegen_17_iegen_16Spline.x_vals[_iegen_17_iegen_16k]);} 
#define s110(__x0)   double _iegen_17eval_Spline_df_return = _iegen_17_iegen_16eval_spline_df_return; 
#define s111(__x0)   if(_iegen_17n==0){_iegen_17v_diff_return = _iegen_17eval_Spline_df_return;} 
#define s112(__x0)   sources.dv[0] = _iegen_17v_diff_return; 
#define s113(__x0)   double _iegen_20r = r; 
#define s114(__x0)   double _iegen_20theta = theta; 
#define s115(__x0)   double _iegen_20phi = phi; 
#define s116(__x0)   int _iegen_20n = 0; 
#define s117(__x0)   NaturalCubicSpline_1D & _iegen_20Windu_Spline = spl.Windu_Spline; 
#define s118(__x0)   double _iegen_20r_eval = min(_iegen_20r, r_max); _iegen_20r_eval = max(_iegen_20r_eval, r_min); 
#define s119(__x0)   double _iegen_20u_diff_return = 0.0 
#define s120(__x0)   double _iegen_20_iegen_19x = _iegen_20r_eval; 
#define s121(__x0)   NaturalCubicSpline_1D & _iegen_20_iegen_19Spline = _iegen_20Windu_Spline; 
#define s122(__x0)   double _iegen_20_iegen_19_iegen_18x = _iegen_20_iegen_19x; 
#define s123(__x0)   double* _iegen_20_iegen_19_iegen_18x_vals = _iegen_20_iegen_19Spline.x_vals; 
#define s124(__x0)   int _iegen_20_iegen_19_iegen_18length = _iegen_20_iegen_19Spline.length; 
#define s125(__x0)   int& _iegen_20_iegen_19_iegen_18prev = _iegen_20_iegen_19Spline.accel; 
#define s126(__x0, i, __x2)   if(_iegen_20_iegen_19_iegen_18x >= _iegen_20_iegen_19_iegen_18x_vals[i] && _iegen_20_iegen_19_iegen_18x <= _iegen_20_iegen_19_iegen_18x_vals[i+1]) _iegen_20_iegen_19_iegen_18prev = i; 
#define s127(__x0)   int _iegen_20_iegen_19k = _iegen_20_iegen_19_iegen_18prev; 
#define s128(__x0)   double _iegen_20_iegen_19eval_spline_df_return = 0.0; 
#define s129(__x0)   if(_iegen_20_iegen_19k < _iegen_20_iegen_19Spline.length){double _iegen_20_iegen_19X = (_iegen_20_iegen_19x - _iegen_20_iegen_19Spline.x_vals[_iegen_20_iegen_19k])/(_iegen_20_iegen_19Spline.x_vals[_iegen_20_iegen_19k+1] - _iegen_20_iegen_19Spline.x_vals[_iegen_20_iegen_19k]); double _iegen_20_iegen_19A = _iegen_20_iegen_19Spline.slopes[_iegen_20_iegen_19k] * (_iegen_20_iegen_19Spline.x_vals[_iegen_20_iegen_19k+1] -_iegen_20_iegen_19Spline.x_vals[_iegen_20_iegen_19k]) - (_iegen_20_iegen_19Spline.f_vals[_iegen_20_iegen_19k+1] - _iegen_20_iegen_19Spline.f_vals[_iegen_20_iegen_19k]); double _iegen_20_iegen_19B = -_iegen_20_iegen_19Spline.slopes[_iegen_20_iegen_19k+1] * (_iegen_20_iegen_19Spline.x_vals[_iegen_20_iegen_19k+1] - _iegen_20_iegen_19Spline.x_vals[_iegen_20_iegen_19k]) + (_iegen_20_iegen_19Spline.f_vals[_iegen_20_iegen_19k+1] - _iegen_20_iegen_19Spline.f_vals[_iegen_20_iegen_19k]); _iegen_20_iegen_19eval_spline_df_return = (_iegen_20_iegen_19Spline.f_vals[_iegen_20_iegen_19k+1] - _iegen_20_iegen_19Spline.f_vals[_iegen_20_iegen_19k])/(_iegen_20_iegen_19Spline.x_vals[_iegen_20_iegen_19k+1] - _iegen_20_iegen_19Spline.x_vals[_iegen_20_iegen_19k]) + (1.0 - 2.0 * _iegen_20_iegen_19X) * (_iegen_20_iegen_19A * (1.0 - _iegen_20_iegen_19X) + _iegen_20_iegen_19B * _iegen_20_iegen_19X)/(_iegen_20_iegen_19Spline.x_vals[_iegen_20_iegen_19k+1] - _iegen_20_iegen_19Spline.x_vals[_iegen_20_iegen_19k])+ _iegen_20_iegen_19X * (1.0 - _iegen_20_iegen_19X) * (_iegen_20_iegen_19B - _iegen_20_iegen_19A)/(_iegen_20_iegen_19Spline.x_vals[_iegen_20_iegen_19k+1] - _iegen_20_iegen_19Spline.x_vals[_iegen_20_iegen_19k]);} 
#define s130(__x0)   double _iegen_20eval_Spline_df_return = _iegen_20_iegen_19eval_spline_df_return; 
#define s131(__x0)   if(_iegen_20n==0){_iegen_20u_diff_return = _iegen_20eval_Spline_df_return;} 
#define s132(__x0)   sources.du[0] = _iegen_20u_diff_return; 
#define s133(__x0)   double _iegen_21r = r; 
#define s134(__x0)   double _iegen_21theta = theta; 
#define s135(__x0)   double _iegen_21phi = phi; 
#define s136(__x0)   int _iegen_21n = 1; 
#define s137(__x0)   NaturalCubicSpline_1D & _iegen_21Temp_Spline = spl.Temp_Spline; 
#define s138(__x0)   double _iegen_21r_eval = min(_iegen_21r, r_max); _iegen_21r_eval = max(_iegen_21r_eval, r_min); 
#define s139(__x0)   double _iegen_21c_diff_return = 0.0 
#define s140(__x0)   double _iegen_21_iegen_11r = _iegen_21r; 
#define s141(__x0)   double _iegen_21_iegen_11theta = _iegen_21theta; 
#define s142(__x0)   double _iegen_21_iegen_11phi = _iegen_21phi; 
#define s143(__x0)   NaturalCubicSpline_1D & _iegen_21_iegen_11Temp_Spline = _iegen_21Temp_Spline; 
#define s144(__x0)   double _iegen_21_iegen_11r_eval = min(_iegen_21_iegen_11r, r_max); 
#define s145(__x0)   _iegen_21_iegen_11r_eval = max(_iegen_21_iegen_11r_eval, r_min); 
#define s146(__x0)   double _iegen_21_iegen_11_iegen_10x = _iegen_21_iegen_11r_eval; 
#define s147(__x0)   struct NaturalCubicSpline_1D & _iegen_21_iegen_11_iegen_10Spline = _iegen_21_iegen_11Temp_Spline; 
#define s148(__x0)   double _iegen_21_iegen_11_iegen_10_iegen_9x = _iegen_21_iegen_11_iegen_10x; 
#define s149(__x0)   double* _iegen_21_iegen_11_iegen_10_iegen_9x_vals = _iegen_21_iegen_11_iegen_10Spline.x_vals; 
#define s150(__x0)   int _iegen_21_iegen_11_iegen_10_iegen_9length = _iegen_21_iegen_11_iegen_10Spline.length; 
#define s151(__x0)   int& _iegen_21_iegen_11_iegen_10_iegen_9prev = _iegen_21_iegen_11_iegen_10Spline.accel; 
#define s152(__x0, i, __x2)   if(_iegen_21_iegen_11_iegen_10_iegen_9x >= _iegen_21_iegen_11_iegen_10_iegen_9x_vals[i] && _iegen_21_iegen_11_iegen_10_iegen_9x <= _iegen_21_iegen_11_iegen_10_iegen_9x_vals[i+1]) _iegen_21_iegen_11_iegen_10_iegen_9prev = i; 
#define s153(__x0)   int _iegen_21_iegen_11_iegen_10k = _iegen_21_iegen_11_iegen_10_iegen_9prev; 
#define s154(__x0)   double _iegen_21_iegen_11_iegen_10result = 0.0; 
#define s155(__x0)   if(_iegen_21_iegen_11_iegen_10k < _iegen_21_iegen_11_iegen_10Spline.length) { double _iegen_21_iegen_11_iegen_10X = (_iegen_21_iegen_11_iegen_10x - _iegen_21_iegen_11_iegen_10Spline.x_vals[_iegen_21_iegen_11_iegen_10k])/(_iegen_21_iegen_11_iegen_10Spline.x_vals[_iegen_21_iegen_11_iegen_10k+1] - _iegen_21_iegen_11_iegen_10Spline.x_vals[_iegen_21_iegen_11_iegen_10k]); double _iegen_21_iegen_11_iegen_10A = _iegen_21_iegen_11_iegen_10Spline.slopes[_iegen_21_iegen_11_iegen_10k] * (_iegen_21_iegen_11_iegen_10Spline.x_vals[_iegen_21_iegen_11_iegen_10k+1] - _iegen_21_iegen_11_iegen_10Spline.x_vals[_iegen_21_iegen_11_iegen_10k]) - (_iegen_21_iegen_11_iegen_10Spline.f_vals[_iegen_21_iegen_11_iegen_10k+1] - _iegen_21_iegen_11_iegen_10Spline.f_vals[_iegen_21_iegen_11_iegen_10k]); double _iegen_21_iegen_11_iegen_10B = -_iegen_21_iegen_11_iegen_10Spline.slopes[_iegen_21_iegen_11_iegen_10k+1] * (_iegen_21_iegen_11_iegen_10Spline.x_vals[_iegen_21_iegen_11_iegen_10k+1] - _iegen_21_iegen_11_iegen_10Spline.x_vals[_iegen_21_iegen_11_iegen_10k]) + (_iegen_21_iegen_11_iegen_10Spline.f_vals[_iegen_21_iegen_11_iegen_10k+1] - _iegen_21_iegen_11_iegen_10Spline.f_vals[_iegen_21_iegen_11_iegen_10k]); _iegen_21_iegen_11_iegen_10result = (1.0 - _iegen_21_iegen_11_iegen_10X) * _iegen_21_iegen_11_iegen_10Spline.f_vals[_iegen_21_iegen_11_iegen_10k] + _iegen_21_iegen_11_iegen_10X * _iegen_21_iegen_11_iegen_10Spline.f_vals[_iegen_21_iegen_11_iegen_10k+1] + _iegen_21_iegen_11_iegen_10X * (1.0 - _iegen_21_iegen_11_iegen_10X) * (_iegen_21_iegen_11_iegen_10A * (1.0 - _iegen_21_iegen_11_iegen_10X ) + _iegen_21_iegen_11_iegen_10B * _iegen_21_iegen_11_iegen_10X);} 
#define s156(__x0)   double _iegen_21_iegen_11c_result = sqrt(gamR * _iegen_21_iegen_11_iegen_10result); 
#define s157(__x0)   double _iegen_21c_return = _iegen_21_iegen_11c_result; 
#define s158(__x0)   double _iegen_21_iegen_13x = _iegen_21r_eval; 
#define s159(__x0)   NaturalCubicSpline_1D & _iegen_21_iegen_13Spline = _iegen_21Temp_Spline; 
#define s160(__x0)   double _iegen_21_iegen_13_iegen_12x = _iegen_21_iegen_13x; 
#define s161(__x0)   double* _iegen_21_iegen_13_iegen_12x_vals = _iegen_21_iegen_13Spline.x_vals; 
#define s162(__x0)   int _iegen_21_iegen_13_iegen_12length = _iegen_21_iegen_13Spline.length; 
#define s163(__x0)   int& _iegen_21_iegen_13_iegen_12prev = _iegen_21_iegen_13Spline.accel; 
#define s164(__x0, i, __x2)   if(_iegen_21_iegen_13_iegen_12x >= _iegen_21_iegen_13_iegen_12x_vals[i] && _iegen_21_iegen_13_iegen_12x <= _iegen_21_iegen_13_iegen_12x_vals[i+1]) _iegen_21_iegen_13_iegen_12prev = i; 
#define s165(__x0)   int _iegen_21_iegen_13k = _iegen_21_iegen_13_iegen_12prev; 
#define s166(__x0)   double _iegen_21_iegen_13eval_spline_df_return = 0.0; 
#define s167(__x0)   if(_iegen_21_iegen_13k < _iegen_21_iegen_13Spline.length){double _iegen_21_iegen_13X = (_iegen_21_iegen_13x - _iegen_21_iegen_13Spline.x_vals[_iegen_21_iegen_13k])/(_iegen_21_iegen_13Spline.x_vals[_iegen_21_iegen_13k+1] - _iegen_21_iegen_13Spline.x_vals[_iegen_21_iegen_13k]); double _iegen_21_iegen_13A = _iegen_21_iegen_13Spline.slopes[_iegen_21_iegen_13k] * (_iegen_21_iegen_13Spline.x_vals[_iegen_21_iegen_13k+1] -_iegen_21_iegen_13Spline.x_vals[_iegen_21_iegen_13k]) - (_iegen_21_iegen_13Spline.f_vals[_iegen_21_iegen_13k+1] - _iegen_21_iegen_13Spline.f_vals[_iegen_21_iegen_13k]); double _iegen_21_iegen_13B = -_iegen_21_iegen_13Spline.slopes[_iegen_21_iegen_13k+1] * (_iegen_21_iegen_13Spline.x_vals[_iegen_21_iegen_13k+1] - _iegen_21_iegen_13Spline.x_vals[_iegen_21_iegen_13k]) + (_iegen_21_iegen_13Spline.f_vals[_iegen_21_iegen_13k+1] - _iegen_21_iegen_13Spline.f_vals[_iegen_21_iegen_13k]); _iegen_21_iegen_13eval_spline_df_return = (_iegen_21_iegen_13Spline.f_vals[_iegen_21_iegen_13k+1] - _iegen_21_iegen_13Spline.f_vals[_iegen_21_iegen_13k])/(_iegen_21_iegen_13Spline.x_vals[_iegen_21_iegen_13k+1] - _iegen_21_iegen_13Spline.x_vals[_iegen_21_iegen_13k]) + (1.0 - 2.0 * _iegen_21_iegen_13X) * (_iegen_21_iegen_13A * (1.0 - _iegen_21_iegen_13X) + _iegen_21_iegen_13B * _iegen_21_iegen_13X)/(_iegen_21_iegen_13Spline.x_vals[_iegen_21_iegen_13k+1] - _iegen_21_iegen_13Spline.x_vals[_iegen_21_iegen_13k])+ _iegen_21_iegen_13X * (1.0 - _iegen_21_iegen_13X) * (_iegen_21_iegen_13B - _iegen_21_iegen_13A)/(_iegen_21_iegen_13Spline.x_vals[_iegen_21_iegen_13k+1] - _iegen_21_iegen_13Spline.x_vals[_iegen_21_iegen_13k]);} 
#define s168(__x0)   double _iegen_21eval_spline_df_return = _iegen_21_iegen_13eval_spline_df_return; 
#define s169(__x0)   if(_iegen_21n==0){_iegen_21c_diff_return = gamR / (2.0 * _iegen_21c_return) * _iegen_21eval_spline_df_return;} 
#define s170(__x0)   sources.dc[1] = _iegen_21c_diff_return; 
#define s171(__x0)   sources.dw[1] = 0; 
#define s172(__x0)   double _iegen_22r = r; 
#define s173(__x0)   double _iegen_22theta = theta; 
#define s174(__x0)   double _iegen_22phi = phi; 
#define s175(__x0)   int _iegen_22n = 1; 
#define s176(__x0)   NaturalCubicSpline_1D & _iegen_22Windv_Spline = spl.Windv_Spline; 
#define s177(__x0)   double _iegen_22r_eval = min(_iegen_22r, r_max); _iegen_22r_eval = max(_iegen_22r_eval, r_min); 
#define s178(__x0)   double _iegen_22v_diff_return = 0.0 
#define s179(__x0)   double _iegen_22_iegen_16x = _iegen_22r_eval; 
#define s180(__x0)   NaturalCubicSpline_1D & _iegen_22_iegen_16Spline = _iegen_22Windv_Spline; 
#define s181(__x0)   double _iegen_22_iegen_16_iegen_15x = _iegen_22_iegen_16x; 
#define s182(__x0)   double* _iegen_22_iegen_16_iegen_15x_vals = _iegen_22_iegen_16Spline.x_vals; 
#define s183(__x0)   int _iegen_22_iegen_16_iegen_15length = _iegen_22_iegen_16Spline.length; 
#define s184(__x0)   int& _iegen_22_iegen_16_iegen_15prev = _iegen_22_iegen_16Spline.accel; 
#define s185(__x0, i, __x2)   if(_iegen_22_iegen_16_iegen_15x >= _iegen_22_iegen_16_iegen_15x_vals[i] && _iegen_22_iegen_16_iegen_15x <= _iegen_22_iegen_16_iegen_15x_vals[i+1]) _iegen_22_iegen_16_iegen_15prev = i; 
#define s186(__x0)   int _iegen_22_iegen_16k = _iegen_22_iegen_16_iegen_15prev; 
#define s187(__x0)   double _iegen_22_iegen_16eval_spline_df_return = 0.0; 
#define s188(__x0)   if(_iegen_22_iegen_16k < _iegen_22_iegen_16Spline.length){double _iegen_22_iegen_16X = (_iegen_22_iegen_16x - _iegen_22_iegen_16Spline.x_vals[_iegen_22_iegen_16k])/(_iegen_22_iegen_16Spline.x_vals[_iegen_22_iegen_16k+1] - _iegen_22_iegen_16Spline.x_vals[_iegen_22_iegen_16k]); double _iegen_22_iegen_16A = _iegen_22_iegen_16Spline.slopes[_iegen_22_iegen_16k] * (_iegen_22_iegen_16Spline.x_vals[_iegen_22_iegen_16k+1] -_iegen_22_iegen_16Spline.x_vals[_iegen_22_iegen_16k]) - (_iegen_22_iegen_16Spline.f_vals[_iegen_22_iegen_16k+1] - _iegen_22_iegen_16Spline.f_vals[_iegen_22_iegen_16k]); double _iegen_22_iegen_16B = -_iegen_22_iegen_16Spline.slopes[_iegen_22_iegen_16k+1] * (_iegen_22_iegen_16Spline.x_vals[_iegen_22_iegen_16k+1] - _iegen_22_iegen_16Spline.x_vals[_iegen_22_iegen_16k]) + (_iegen_22_iegen_16Spline.f_vals[_iegen_22_iegen_16k+1] - _iegen_22_iegen_16Spline.f_vals[_iegen_22_iegen_16k]); _iegen_22_iegen_16eval_spline_df_return = (_iegen_22_iegen_16Spline.f_vals[_iegen_22_iegen_16k+1] - _iegen_22_iegen_16Spline.f_vals[_iegen_22_iegen_16k])/(_iegen_22_iegen_16Spline.x_vals[_iegen_22_iegen_16k+1] - _iegen_22_iegen_16Spline.x_vals[_iegen_22_iegen_16k]) + (1.0 - 2.0 * _iegen_22_iegen_16X) * (_iegen_22_iegen_16A * (1.0 - _iegen_22_iegen_16X) + _iegen_22_iegen_16B * _iegen_22_iegen_16X)/(_iegen_22_iegen_16Spline.x_vals[_iegen_22_iegen_16k+1] - _iegen_22_iegen_16Spline.x_vals[_iegen_22_iegen_16k])+ _iegen_22_iegen_16X * (1.0 - _iegen_22_iegen_16X) * (_iegen_22_iegen_16B - _iegen_22_iegen_16A)/(_iegen_22_iegen_16Spline.x_vals[_iegen_22_iegen_16k+1] - _iegen_22_iegen_16Spline.x_vals[_iegen_22_iegen_16k]);} 
#define s189(__x0)   double _iegen_22eval_Spline_df_return = _iegen_22_iegen_16eval_spline_df_return; 
#define s190(__x0)   if(_iegen_22n==0){_iegen_22v_diff_return = _iegen_22eval_Spline_df_return;} 
#define s191(__x0)   sources.dv[1] = _iegen_22v_diff_return; 
#define s192(__x0)   double _iegen_23r = r; 
#define s193(__x0)   double _iegen_23theta = theta; 
#define s194(__x0)   double _iegen_23phi = phi; 
#define s195(__x0)   int _iegen_23n = 1; 
#define s196(__x0)   NaturalCubicSpline_1D & _iegen_23Windu_Spline = spl.Windu_Spline; 
#define s197(__x0)   double _iegen_23r_eval = min(_iegen_23r, r_max); _iegen_23r_eval = max(_iegen_23r_eval, r_min); 
#define s198(__x0)   double _iegen_23u_diff_return = 0.0 
#define s199(__x0)   double _iegen_23_iegen_19x = _iegen_23r_eval; 
#define s200(__x0)   NaturalCubicSpline_1D & _iegen_23_iegen_19Spline = _iegen_23Windu_Spline; 
#define s201(__x0)   double _iegen_23_iegen_19_iegen_18x = _iegen_23_iegen_19x; 
#define s202(__x0)   double* _iegen_23_iegen_19_iegen_18x_vals = _iegen_23_iegen_19Spline.x_vals; 
#define s203(__x0)   int _iegen_23_iegen_19_iegen_18length = _iegen_23_iegen_19Spline.length; 
#define s204(__x0)   int& _iegen_23_iegen_19_iegen_18prev = _iegen_23_iegen_19Spline.accel; 
#define s205(__x0, i, __x2)   if(_iegen_23_iegen_19_iegen_18x >= _iegen_23_iegen_19_iegen_18x_vals[i] && _iegen_23_iegen_19_iegen_18x <= _iegen_23_iegen_19_iegen_18x_vals[i+1]) _iegen_23_iegen_19_iegen_18prev = i; 
#define s206(__x0)   int _iegen_23_iegen_19k = _iegen_23_iegen_19_iegen_18prev; 
#define s207(__x0)   double _iegen_23_iegen_19eval_spline_df_return = 0.0; 
#define s208(__x0)   if(_iegen_23_iegen_19k < _iegen_23_iegen_19Spline.length){double _iegen_23_iegen_19X = (_iegen_23_iegen_19x - _iegen_23_iegen_19Spline.x_vals[_iegen_23_iegen_19k])/(_iegen_23_iegen_19Spline.x_vals[_iegen_23_iegen_19k+1] - _iegen_23_iegen_19Spline.x_vals[_iegen_23_iegen_19k]); double _iegen_23_iegen_19A = _iegen_23_iegen_19Spline.slopes[_iegen_23_iegen_19k] * (_iegen_23_iegen_19Spline.x_vals[_iegen_23_iegen_19k+1] -_iegen_23_iegen_19Spline.x_vals[_iegen_23_iegen_19k]) - (_iegen_23_iegen_19Spline.f_vals[_iegen_23_iegen_19k+1] - _iegen_23_iegen_19Spline.f_vals[_iegen_23_iegen_19k]); double _iegen_23_iegen_19B = -_iegen_23_iegen_19Spline.slopes[_iegen_23_iegen_19k+1] * (_iegen_23_iegen_19Spline.x_vals[_iegen_23_iegen_19k+1] - _iegen_23_iegen_19Spline.x_vals[_iegen_23_iegen_19k]) + (_iegen_23_iegen_19Spline.f_vals[_iegen_23_iegen_19k+1] - _iegen_23_iegen_19Spline.f_vals[_iegen_23_iegen_19k]); _iegen_23_iegen_19eval_spline_df_return = (_iegen_23_iegen_19Spline.f_vals[_iegen_23_iegen_19k+1] - _iegen_23_iegen_19Spline.f_vals[_iegen_23_iegen_19k])/(_iegen_23_iegen_19Spline.x_vals[_iegen_23_iegen_19k+1] - _iegen_23_iegen_19Spline.x_vals[_iegen_23_iegen_19k]) + (1.0 - 2.0 * _iegen_23_iegen_19X) * (_iegen_23_iegen_19A * (1.0 - _iegen_23_iegen_19X) + _iegen_23_iegen_19B * _iegen_23_iegen_19X)/(_iegen_23_iegen_19Spline.x_vals[_iegen_23_iegen_19k+1] - _iegen_23_iegen_19Spline.x_vals[_iegen_23_iegen_19k])+ _iegen_23_iegen_19X * (1.0 - _iegen_23_iegen_19X) * (_iegen_23_iegen_19B - _iegen_23_iegen_19A)/(_iegen_23_iegen_19Spline.x_vals[_iegen_23_iegen_19k+1] - _iegen_23_iegen_19Spline.x_vals[_iegen_23_iegen_19k]);} 
#define s209(__x0)   double _iegen_23eval_Spline_df_return = _iegen_23_iegen_19eval_spline_df_return; 
#define s210(__x0)   if(_iegen_23n==0){_iegen_23u_diff_return = _iegen_23eval_Spline_df_return;} 
#define s211(__x0)   sources.du[1] = _iegen_23u_diff_return; 
#define s212(__x0)   double _iegen_24r = r; 
#define s213(__x0)   double _iegen_24theta = theta; 
#define s214(__x0)   double _iegen_24phi = phi; 
#define s215(__x0)   int _iegen_24n = 2; 
#define s216(__x0)   NaturalCubicSpline_1D & _iegen_24Temp_Spline = spl.Temp_Spline; 
#define s217(__x0)   double _iegen_24r_eval = min(_iegen_24r, r_max); _iegen_24r_eval = max(_iegen_24r_eval, r_min); 
#define s218(__x0)   double _iegen_24c_diff_return = 0.0 
#define s219(__x0)   double _iegen_24_iegen_11r = _iegen_24r; 
#define s220(__x0)   double _iegen_24_iegen_11theta = _iegen_24theta; 
#define s221(__x0)   double _iegen_24_iegen_11phi = _iegen_24phi; 
#define s222(__x0)   NaturalCubicSpline_1D & _iegen_24_iegen_11Temp_Spline = _iegen_24Temp_Spline; 
#define s223(__x0)   double _iegen_24_iegen_11r_eval = min(_iegen_24_iegen_11r, r_max); 
#define s224(__x0)   _iegen_24_iegen_11r_eval = max(_iegen_24_iegen_11r_eval, r_min); 
#define s225(__x0)   double _iegen_24_iegen_11_iegen_10x = _iegen_24_iegen_11r_eval; 
#define s226(__x0)   struct NaturalCubicSpline_1D & _iegen_24_iegen_11_iegen_10Spline = _iegen_24_iegen_11Temp_Spline; 
#define s227(__x0)   double _iegen_24_iegen_11_iegen_10_iegen_9x = _iegen_24_iegen_11_iegen_10x; 
#define s228(__x0)   double* _iegen_24_iegen_11_iegen_10_iegen_9x_vals = _iegen_24_iegen_11_iegen_10Spline.x_vals; 
#define s229(__x0)   int _iegen_24_iegen_11_iegen_10_iegen_9length = _iegen_24_iegen_11_iegen_10Spline.length; 
#define s230(__x0)   int& _iegen_24_iegen_11_iegen_10_iegen_9prev = _iegen_24_iegen_11_iegen_10Spline.accel; 
#define s231(__x0, i, __x2)   if(_iegen_24_iegen_11_iegen_10_iegen_9x >= _iegen_24_iegen_11_iegen_10_iegen_9x_vals[i] && _iegen_24_iegen_11_iegen_10_iegen_9x <= _iegen_24_iegen_11_iegen_10_iegen_9x_vals[i+1]) _iegen_24_iegen_11_iegen_10_iegen_9prev = i; 
#define s232(__x0)   int _iegen_24_iegen_11_iegen_10k = _iegen_24_iegen_11_iegen_10_iegen_9prev; 
#define s233(__x0)   double _iegen_24_iegen_11_iegen_10result = 0.0; 
#define s234(__x0)   if(_iegen_24_iegen_11_iegen_10k < _iegen_24_iegen_11_iegen_10Spline.length) { double _iegen_24_iegen_11_iegen_10X = (_iegen_24_iegen_11_iegen_10x - _iegen_24_iegen_11_iegen_10Spline.x_vals[_iegen_24_iegen_11_iegen_10k])/(_iegen_24_iegen_11_iegen_10Spline.x_vals[_iegen_24_iegen_11_iegen_10k+1] - _iegen_24_iegen_11_iegen_10Spline.x_vals[_iegen_24_iegen_11_iegen_10k]); double _iegen_24_iegen_11_iegen_10A = _iegen_24_iegen_11_iegen_10Spline.slopes[_iegen_24_iegen_11_iegen_10k] * (_iegen_24_iegen_11_iegen_10Spline.x_vals[_iegen_24_iegen_11_iegen_10k+1] - _iegen_24_iegen_11_iegen_10Spline.x_vals[_iegen_24_iegen_11_iegen_10k]) - (_iegen_24_iegen_11_iegen_10Spline.f_vals[_iegen_24_iegen_11_iegen_10k+1] - _iegen_24_iegen_11_iegen_10Spline.f_vals[_iegen_24_iegen_11_iegen_10k]); double _iegen_24_iegen_11_iegen_10B = -_iegen_24_iegen_11_iegen_10Spline.slopes[_iegen_24_iegen_11_iegen_10k+1] * (_iegen_24_iegen_11_iegen_10Spline.x_vals[_iegen_24_iegen_11_iegen_10k+1] - _iegen_24_iegen_11_iegen_10Spline.x_vals[_iegen_24_iegen_11_iegen_10k]) + (_iegen_24_iegen_11_iegen_10Spline.f_vals[_iegen_24_iegen_11_iegen_10k+1] - _iegen_24_iegen_11_iegen_10Spline.f_vals[_iegen_24_iegen_11_iegen_10k]); _iegen_24_iegen_11_iegen_10result = (1.0 - _iegen_24_iegen_11_iegen_10X) * _iegen_24_iegen_11_iegen_10Spline.f_vals[_iegen_24_iegen_11_iegen_10k] + _iegen_24_iegen_11_iegen_10X * _iegen_24_iegen_11_iegen_10Spline.f_vals[_iegen_24_iegen_11_iegen_10k+1] + _iegen_24_iegen_11_iegen_10X * (1.0 - _iegen_24_iegen_11_iegen_10X) * (_iegen_24_iegen_11_iegen_10A * (1.0 - _iegen_24_iegen_11_iegen_10X ) + _iegen_24_iegen_11_iegen_10B * _iegen_24_iegen_11_iegen_10X);} 
#define s235(__x0)   double _iegen_24_iegen_11c_result = sqrt(gamR * _iegen_24_iegen_11_iegen_10result); 
#define s236(__x0)   double _iegen_24c_return = _iegen_24_iegen_11c_result; 
#define s237(__x0)   double _iegen_24_iegen_13x = _iegen_24r_eval; 
#define s238(__x0)   NaturalCubicSpline_1D & _iegen_24_iegen_13Spline = _iegen_24Temp_Spline; 
#define s239(__x0)   double _iegen_24_iegen_13_iegen_12x = _iegen_24_iegen_13x; 
#define s240(__x0)   double* _iegen_24_iegen_13_iegen_12x_vals = _iegen_24_iegen_13Spline.x_vals; 
#define s241(__x0)   int _iegen_24_iegen_13_iegen_12length = _iegen_24_iegen_13Spline.length; 
#define s242(__x0)   int& _iegen_24_iegen_13_iegen_12prev = _iegen_24_iegen_13Spline.accel; 
#define s243(__x0, i, __x2)   if(_iegen_24_iegen_13_iegen_12x >= _iegen_24_iegen_13_iegen_12x_vals[i] && _iegen_24_iegen_13_iegen_12x <= _iegen_24_iegen_13_iegen_12x_vals[i+1]) _iegen_24_iegen_13_iegen_12prev = i; 
#define s244(__x0)   int _iegen_24_iegen_13k = _iegen_24_iegen_13_iegen_12prev; 
#define s245(__x0)   double _iegen_24_iegen_13eval_spline_df_return = 0.0; 
#define s246(__x0)   if(_iegen_24_iegen_13k < _iegen_24_iegen_13Spline.length){double _iegen_24_iegen_13X = (_iegen_24_iegen_13x - _iegen_24_iegen_13Spline.x_vals[_iegen_24_iegen_13k])/(_iegen_24_iegen_13Spline.x_vals[_iegen_24_iegen_13k+1] - _iegen_24_iegen_13Spline.x_vals[_iegen_24_iegen_13k]); double _iegen_24_iegen_13A = _iegen_24_iegen_13Spline.slopes[_iegen_24_iegen_13k] * (_iegen_24_iegen_13Spline.x_vals[_iegen_24_iegen_13k+1] -_iegen_24_iegen_13Spline.x_vals[_iegen_24_iegen_13k]) - (_iegen_24_iegen_13Spline.f_vals[_iegen_24_iegen_13k+1] - _iegen_24_iegen_13Spline.f_vals[_iegen_24_iegen_13k]); double _iegen_24_iegen_13B = -_iegen_24_iegen_13Spline.slopes[_iegen_24_iegen_13k+1] * (_iegen_24_iegen_13Spline.x_vals[_iegen_24_iegen_13k+1] - _iegen_24_iegen_13Spline.x_vals[_iegen_24_iegen_13k]) + (_iegen_24_iegen_13Spline.f_vals[_iegen_24_iegen_13k+1] - _iegen_24_iegen_13Spline.f_vals[_iegen_24_iegen_13k]); _iegen_24_iegen_13eval_spline_df_return = (_iegen_24_iegen_13Spline.f_vals[_iegen_24_iegen_13k+1] - _iegen_24_iegen_13Spline.f_vals[_iegen_24_iegen_13k])/(_iegen_24_iegen_13Spline.x_vals[_iegen_24_iegen_13k+1] - _iegen_24_iegen_13Spline.x_vals[_iegen_24_iegen_13k]) + (1.0 - 2.0 * _iegen_24_iegen_13X) * (_iegen_24_iegen_13A * (1.0 - _iegen_24_iegen_13X) + _iegen_24_iegen_13B * _iegen_24_iegen_13X)/(_iegen_24_iegen_13Spline.x_vals[_iegen_24_iegen_13k+1] - _iegen_24_iegen_13Spline.x_vals[_iegen_24_iegen_13k])+ _iegen_24_iegen_13X * (1.0 - _iegen_24_iegen_13X) * (_iegen_24_iegen_13B - _iegen_24_iegen_13A)/(_iegen_24_iegen_13Spline.x_vals[_iegen_24_iegen_13k+1] - _iegen_24_iegen_13Spline.x_vals[_iegen_24_iegen_13k]);} 
#define s247(__x0)   double _iegen_24eval_spline_df_return = _iegen_24_iegen_13eval_spline_df_return; 
#define s248(__x0)   if(_iegen_24n==0){_iegen_24c_diff_return = gamR / (2.0 * _iegen_24c_return) * _iegen_24eval_spline_df_return;} 
#define s249(__x0)   sources.dc[2] = _iegen_24c_diff_return; 
#define s250(__x0)   sources.dw[2] = 0; 
#define s251(__x0)   double _iegen_25r = r; 
#define s252(__x0)   double _iegen_25theta = theta; 
#define s253(__x0)   double _iegen_25phi = phi; 
#define s254(__x0)   int _iegen_25n = 2; 
#define s255(__x0)   NaturalCubicSpline_1D & _iegen_25Windv_Spline = spl.Windv_Spline; 
#define s256(__x0)   double _iegen_25r_eval = min(_iegen_25r, r_max); _iegen_25r_eval = max(_iegen_25r_eval, r_min); 
#define s257(__x0)   double _iegen_25v_diff_return = 0.0 
#define s258(__x0)   double _iegen_25_iegen_16x = _iegen_25r_eval; 
#define s259(__x0)   NaturalCubicSpline_1D & _iegen_25_iegen_16Spline = _iegen_25Windv_Spline; 
#define s260(__x0)   double _iegen_25_iegen_16_iegen_15x = _iegen_25_iegen_16x; 
#define s261(__x0)   double* _iegen_25_iegen_16_iegen_15x_vals = _iegen_25_iegen_16Spline.x_vals; 
#define s262(__x0)   int _iegen_25_iegen_16_iegen_15length = _iegen_25_iegen_16Spline.length; 
#define s263(__x0)   int& _iegen_25_iegen_16_iegen_15prev = _iegen_25_iegen_16Spline.accel; 
#define s264(__x0, i, __x2)   if(_iegen_25_iegen_16_iegen_15x >= _iegen_25_iegen_16_iegen_15x_vals[i] && _iegen_25_iegen_16_iegen_15x <= _iegen_25_iegen_16_iegen_15x_vals[i+1]) _iegen_25_iegen_16_iegen_15prev = i; 
#define s265(__x0)   int _iegen_25_iegen_16k = _iegen_25_iegen_16_iegen_15prev; 
#define s266(__x0)   double _iegen_25_iegen_16eval_spline_df_return = 0.0; 
#define s267(__x0)   if(_iegen_25_iegen_16k < _iegen_25_iegen_16Spline.length){double _iegen_25_iegen_16X = (_iegen_25_iegen_16x - _iegen_25_iegen_16Spline.x_vals[_iegen_25_iegen_16k])/(_iegen_25_iegen_16Spline.x_vals[_iegen_25_iegen_16k+1] - _iegen_25_iegen_16Spline.x_vals[_iegen_25_iegen_16k]); double _iegen_25_iegen_16A = _iegen_25_iegen_16Spline.slopes[_iegen_25_iegen_16k] * (_iegen_25_iegen_16Spline.x_vals[_iegen_25_iegen_16k+1] -_iegen_25_iegen_16Spline.x_vals[_iegen_25_iegen_16k]) - (_iegen_25_iegen_16Spline.f_vals[_iegen_25_iegen_16k+1] - _iegen_25_iegen_16Spline.f_vals[_iegen_25_iegen_16k]); double _iegen_25_iegen_16B = -_iegen_25_iegen_16Spline.slopes[_iegen_25_iegen_16k+1] * (_iegen_25_iegen_16Spline.x_vals[_iegen_25_iegen_16k+1] - _iegen_25_iegen_16Spline.x_vals[_iegen_25_iegen_16k]) + (_iegen_25_iegen_16Spline.f_vals[_iegen_25_iegen_16k+1] - _iegen_25_iegen_16Spline.f_vals[_iegen_25_iegen_16k]); _iegen_25_iegen_16eval_spline_df_return = (_iegen_25_iegen_16Spline.f_vals[_iegen_25_iegen_16k+1] - _iegen_25_iegen_16Spline.f_vals[_iegen_25_iegen_16k])/(_iegen_25_iegen_16Spline.x_vals[_iegen_25_iegen_16k+1] - _iegen_25_iegen_16Spline.x_vals[_iegen_25_iegen_16k]) + (1.0 - 2.0 * _iegen_25_iegen_16X) * (_iegen_25_iegen_16A * (1.0 - _iegen_25_iegen_16X) + _iegen_25_iegen_16B * _iegen_25_iegen_16X)/(_iegen_25_iegen_16Spline.x_vals[_iegen_25_iegen_16k+1] - _iegen_25_iegen_16Spline.x_vals[_iegen_25_iegen_16k])+ _iegen_25_iegen_16X * (1.0 - _iegen_25_iegen_16X) * (_iegen_25_iegen_16B - _iegen_25_iegen_16A)/(_iegen_25_iegen_16Spline.x_vals[_iegen_25_iegen_16k+1] - _iegen_25_iegen_16Spline.x_vals[_iegen_25_iegen_16k]);} 
#define s268(__x0)   double _iegen_25eval_Spline_df_return = _iegen_25_iegen_16eval_spline_df_return; 
#define s269(__x0)   if(_iegen_25n==0){_iegen_25v_diff_return = _iegen_25eval_Spline_df_return;} 
#define s270(__x0)   sources.dv[2] = _iegen_25v_diff_return; 
#define s271(__x0)   double _iegen_26r = r; 
#define s272(__x0)   double _iegen_26theta = theta; 
#define s273(__x0)   double _iegen_26phi = phi; 
#define s274(__x0)   int _iegen_26n = 2; 
#define s275(__x0)   NaturalCubicSpline_1D & _iegen_26Windu_Spline = spl.Windu_Spline; 
#define s276(__x0)   double _iegen_26r_eval = min(_iegen_26r, r_max); _iegen_26r_eval = max(_iegen_26r_eval, r_min); 
#define s277(__x0)   double _iegen_26u_diff_return = 0.0 
#define s278(__x0)   double _iegen_26_iegen_19x = _iegen_26r_eval; 
#define s279(__x0)   NaturalCubicSpline_1D & _iegen_26_iegen_19Spline = _iegen_26Windu_Spline; 
#define s280(__x0)   double _iegen_26_iegen_19_iegen_18x = _iegen_26_iegen_19x; 
#define s281(__x0)   double* _iegen_26_iegen_19_iegen_18x_vals = _iegen_26_iegen_19Spline.x_vals; 
#define s282(__x0)   int _iegen_26_iegen_19_iegen_18length = _iegen_26_iegen_19Spline.length; 
#define s283(__x0)   int& _iegen_26_iegen_19_iegen_18prev = _iegen_26_iegen_19Spline.accel; 
#define s284(__x0, i, __x2)   if(_iegen_26_iegen_19_iegen_18x >= _iegen_26_iegen_19_iegen_18x_vals[i] && _iegen_26_iegen_19_iegen_18x <= _iegen_26_iegen_19_iegen_18x_vals[i+1]) _iegen_26_iegen_19_iegen_18prev = i; 
#define s285(__x0)   int _iegen_26_iegen_19k = _iegen_26_iegen_19_iegen_18prev; 
#define s286(__x0)   double _iegen_26_iegen_19eval_spline_df_return = 0.0; 
#define s287(__x0)   if(_iegen_26_iegen_19k < _iegen_26_iegen_19Spline.length){double _iegen_26_iegen_19X = (_iegen_26_iegen_19x - _iegen_26_iegen_19Spline.x_vals[_iegen_26_iegen_19k])/(_iegen_26_iegen_19Spline.x_vals[_iegen_26_iegen_19k+1] - _iegen_26_iegen_19Spline.x_vals[_iegen_26_iegen_19k]); double _iegen_26_iegen_19A = _iegen_26_iegen_19Spline.slopes[_iegen_26_iegen_19k] * (_iegen_26_iegen_19Spline.x_vals[_iegen_26_iegen_19k+1] -_iegen_26_iegen_19Spline.x_vals[_iegen_26_iegen_19k]) - (_iegen_26_iegen_19Spline.f_vals[_iegen_26_iegen_19k+1] - _iegen_26_iegen_19Spline.f_vals[_iegen_26_iegen_19k]); double _iegen_26_iegen_19B = -_iegen_26_iegen_19Spline.slopes[_iegen_26_iegen_19k+1] * (_iegen_26_iegen_19Spline.x_vals[_iegen_26_iegen_19k+1] - _iegen_26_iegen_19Spline.x_vals[_iegen_26_iegen_19k]) + (_iegen_26_iegen_19Spline.f_vals[_iegen_26_iegen_19k+1] - _iegen_26_iegen_19Spline.f_vals[_iegen_26_iegen_19k]); _iegen_26_iegen_19eval_spline_df_return = (_iegen_26_iegen_19Spline.f_vals[_iegen_26_iegen_19k+1] - _iegen_26_iegen_19Spline.f_vals[_iegen_26_iegen_19k])/(_iegen_26_iegen_19Spline.x_vals[_iegen_26_iegen_19k+1] - _iegen_26_iegen_19Spline.x_vals[_iegen_26_iegen_19k]) + (1.0 - 2.0 * _iegen_26_iegen_19X) * (_iegen_26_iegen_19A * (1.0 - _iegen_26_iegen_19X) + _iegen_26_iegen_19B * _iegen_26_iegen_19X)/(_iegen_26_iegen_19Spline.x_vals[_iegen_26_iegen_19k+1] - _iegen_26_iegen_19Spline.x_vals[_iegen_26_iegen_19k])+ _iegen_26_iegen_19X * (1.0 - _iegen_26_iegen_19X) * (_iegen_26_iegen_19B - _iegen_26_iegen_19A)/(_iegen_26_iegen_19Spline.x_vals[_iegen_26_iegen_19k+1] - _iegen_26_iegen_19Spline.x_vals[_iegen_26_iegen_19k]);} 
#define s288(__x0)   double _iegen_26eval_Spline_df_return = _iegen_26_iegen_19eval_spline_df_return; 
#define s289(__x0)   if(_iegen_26n==0){_iegen_26u_diff_return = _iegen_26eval_Spline_df_return;} 
#define s290(__x0)   sources.du[2] = _iegen_26u_diff_return; 
#define s291(__x0)   sources.nu_mag = sqrt( nu[0]*nu[0] + nu[1]*nu[1] + nu[2]*nu[2]); 
#define s292(__x0)   sources.c_gr[0] =  sources.c*nu[0]/sources.nu_mag + sources.w; 
#define s293(__x0)   sources.c_gr[1] =  sources.c*nu[1]/sources.nu_mag + sources.v; 
#define s294(__x0)   sources.c_gr[2] =  sources.c*nu[2]/sources.nu_mag + sources.u; 
#define s295(__x0)   sources.c_gr_mag = sqrt(pow(sources.c_gr[0],2) + pow(sources.c_gr[1],2) + pow(sources.c_gr[2],2)); 
#define s296(__x0)   sources.GeoCoeff[0] = 1.0; 
#define s297(__x0)   sources.GeoCoeff[1] = 1.0/r; 
#define s298(__x0)   sources.GeoCoeff[2] = 1.0/(r*cos(theta)); 
#define s299(__x0)   sources.GeoTerms[0] = 0.0; 
#define s300(__x0)   sources.GeoTerms[1] = (nu[0]*sources.v - nu[1]*sources.w); 
#define s301(__x0)   sources.GeoTerms[2] = (nu[0]*sources.u - nu[2]*sources.w)*cos(theta) + (nu[1]*sources.u - nu[2]*sources.v)*sin(theta); 
#define s302(__x0)   sources.GeoTerms[0] += 1.0/r * (nu[1]*sources.c_gr[1] + nu[2]*sources.c_gr[2]); 
#define s303(__x0)   sources.GeoTerms[1] += -nu[0]*sources.c_gr[1] + nu[2]*sources.c_gr[2]*tan(theta); 
#define s304(__x0)   sources.GeoTerms[2] += -sources.c_gr[2]*(nu[0]*cos(theta) + nu[1]*sin(theta)); 
#define s305(__x0)   double R_lt[3], R_lp[3], mu_lt[3], mu_lp[3]; 
#define s306(__x0)   R_lt[0]  = current_values[6];       R_lt[1]  = current_values[7];       R_lt[2]  = current_values[8]; 
#define s307(__x0)   mu_lt[0] = current_values[9];     mu_lt[1] = current_values[10];      mu_lt[2] = current_values[11]; 
#define s308(__x0)   R_lp[0]  = current_values[12]; R_lp[1] = current_values[13]; R_lp[2]  = current_values[14]; 
#define s309(__x0)   mu_lp[0] = current_values[15]; mu_lp[1] = current_values[16]; mu_lp[2] = current_values[17]; 


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
s12(12);
s13(13);
for(t2 = 0; t2 <= _iegen_2_iegen_1_iegen_0length-1; t2++) {
  s14(14,t2,0);
}
s15(15);
s16(16);
s17(17);
s18(18);
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
s30(30);
s31(31);
for(t2 = 0; t2 <= _iegen_5_iegen_4_iegen_3length-1; t2++) {
  s32(32,t2,0);
}
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
s46(46);
s47(47);
s48(48);
for(t2 = 0; t2 <= _iegen_8_iegen_7_iegen_6length-1; t2++) {
  s49(49,t2,0);
}
s50(50);
s51(51);
s52(52);
s53(53);
s54(54);
s55(55);
s56(56);
s57(57);
s58(58);
s59(59);
s60(60);
s61(61);
s62(62);
s63(63);
s64(64);
s65(65);
s66(66);
s67(67);
s68(68);
s69(69);
s70(70);
s71(71);
s72(72);
for(t2 = 0; t2 <= _iegen_14_iegen_11_iegen_10_iegen_9length-1; t2++) {
  s73(73,t2,0);
}
s74(74);
s75(75);
s76(76);
s77(77);
s78(78);
s79(79);
s80(80);
s81(81);
s82(82);
s83(83);
s84(84);
for(t2 = 0; t2 <= _iegen_14_iegen_13_iegen_12length-1; t2++) {
  s85(85,t2,0);
}
s86(86);
s87(87);
s88(88);
s89(89);
s90(90);
s91(91);
s92(92);
s93(93);
s94(94);
s95(95);
s96(96);
s97(97);
s98(98);
s99(99);
s100(100);
s101(101);
s102(102);
s103(103);
s104(104);
s105(105);
for(t2 = 0; t2 <= _iegen_17_iegen_16_iegen_15length-1; t2++) {
  s106(106,t2,0);
}
s107(107);
s108(108);
s109(109);
s110(110);
s111(111);
s112(112);
s113(113);
s114(114);
s115(115);
s116(116);
s117(117);
s118(118);
s119(119);
s120(120);
s121(121);
s122(122);
s123(123);
s124(124);
s125(125);
for(t2 = 0; t2 <= _iegen_20_iegen_19_iegen_18length-1; t2++) {
  s126(126,t2,0);
}
s127(127);
s128(128);
s129(129);
s130(130);
s131(131);
s132(132);
s133(133);
s134(134);
s135(135);
s136(136);
s137(137);
s138(138);
s139(139);
s140(140);
s141(141);
s142(142);
s143(143);
s144(144);
s145(145);
s146(146);
s147(147);
s148(148);
s149(149);
s150(150);
s151(151);
for(t2 = 0; t2 <= _iegen_21_iegen_11_iegen_10_iegen_9length-1; t2++) {
  s152(152,t2,0);
}
s153(153);
s154(154);
s155(155);
s156(156);
s157(157);
s158(158);
s159(159);
s160(160);
s161(161);
s162(162);
s163(163);
for(t2 = 0; t2 <= _iegen_21_iegen_13_iegen_12length-1; t2++) {
  s164(164,t2,0);
}
s165(165);
s166(166);
s167(167);
s168(168);
s169(169);
s170(170);
s171(171);
s172(172);
s173(173);
s174(174);
s175(175);
s176(176);
s177(177);
s178(178);
s179(179);
s180(180);
s181(181);
s182(182);
s183(183);
s184(184);
for(t2 = 0; t2 <= _iegen_22_iegen_16_iegen_15length-1; t2++) {
  s185(185,t2,0);
}
s186(186);
s187(187);
s188(188);
s189(189);
s190(190);
s191(191);
s192(192);
s193(193);
s194(194);
s195(195);
s196(196);
s197(197);
s198(198);
s199(199);
s200(200);
s201(201);
s202(202);
s203(203);
s204(204);
for(t2 = 0; t2 <= _iegen_23_iegen_19_iegen_18length-1; t2++) {
  s205(205,t2,0);
}
s206(206);
s207(207);
s208(208);
s209(209);
s210(210);
s211(211);
s212(212);
s213(213);
s214(214);
s215(215);
s216(216);
s217(217);
s218(218);
s219(219);
s220(220);
s221(221);
s222(222);
s223(223);
s224(224);
s225(225);
s226(226);
s227(227);
s228(228);
s229(229);
s230(230);
for(t2 = 0; t2 <= _iegen_24_iegen_11_iegen_10_iegen_9length-1; t2++) {
  s231(231,t2,0);
}
s232(232);
s233(233);
s234(234);
s235(235);
s236(236);
s237(237);
s238(238);
s239(239);
s240(240);
s241(241);
s242(242);
for(t2 = 0; t2 <= _iegen_24_iegen_13_iegen_12length-1; t2++) {
  s243(243,t2,0);
}
s244(244);
s245(245);
s246(246);
s247(247);
s248(248);
s249(249);
s250(250);
s251(251);
s252(252);
s253(253);
s254(254);
s255(255);
s256(256);
s257(257);
s258(258);
s259(259);
s260(260);
s261(261);
s262(262);
s263(263);
for(t2 = 0; t2 <= _iegen_25_iegen_16_iegen_15length-1; t2++) {
  s264(264,t2,0);
}
s265(265);
s266(266);
s267(267);
s268(268);
s269(269);
s270(270);
s271(271);
s272(272);
s273(273);
s274(274);
s275(275);
s276(276);
s277(277);
s278(278);
s279(279);
s280(280);
s281(281);
s282(282);
s283(283);
for(t2 = 0; t2 <= _iegen_26_iegen_19_iegen_18length-1; t2++) {
  s284(284,t2,0);
}
s285(285);
s286(286);
s287(287);
s288(288);
s289(289);
s290(290);
s291(291);
s292(292);
s293(293);
s294(294);
s295(295);
s296(296);
s297(297);
s298(298);
s299(299);
s300(300);
s301(301);
s302(302);
s303(303);
s304(304);
s305(305);
if (true == GeoAc_CalcAmp) {
  s306(306);
}
if (true == GeoAc_CalcAmp) {
  s307(307);
}
if (GeoAc_CalcAmp == true) {
  s308(308);
}
if (GeoAc_CalcAmp == true) {
  s309(309);
}

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
#undef s51
#undef s52
#undef s53
#undef s54
#undef s55
#undef s56
#undef s57
#undef s58
#undef s59
#undef s60
#undef s61
#undef s62
#undef s63
#undef s64
#undef s65
#undef s66
#undef s67
#undef s68
#undef s69
#undef s70
#undef s71
#undef s72
#undef s73
#undef s74
#undef s75
#undef s76
#undef s77
#undef s78
#undef s79
#undef s80
#undef s81
#undef s82
#undef s83
#undef s84
#undef s85
#undef s86
#undef s87
#undef s88
#undef s89
#undef s90
#undef s91
#undef s92
#undef s93
#undef s94
#undef s95
#undef s96
#undef s97
#undef s98
#undef s99
#undef s100
#undef s101
#undef s102
#undef s103
#undef s104
#undef s105
#undef s106
#undef s107
#undef s108
#undef s109
#undef s110
#undef s111
#undef s112
#undef s113
#undef s114
#undef s115
#undef s116
#undef s117
#undef s118
#undef s119
#undef s120
#undef s121
#undef s122
#undef s123
#undef s124
#undef s125
#undef s126
#undef s127
#undef s128
#undef s129
#undef s130
#undef s131
#undef s132
#undef s133
#undef s134
#undef s135
#undef s136
#undef s137
#undef s138
#undef s139
#undef s140
#undef s141
#undef s142
#undef s143
#undef s144
#undef s145
#undef s146
#undef s147
#undef s148
#undef s149
#undef s150
#undef s151
#undef s152
#undef s153
#undef s154
#undef s155
#undef s156
#undef s157
#undef s158
#undef s159
#undef s160
#undef s161
#undef s162
#undef s163
#undef s164
#undef s165
#undef s166
#undef s167
#undef s168
#undef s169
#undef s170
#undef s171
#undef s172
#undef s173
#undef s174
#undef s175
#undef s176
#undef s177
#undef s178
#undef s179
#undef s180
#undef s181
#undef s182
#undef s183
#undef s184
#undef s185
#undef s186
#undef s187
#undef s188
#undef s189
#undef s190
#undef s191
#undef s192
#undef s193
#undef s194
#undef s195
#undef s196
#undef s197
#undef s198
#undef s199
#undef s200
#undef s201
#undef s202
#undef s203
#undef s204
#undef s205
#undef s206
#undef s207
#undef s208
#undef s209
#undef s210
#undef s211
#undef s212
#undef s213
#undef s214
#undef s215
#undef s216
#undef s217
#undef s218
#undef s219
#undef s220
#undef s221
#undef s222
#undef s223
#undef s224
#undef s225
#undef s226
#undef s227
#undef s228
#undef s229
#undef s230
#undef s231
#undef s232
#undef s233
#undef s234
#undef s235
#undef s236
#undef s237
#undef s238
#undef s239
#undef s240
#undef s241
#undef s242
#undef s243
#undef s244
#undef s245
#undef s246
#undef s247
#undef s248
#undef s249
#undef s250
#undef s251
#undef s252
#undef s253
#undef s254
#undef s255
#undef s256
#undef s257
#undef s258
#undef s259
#undef s260
#undef s261
#undef s262
#undef s263
#undef s264
#undef s265
#undef s266
#undef s267
#undef s268
#undef s269
#undef s270
#undef s271
#undef s272
#undef s273
#undef s274
#undef s275
#undef s276
#undef s277
#undef s278
#undef s279
#undef s280
#undef s281
#undef s282
#undef s283
#undef s284
#undef s285
#undef s286
#undef s287
#undef s288
#undef s289
#undef s290
#undef s291
#undef s292
#undef s293
#undef s294
#undef s295
#undef s296
#undef s297
#undef s298
#undef s299
#undef s300
#undef s301
#undef s302
#undef s303
#undef s304
#undef s305
#undef s306
#undef s307
#undef s308
#undef s309
