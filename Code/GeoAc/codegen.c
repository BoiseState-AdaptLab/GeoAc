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
#define s17(__x0)   sources.c = _iegen_2c_result; 
#define s18(__x0)   sources.w = 0; 
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
#define s34(__x0)   double _iegen_5v_return =_iegen_5_iegen_4result; 
#define s35(__x0)   sources.v = _iegen_5v_return; 
#define s36(__x0)   double _iegen_8r = r; 
#define s37(__x0)   double _iegen_8theta = theta; 
#define s38(__x0)   double _iegen_8phi = phi; 
#define s39(__x0)   NaturalCubicSpline_1D & _iegen_8Windu_Spline = spl.Windu_Spline; 
#define s40(__x0)   double _iegen_8r_eval = min(_iegen_8r, r_max); _iegen_8r_eval = max(_iegen_8r_eval, r_min) 
#define s41(__x0)   double _iegen_8_iegen_7x = _iegen_8r_eval; 
#define s42(__x0)   struct NaturalCubicSpline_1D & _iegen_8_iegen_7Spline = _iegen_8Windu_Spline; 
#define s43(__x0)   double _iegen_8_iegen_7_iegen_6x = _iegen_8_iegen_7x; 
#define s44(__x0)   double* _iegen_8_iegen_7_iegen_6x_vals = _iegen_8_iegen_7Spline.x_vals; 
#define s45(__x0)   int _iegen_8_iegen_7_iegen_6length = _iegen_8_iegen_7Spline.length; 
#define s46(__x0)   int& _iegen_8_iegen_7_iegen_6prev = _iegen_8_iegen_7Spline.accel; 
#define s47(__x0, i, __x2)   if(_iegen_8_iegen_7_iegen_6x >= _iegen_8_iegen_7_iegen_6x_vals[i] && _iegen_8_iegen_7_iegen_6x <= _iegen_8_iegen_7_iegen_6x_vals[i+1]) _iegen_8_iegen_7_iegen_6prev = i; 
#define s48(__x0)   int _iegen_8_iegen_7k = _iegen_8_iegen_7_iegen_6prev; 
#define s49(__x0)   double _iegen_8_iegen_7result = 0.0; 
#define s50(__x0)   if(_iegen_8_iegen_7k < _iegen_8_iegen_7Spline.length) { double _iegen_8_iegen_7X = (_iegen_8_iegen_7x - _iegen_8_iegen_7Spline.x_vals[_iegen_8_iegen_7k])/(_iegen_8_iegen_7Spline.x_vals[_iegen_8_iegen_7k+1] - _iegen_8_iegen_7Spline.x_vals[_iegen_8_iegen_7k]); double _iegen_8_iegen_7A = _iegen_8_iegen_7Spline.slopes[_iegen_8_iegen_7k] * (_iegen_8_iegen_7Spline.x_vals[_iegen_8_iegen_7k+1] - _iegen_8_iegen_7Spline.x_vals[_iegen_8_iegen_7k]) - (_iegen_8_iegen_7Spline.f_vals[_iegen_8_iegen_7k+1] - _iegen_8_iegen_7Spline.f_vals[_iegen_8_iegen_7k]); double _iegen_8_iegen_7B = -_iegen_8_iegen_7Spline.slopes[_iegen_8_iegen_7k+1] * (_iegen_8_iegen_7Spline.x_vals[_iegen_8_iegen_7k+1] - _iegen_8_iegen_7Spline.x_vals[_iegen_8_iegen_7k]) + (_iegen_8_iegen_7Spline.f_vals[_iegen_8_iegen_7k+1] - _iegen_8_iegen_7Spline.f_vals[_iegen_8_iegen_7k]); _iegen_8_iegen_7result = (1.0 - _iegen_8_iegen_7X) * _iegen_8_iegen_7Spline.f_vals[_iegen_8_iegen_7k] + _iegen_8_iegen_7X * _iegen_8_iegen_7Spline.f_vals[_iegen_8_iegen_7k+1] + _iegen_8_iegen_7X * (1.0 - _iegen_8_iegen_7X) * (_iegen_8_iegen_7A * (1.0 - _iegen_8_iegen_7X ) + _iegen_8_iegen_7B * _iegen_8_iegen_7X);} 
#define s51(__x0)   sources.u = _iegen_8_iegen_7result; 
#define s52(__x0)   double _iegen_14r = r; 
#define s53(__x0)   double _iegen_14theta = theta; 
#define s54(__x0)   double _iegen_14phi = phi; 
#define s55(__x0)   int _iegen_14n = 0; 
#define s56(__x0)   NaturalCubicSpline_1D & _iegen_14Temp_Spline = spl.Temp_Spline; 
#define s57(__x0)   double _iegen_14r_eval = min(_iegen_14r, r_max); _iegen_14r_eval = max(_iegen_14r_eval, r_min); 
#define s58(__x0)   double _iegen_14c_diff_return = 0.0 
#define s59(__x0)   double _iegen_14_iegen_11r = _iegen_14r; 
#define s60(__x0)   double _iegen_14_iegen_11theta = _iegen_14theta; 
#define s61(__x0)   double _iegen_14_iegen_11phi = _iegen_14phi; 
#define s62(__x0)   NaturalCubicSpline_1D & _iegen_14_iegen_11Temp_Spline = _iegen_14Temp_Spline; 
#define s63(__x0)   double _iegen_14_iegen_11r_eval = min(_iegen_14_iegen_11r, r_max); 
#define s64(__x0)   _iegen_14_iegen_11r_eval = max(_iegen_14_iegen_11r_eval, r_min); 
#define s65(__x0)   double _iegen_14_iegen_11_iegen_10x = _iegen_14_iegen_11r_eval; 
#define s66(__x0)   struct NaturalCubicSpline_1D & _iegen_14_iegen_11_iegen_10Spline = _iegen_14_iegen_11Temp_Spline; 
#define s67(__x0)   double _iegen_14_iegen_11_iegen_10_iegen_9x = _iegen_14_iegen_11_iegen_10x; 
#define s68(__x0)   double* _iegen_14_iegen_11_iegen_10_iegen_9x_vals = _iegen_14_iegen_11_iegen_10Spline.x_vals; 
#define s69(__x0)   int _iegen_14_iegen_11_iegen_10_iegen_9length = _iegen_14_iegen_11_iegen_10Spline.length; 
#define s70(__x0)   int& _iegen_14_iegen_11_iegen_10_iegen_9prev = _iegen_14_iegen_11_iegen_10Spline.accel; 
#define s71(__x0, i, __x2)   if(_iegen_14_iegen_11_iegen_10_iegen_9x >= _iegen_14_iegen_11_iegen_10_iegen_9x_vals[i] && _iegen_14_iegen_11_iegen_10_iegen_9x <= _iegen_14_iegen_11_iegen_10_iegen_9x_vals[i+1]) _iegen_14_iegen_11_iegen_10_iegen_9prev = i; 
#define s72(__x0)   int _iegen_14_iegen_11_iegen_10k = _iegen_14_iegen_11_iegen_10_iegen_9prev; 
#define s73(__x0)   double _iegen_14_iegen_11_iegen_10result = 0.0; 
#define s74(__x0)   if(_iegen_14_iegen_11_iegen_10k < _iegen_14_iegen_11_iegen_10Spline.length) { double _iegen_14_iegen_11_iegen_10X = (_iegen_14_iegen_11_iegen_10x - _iegen_14_iegen_11_iegen_10Spline.x_vals[_iegen_14_iegen_11_iegen_10k])/(_iegen_14_iegen_11_iegen_10Spline.x_vals[_iegen_14_iegen_11_iegen_10k+1] - _iegen_14_iegen_11_iegen_10Spline.x_vals[_iegen_14_iegen_11_iegen_10k]); double _iegen_14_iegen_11_iegen_10A = _iegen_14_iegen_11_iegen_10Spline.slopes[_iegen_14_iegen_11_iegen_10k] * (_iegen_14_iegen_11_iegen_10Spline.x_vals[_iegen_14_iegen_11_iegen_10k+1] - _iegen_14_iegen_11_iegen_10Spline.x_vals[_iegen_14_iegen_11_iegen_10k]) - (_iegen_14_iegen_11_iegen_10Spline.f_vals[_iegen_14_iegen_11_iegen_10k+1] - _iegen_14_iegen_11_iegen_10Spline.f_vals[_iegen_14_iegen_11_iegen_10k]); double _iegen_14_iegen_11_iegen_10B = -_iegen_14_iegen_11_iegen_10Spline.slopes[_iegen_14_iegen_11_iegen_10k+1] * (_iegen_14_iegen_11_iegen_10Spline.x_vals[_iegen_14_iegen_11_iegen_10k+1] - _iegen_14_iegen_11_iegen_10Spline.x_vals[_iegen_14_iegen_11_iegen_10k]) + (_iegen_14_iegen_11_iegen_10Spline.f_vals[_iegen_14_iegen_11_iegen_10k+1] - _iegen_14_iegen_11_iegen_10Spline.f_vals[_iegen_14_iegen_11_iegen_10k]); _iegen_14_iegen_11_iegen_10result = (1.0 - _iegen_14_iegen_11_iegen_10X) * _iegen_14_iegen_11_iegen_10Spline.f_vals[_iegen_14_iegen_11_iegen_10k] + _iegen_14_iegen_11_iegen_10X * _iegen_14_iegen_11_iegen_10Spline.f_vals[_iegen_14_iegen_11_iegen_10k+1] + _iegen_14_iegen_11_iegen_10X * (1.0 - _iegen_14_iegen_11_iegen_10X) * (_iegen_14_iegen_11_iegen_10A * (1.0 - _iegen_14_iegen_11_iegen_10X ) + _iegen_14_iegen_11_iegen_10B * _iegen_14_iegen_11_iegen_10X);} 
#define s75(__x0)   double _iegen_14_iegen_11c_result = sqrt(gamR * _iegen_14_iegen_11_iegen_10result); 
#define s76(__x0)   double _iegen_14c_return = _iegen_14_iegen_11c_result; 
#define s77(__x0)   double _iegen_14_iegen_13x = _iegen_14r_eval; 
#define s78(__x0)   NaturalCubicSpline_1D & _iegen_14_iegen_13Spline = _iegen_14Temp_Spline; 
#define s79(__x0)   double _iegen_14_iegen_13_iegen_12x = _iegen_14_iegen_13x; 
#define s80(__x0)   double* _iegen_14_iegen_13_iegen_12x_vals = _iegen_14_iegen_13Spline.x_vals; 
#define s81(__x0)   int _iegen_14_iegen_13_iegen_12length = _iegen_14_iegen_13Spline.length; 
#define s82(__x0)   int& _iegen_14_iegen_13_iegen_12prev = _iegen_14_iegen_13Spline.accel; 
#define s83(__x0, i, __x2)   if(_iegen_14_iegen_13_iegen_12x >= _iegen_14_iegen_13_iegen_12x_vals[i] && _iegen_14_iegen_13_iegen_12x <= _iegen_14_iegen_13_iegen_12x_vals[i+1]) _iegen_14_iegen_13_iegen_12prev = i; 
#define s84(__x0)   int _iegen_14_iegen_13k = _iegen_14_iegen_13_iegen_12prev; 
#define s85(__x0)   double _iegen_14_iegen_13eval_spline_df_return = 0.0; 
#define s86(__x0)   if(_iegen_14_iegen_13k < _iegen_14_iegen_13Spline.length){double _iegen_14_iegen_13X = (_iegen_14_iegen_13x - _iegen_14_iegen_13Spline.x_vals[_iegen_14_iegen_13k])/(_iegen_14_iegen_13Spline.x_vals[_iegen_14_iegen_13k+1] - _iegen_14_iegen_13Spline.x_vals[_iegen_14_iegen_13k]); double _iegen_14_iegen_13A = _iegen_14_iegen_13Spline.slopes[_iegen_14_iegen_13k] * (_iegen_14_iegen_13Spline.x_vals[_iegen_14_iegen_13k+1] -_iegen_14_iegen_13Spline.x_vals[_iegen_14_iegen_13k]) - (_iegen_14_iegen_13Spline.f_vals[_iegen_14_iegen_13k+1] - _iegen_14_iegen_13Spline.f_vals[_iegen_14_iegen_13k]); double _iegen_14_iegen_13B = -_iegen_14_iegen_13Spline.slopes[_iegen_14_iegen_13k+1] * (_iegen_14_iegen_13Spline.x_vals[_iegen_14_iegen_13k+1] - _iegen_14_iegen_13Spline.x_vals[_iegen_14_iegen_13k]) + (_iegen_14_iegen_13Spline.f_vals[_iegen_14_iegen_13k+1] - _iegen_14_iegen_13Spline.f_vals[_iegen_14_iegen_13k]); _iegen_14_iegen_13eval_spline_df_return = (_iegen_14_iegen_13Spline.f_vals[_iegen_14_iegen_13k+1] - _iegen_14_iegen_13Spline.f_vals[_iegen_14_iegen_13k])/(_iegen_14_iegen_13Spline.x_vals[_iegen_14_iegen_13k+1] - _iegen_14_iegen_13Spline.x_vals[_iegen_14_iegen_13k]) + (1.0 - 2.0 * _iegen_14_iegen_13X) * (_iegen_14_iegen_13A * (1.0 - _iegen_14_iegen_13X) + _iegen_14_iegen_13B * _iegen_14_iegen_13X)/(_iegen_14_iegen_13Spline.x_vals[_iegen_14_iegen_13k+1] - _iegen_14_iegen_13Spline.x_vals[_iegen_14_iegen_13k])+ _iegen_14_iegen_13X * (1.0 - _iegen_14_iegen_13X) * (_iegen_14_iegen_13B - _iegen_14_iegen_13A)/(_iegen_14_iegen_13Spline.x_vals[_iegen_14_iegen_13k+1] - _iegen_14_iegen_13Spline.x_vals[_iegen_14_iegen_13k]);} 
#define s87(__x0)   double _iegen_14eval_spline_df_return = _iegen_14_iegen_13eval_spline_df_return; 
#define s88(__x0)   if(_iegen_14n==0){_iegen_14c_diff_return = gamR / (2.0 * _iegen_14c_return) * _iegen_14eval_spline_df_return;} 
#define s89(__x0)   sources.dc[0] = _iegen_14c_diff_return; 
#define s90(__x0)   sources.dw[0] = 0; 
#define s91(__x0)   double _iegen_17r = r; 
#define s92(__x0)   double _iegen_17theta = theta; 
#define s93(__x0)   double _iegen_17phi = phi; 
#define s94(__x0)   int _iegen_17n = 0; 
#define s95(__x0)   NaturalCubicSpline_1D & _iegen_17Windv_Spline = spl.Windv_Spline; 
#define s96(__x0)   double _iegen_17r_eval = min(_iegen_17r, r_max); _iegen_17r_eval = max(_iegen_17r_eval, r_min); 
#define s97(__x0)   double _iegen_17v_diff_return = 0.0 
#define s98(__x0)   double _iegen_17_iegen_16x = _iegen_17r_eval; 
#define s99(__x0)   NaturalCubicSpline_1D & _iegen_17_iegen_16Spline = _iegen_17Windv_Spline; 
#define s100(__x0)   double _iegen_17_iegen_16_iegen_15x = _iegen_17_iegen_16x; 
#define s101(__x0)   double* _iegen_17_iegen_16_iegen_15x_vals = _iegen_17_iegen_16Spline.x_vals; 
#define s102(__x0)   int _iegen_17_iegen_16_iegen_15length = _iegen_17_iegen_16Spline.length; 
#define s103(__x0)   int& _iegen_17_iegen_16_iegen_15prev = _iegen_17_iegen_16Spline.accel; 
#define s104(__x0, i, __x2)   if(_iegen_17_iegen_16_iegen_15x >= _iegen_17_iegen_16_iegen_15x_vals[i] && _iegen_17_iegen_16_iegen_15x <= _iegen_17_iegen_16_iegen_15x_vals[i+1]) _iegen_17_iegen_16_iegen_15prev = i; 
#define s105(__x0)   int _iegen_17_iegen_16k = _iegen_17_iegen_16_iegen_15prev; 
#define s106(__x0)   double _iegen_17_iegen_16eval_spline_df_return = 0.0; 
#define s107(__x0)   if(_iegen_17_iegen_16k < _iegen_17_iegen_16Spline.length){double _iegen_17_iegen_16X = (_iegen_17_iegen_16x - _iegen_17_iegen_16Spline.x_vals[_iegen_17_iegen_16k])/(_iegen_17_iegen_16Spline.x_vals[_iegen_17_iegen_16k+1] - _iegen_17_iegen_16Spline.x_vals[_iegen_17_iegen_16k]); double _iegen_17_iegen_16A = _iegen_17_iegen_16Spline.slopes[_iegen_17_iegen_16k] * (_iegen_17_iegen_16Spline.x_vals[_iegen_17_iegen_16k+1] -_iegen_17_iegen_16Spline.x_vals[_iegen_17_iegen_16k]) - (_iegen_17_iegen_16Spline.f_vals[_iegen_17_iegen_16k+1] - _iegen_17_iegen_16Spline.f_vals[_iegen_17_iegen_16k]); double _iegen_17_iegen_16B = -_iegen_17_iegen_16Spline.slopes[_iegen_17_iegen_16k+1] * (_iegen_17_iegen_16Spline.x_vals[_iegen_17_iegen_16k+1] - _iegen_17_iegen_16Spline.x_vals[_iegen_17_iegen_16k]) + (_iegen_17_iegen_16Spline.f_vals[_iegen_17_iegen_16k+1] - _iegen_17_iegen_16Spline.f_vals[_iegen_17_iegen_16k]); _iegen_17_iegen_16eval_spline_df_return = (_iegen_17_iegen_16Spline.f_vals[_iegen_17_iegen_16k+1] - _iegen_17_iegen_16Spline.f_vals[_iegen_17_iegen_16k])/(_iegen_17_iegen_16Spline.x_vals[_iegen_17_iegen_16k+1] - _iegen_17_iegen_16Spline.x_vals[_iegen_17_iegen_16k]) + (1.0 - 2.0 * _iegen_17_iegen_16X) * (_iegen_17_iegen_16A * (1.0 - _iegen_17_iegen_16X) + _iegen_17_iegen_16B * _iegen_17_iegen_16X)/(_iegen_17_iegen_16Spline.x_vals[_iegen_17_iegen_16k+1] - _iegen_17_iegen_16Spline.x_vals[_iegen_17_iegen_16k])+ _iegen_17_iegen_16X * (1.0 - _iegen_17_iegen_16X) * (_iegen_17_iegen_16B - _iegen_17_iegen_16A)/(_iegen_17_iegen_16Spline.x_vals[_iegen_17_iegen_16k+1] - _iegen_17_iegen_16Spline.x_vals[_iegen_17_iegen_16k]);} 
#define s108(__x0)   double _iegen_17eval_Spline_df_return = _iegen_17_iegen_16eval_spline_df_return; 
#define s109(__x0)   if(_iegen_17n==0){_iegen_17v_diff_return = _iegen_17eval_Spline_df_return;} 
#define s110(__x0)   sources.dv[0] = _iegen_17v_diff_return; 
#define s111(__x0)   double _iegen_20r = r; 
#define s112(__x0)   double _iegen_20theta = theta; 
#define s113(__x0)   double _iegen_20phi = phi; 
#define s114(__x0)   int _iegen_20n = 0; 
#define s115(__x0)   NaturalCubicSpline_1D & _iegen_20Windu_Spline = spl.Windu_Spline; 
#define s116(__x0)   double _iegen_20r_eval = min(_iegen_20r, r_max); _iegen_20r_eval = max(_iegen_20r_eval, r_min); 
#define s117(__x0)   double _iegen_20u_diff_return = 0.0 
#define s118(__x0)   double _iegen_20_iegen_19x = _iegen_20r_eval; 
#define s119(__x0)   NaturalCubicSpline_1D & _iegen_20_iegen_19Spline = _iegen_20Windu_Spline; 
#define s120(__x0)   double _iegen_20_iegen_19_iegen_18x = _iegen_20_iegen_19x; 
#define s121(__x0)   double* _iegen_20_iegen_19_iegen_18x_vals = _iegen_20_iegen_19Spline.x_vals; 
#define s122(__x0)   int _iegen_20_iegen_19_iegen_18length = _iegen_20_iegen_19Spline.length; 
#define s123(__x0)   int& _iegen_20_iegen_19_iegen_18prev = _iegen_20_iegen_19Spline.accel; 
#define s124(__x0, i, __x2)   if(_iegen_20_iegen_19_iegen_18x >= _iegen_20_iegen_19_iegen_18x_vals[i] && _iegen_20_iegen_19_iegen_18x <= _iegen_20_iegen_19_iegen_18x_vals[i+1]) _iegen_20_iegen_19_iegen_18prev = i; 
#define s125(__x0)   int _iegen_20_iegen_19k = _iegen_20_iegen_19_iegen_18prev; 
#define s126(__x0)   double _iegen_20_iegen_19eval_spline_df_return = 0.0; 
#define s127(__x0)   if(_iegen_20_iegen_19k < _iegen_20_iegen_19Spline.length){double _iegen_20_iegen_19X = (_iegen_20_iegen_19x - _iegen_20_iegen_19Spline.x_vals[_iegen_20_iegen_19k])/(_iegen_20_iegen_19Spline.x_vals[_iegen_20_iegen_19k+1] - _iegen_20_iegen_19Spline.x_vals[_iegen_20_iegen_19k]); double _iegen_20_iegen_19A = _iegen_20_iegen_19Spline.slopes[_iegen_20_iegen_19k] * (_iegen_20_iegen_19Spline.x_vals[_iegen_20_iegen_19k+1] -_iegen_20_iegen_19Spline.x_vals[_iegen_20_iegen_19k]) - (_iegen_20_iegen_19Spline.f_vals[_iegen_20_iegen_19k+1] - _iegen_20_iegen_19Spline.f_vals[_iegen_20_iegen_19k]); double _iegen_20_iegen_19B = -_iegen_20_iegen_19Spline.slopes[_iegen_20_iegen_19k+1] * (_iegen_20_iegen_19Spline.x_vals[_iegen_20_iegen_19k+1] - _iegen_20_iegen_19Spline.x_vals[_iegen_20_iegen_19k]) + (_iegen_20_iegen_19Spline.f_vals[_iegen_20_iegen_19k+1] - _iegen_20_iegen_19Spline.f_vals[_iegen_20_iegen_19k]); _iegen_20_iegen_19eval_spline_df_return = (_iegen_20_iegen_19Spline.f_vals[_iegen_20_iegen_19k+1] - _iegen_20_iegen_19Spline.f_vals[_iegen_20_iegen_19k])/(_iegen_20_iegen_19Spline.x_vals[_iegen_20_iegen_19k+1] - _iegen_20_iegen_19Spline.x_vals[_iegen_20_iegen_19k]) + (1.0 - 2.0 * _iegen_20_iegen_19X) * (_iegen_20_iegen_19A * (1.0 - _iegen_20_iegen_19X) + _iegen_20_iegen_19B * _iegen_20_iegen_19X)/(_iegen_20_iegen_19Spline.x_vals[_iegen_20_iegen_19k+1] - _iegen_20_iegen_19Spline.x_vals[_iegen_20_iegen_19k])+ _iegen_20_iegen_19X * (1.0 - _iegen_20_iegen_19X) * (_iegen_20_iegen_19B - _iegen_20_iegen_19A)/(_iegen_20_iegen_19Spline.x_vals[_iegen_20_iegen_19k+1] - _iegen_20_iegen_19Spline.x_vals[_iegen_20_iegen_19k]);} 
#define s128(__x0)   double _iegen_20eval_Spline_df_return = _iegen_20_iegen_19eval_spline_df_return; 
#define s129(__x0)   if(_iegen_20n==0){_iegen_20u_diff_return = _iegen_20eval_Spline_df_return;} 
#define s130(__x0)   sources.du[0] = _iegen_20u_diff_return; 
#define s131(__x0)   double _iegen_21r = r; 
#define s132(__x0)   double _iegen_21theta = theta; 
#define s133(__x0)   double _iegen_21phi = phi; 
#define s134(__x0)   int _iegen_21n = 1; 
#define s135(__x0)   NaturalCubicSpline_1D & _iegen_21Temp_Spline = spl.Temp_Spline; 
#define s136(__x0)   double _iegen_21r_eval = min(_iegen_21r, r_max); _iegen_21r_eval = max(_iegen_21r_eval, r_min); 
#define s137(__x0)   double _iegen_21c_diff_return = 0.0 
#define s138(__x0)   double _iegen_21_iegen_11r = _iegen_21r; 
#define s139(__x0)   double _iegen_21_iegen_11theta = _iegen_21theta; 
#define s140(__x0)   double _iegen_21_iegen_11phi = _iegen_21phi; 
#define s141(__x0)   NaturalCubicSpline_1D & _iegen_21_iegen_11Temp_Spline = _iegen_21Temp_Spline; 
#define s142(__x0)   double _iegen_21_iegen_11r_eval = min(_iegen_21_iegen_11r, r_max); 
#define s143(__x0)   _iegen_21_iegen_11r_eval = max(_iegen_21_iegen_11r_eval, r_min); 
#define s144(__x0)   double _iegen_21_iegen_11_iegen_10x = _iegen_21_iegen_11r_eval; 
#define s145(__x0)   struct NaturalCubicSpline_1D & _iegen_21_iegen_11_iegen_10Spline = _iegen_21_iegen_11Temp_Spline; 
#define s146(__x0)   double _iegen_21_iegen_11_iegen_10_iegen_9x = _iegen_21_iegen_11_iegen_10x; 
#define s147(__x0)   double* _iegen_21_iegen_11_iegen_10_iegen_9x_vals = _iegen_21_iegen_11_iegen_10Spline.x_vals; 
#define s148(__x0)   int _iegen_21_iegen_11_iegen_10_iegen_9length = _iegen_21_iegen_11_iegen_10Spline.length; 
#define s149(__x0)   int& _iegen_21_iegen_11_iegen_10_iegen_9prev = _iegen_21_iegen_11_iegen_10Spline.accel; 
#define s150(__x0, i, __x2)   if(_iegen_21_iegen_11_iegen_10_iegen_9x >= _iegen_21_iegen_11_iegen_10_iegen_9x_vals[i] && _iegen_21_iegen_11_iegen_10_iegen_9x <= _iegen_21_iegen_11_iegen_10_iegen_9x_vals[i+1]) _iegen_21_iegen_11_iegen_10_iegen_9prev = i; 
#define s151(__x0)   int _iegen_21_iegen_11_iegen_10k = _iegen_21_iegen_11_iegen_10_iegen_9prev; 
#define s152(__x0)   double _iegen_21_iegen_11_iegen_10result = 0.0; 
#define s153(__x0)   if(_iegen_21_iegen_11_iegen_10k < _iegen_21_iegen_11_iegen_10Spline.length) { double _iegen_21_iegen_11_iegen_10X = (_iegen_21_iegen_11_iegen_10x - _iegen_21_iegen_11_iegen_10Spline.x_vals[_iegen_21_iegen_11_iegen_10k])/(_iegen_21_iegen_11_iegen_10Spline.x_vals[_iegen_21_iegen_11_iegen_10k+1] - _iegen_21_iegen_11_iegen_10Spline.x_vals[_iegen_21_iegen_11_iegen_10k]); double _iegen_21_iegen_11_iegen_10A = _iegen_21_iegen_11_iegen_10Spline.slopes[_iegen_21_iegen_11_iegen_10k] * (_iegen_21_iegen_11_iegen_10Spline.x_vals[_iegen_21_iegen_11_iegen_10k+1] - _iegen_21_iegen_11_iegen_10Spline.x_vals[_iegen_21_iegen_11_iegen_10k]) - (_iegen_21_iegen_11_iegen_10Spline.f_vals[_iegen_21_iegen_11_iegen_10k+1] - _iegen_21_iegen_11_iegen_10Spline.f_vals[_iegen_21_iegen_11_iegen_10k]); double _iegen_21_iegen_11_iegen_10B = -_iegen_21_iegen_11_iegen_10Spline.slopes[_iegen_21_iegen_11_iegen_10k+1] * (_iegen_21_iegen_11_iegen_10Spline.x_vals[_iegen_21_iegen_11_iegen_10k+1] - _iegen_21_iegen_11_iegen_10Spline.x_vals[_iegen_21_iegen_11_iegen_10k]) + (_iegen_21_iegen_11_iegen_10Spline.f_vals[_iegen_21_iegen_11_iegen_10k+1] - _iegen_21_iegen_11_iegen_10Spline.f_vals[_iegen_21_iegen_11_iegen_10k]); _iegen_21_iegen_11_iegen_10result = (1.0 - _iegen_21_iegen_11_iegen_10X) * _iegen_21_iegen_11_iegen_10Spline.f_vals[_iegen_21_iegen_11_iegen_10k] + _iegen_21_iegen_11_iegen_10X * _iegen_21_iegen_11_iegen_10Spline.f_vals[_iegen_21_iegen_11_iegen_10k+1] + _iegen_21_iegen_11_iegen_10X * (1.0 - _iegen_21_iegen_11_iegen_10X) * (_iegen_21_iegen_11_iegen_10A * (1.0 - _iegen_21_iegen_11_iegen_10X ) + _iegen_21_iegen_11_iegen_10B * _iegen_21_iegen_11_iegen_10X);} 
#define s154(__x0)   double _iegen_21_iegen_11c_result = sqrt(gamR * _iegen_21_iegen_11_iegen_10result); 
#define s155(__x0)   double _iegen_21c_return = _iegen_21_iegen_11c_result; 
#define s156(__x0)   double _iegen_21_iegen_13x = _iegen_21r_eval; 
#define s157(__x0)   NaturalCubicSpline_1D & _iegen_21_iegen_13Spline = _iegen_21Temp_Spline; 
#define s158(__x0)   double _iegen_21_iegen_13_iegen_12x = _iegen_21_iegen_13x; 
#define s159(__x0)   double* _iegen_21_iegen_13_iegen_12x_vals = _iegen_21_iegen_13Spline.x_vals; 
#define s160(__x0)   int _iegen_21_iegen_13_iegen_12length = _iegen_21_iegen_13Spline.length; 
#define s161(__x0)   int& _iegen_21_iegen_13_iegen_12prev = _iegen_21_iegen_13Spline.accel; 
#define s162(__x0, i, __x2)   if(_iegen_21_iegen_13_iegen_12x >= _iegen_21_iegen_13_iegen_12x_vals[i] && _iegen_21_iegen_13_iegen_12x <= _iegen_21_iegen_13_iegen_12x_vals[i+1]) _iegen_21_iegen_13_iegen_12prev = i; 
#define s163(__x0)   int _iegen_21_iegen_13k = _iegen_21_iegen_13_iegen_12prev; 
#define s164(__x0)   double _iegen_21_iegen_13eval_spline_df_return = 0.0; 
#define s165(__x0)   if(_iegen_21_iegen_13k < _iegen_21_iegen_13Spline.length){double _iegen_21_iegen_13X = (_iegen_21_iegen_13x - _iegen_21_iegen_13Spline.x_vals[_iegen_21_iegen_13k])/(_iegen_21_iegen_13Spline.x_vals[_iegen_21_iegen_13k+1] - _iegen_21_iegen_13Spline.x_vals[_iegen_21_iegen_13k]); double _iegen_21_iegen_13A = _iegen_21_iegen_13Spline.slopes[_iegen_21_iegen_13k] * (_iegen_21_iegen_13Spline.x_vals[_iegen_21_iegen_13k+1] -_iegen_21_iegen_13Spline.x_vals[_iegen_21_iegen_13k]) - (_iegen_21_iegen_13Spline.f_vals[_iegen_21_iegen_13k+1] - _iegen_21_iegen_13Spline.f_vals[_iegen_21_iegen_13k]); double _iegen_21_iegen_13B = -_iegen_21_iegen_13Spline.slopes[_iegen_21_iegen_13k+1] * (_iegen_21_iegen_13Spline.x_vals[_iegen_21_iegen_13k+1] - _iegen_21_iegen_13Spline.x_vals[_iegen_21_iegen_13k]) + (_iegen_21_iegen_13Spline.f_vals[_iegen_21_iegen_13k+1] - _iegen_21_iegen_13Spline.f_vals[_iegen_21_iegen_13k]); _iegen_21_iegen_13eval_spline_df_return = (_iegen_21_iegen_13Spline.f_vals[_iegen_21_iegen_13k+1] - _iegen_21_iegen_13Spline.f_vals[_iegen_21_iegen_13k])/(_iegen_21_iegen_13Spline.x_vals[_iegen_21_iegen_13k+1] - _iegen_21_iegen_13Spline.x_vals[_iegen_21_iegen_13k]) + (1.0 - 2.0 * _iegen_21_iegen_13X) * (_iegen_21_iegen_13A * (1.0 - _iegen_21_iegen_13X) + _iegen_21_iegen_13B * _iegen_21_iegen_13X)/(_iegen_21_iegen_13Spline.x_vals[_iegen_21_iegen_13k+1] - _iegen_21_iegen_13Spline.x_vals[_iegen_21_iegen_13k])+ _iegen_21_iegen_13X * (1.0 - _iegen_21_iegen_13X) * (_iegen_21_iegen_13B - _iegen_21_iegen_13A)/(_iegen_21_iegen_13Spline.x_vals[_iegen_21_iegen_13k+1] - _iegen_21_iegen_13Spline.x_vals[_iegen_21_iegen_13k]);} 
#define s166(__x0)   double _iegen_21eval_spline_df_return = _iegen_21_iegen_13eval_spline_df_return; 
#define s167(__x0)   if(_iegen_21n==0){_iegen_21c_diff_return = gamR / (2.0 * _iegen_21c_return) * _iegen_21eval_spline_df_return;} 
#define s168(__x0)   sources.dc[1] = _iegen_21c_diff_return; 
#define s169(__x0)   sources.dw[1] = 0; 
#define s170(__x0)   double _iegen_22r = r; 
#define s171(__x0)   double _iegen_22theta = theta; 
#define s172(__x0)   double _iegen_22phi = phi; 
#define s173(__x0)   int _iegen_22n = 1; 
#define s174(__x0)   NaturalCubicSpline_1D & _iegen_22Windv_Spline = spl.Windv_Spline; 
#define s175(__x0)   double _iegen_22r_eval = min(_iegen_22r, r_max); _iegen_22r_eval = max(_iegen_22r_eval, r_min); 
#define s176(__x0)   double _iegen_22v_diff_return = 0.0 
#define s177(__x0)   double _iegen_22_iegen_16x = _iegen_22r_eval; 
#define s178(__x0)   NaturalCubicSpline_1D & _iegen_22_iegen_16Spline = _iegen_22Windv_Spline; 
#define s179(__x0)   double _iegen_22_iegen_16_iegen_15x = _iegen_22_iegen_16x; 
#define s180(__x0)   double* _iegen_22_iegen_16_iegen_15x_vals = _iegen_22_iegen_16Spline.x_vals; 
#define s181(__x0)   int _iegen_22_iegen_16_iegen_15length = _iegen_22_iegen_16Spline.length; 
#define s182(__x0)   int& _iegen_22_iegen_16_iegen_15prev = _iegen_22_iegen_16Spline.accel; 
#define s183(__x0, i, __x2)   if(_iegen_22_iegen_16_iegen_15x >= _iegen_22_iegen_16_iegen_15x_vals[i] && _iegen_22_iegen_16_iegen_15x <= _iegen_22_iegen_16_iegen_15x_vals[i+1]) _iegen_22_iegen_16_iegen_15prev = i; 
#define s184(__x0)   int _iegen_22_iegen_16k = _iegen_22_iegen_16_iegen_15prev; 
#define s185(__x0)   double _iegen_22_iegen_16eval_spline_df_return = 0.0; 
#define s186(__x0)   if(_iegen_22_iegen_16k < _iegen_22_iegen_16Spline.length){double _iegen_22_iegen_16X = (_iegen_22_iegen_16x - _iegen_22_iegen_16Spline.x_vals[_iegen_22_iegen_16k])/(_iegen_22_iegen_16Spline.x_vals[_iegen_22_iegen_16k+1] - _iegen_22_iegen_16Spline.x_vals[_iegen_22_iegen_16k]); double _iegen_22_iegen_16A = _iegen_22_iegen_16Spline.slopes[_iegen_22_iegen_16k] * (_iegen_22_iegen_16Spline.x_vals[_iegen_22_iegen_16k+1] -_iegen_22_iegen_16Spline.x_vals[_iegen_22_iegen_16k]) - (_iegen_22_iegen_16Spline.f_vals[_iegen_22_iegen_16k+1] - _iegen_22_iegen_16Spline.f_vals[_iegen_22_iegen_16k]); double _iegen_22_iegen_16B = -_iegen_22_iegen_16Spline.slopes[_iegen_22_iegen_16k+1] * (_iegen_22_iegen_16Spline.x_vals[_iegen_22_iegen_16k+1] - _iegen_22_iegen_16Spline.x_vals[_iegen_22_iegen_16k]) + (_iegen_22_iegen_16Spline.f_vals[_iegen_22_iegen_16k+1] - _iegen_22_iegen_16Spline.f_vals[_iegen_22_iegen_16k]); _iegen_22_iegen_16eval_spline_df_return = (_iegen_22_iegen_16Spline.f_vals[_iegen_22_iegen_16k+1] - _iegen_22_iegen_16Spline.f_vals[_iegen_22_iegen_16k])/(_iegen_22_iegen_16Spline.x_vals[_iegen_22_iegen_16k+1] - _iegen_22_iegen_16Spline.x_vals[_iegen_22_iegen_16k]) + (1.0 - 2.0 * _iegen_22_iegen_16X) * (_iegen_22_iegen_16A * (1.0 - _iegen_22_iegen_16X) + _iegen_22_iegen_16B * _iegen_22_iegen_16X)/(_iegen_22_iegen_16Spline.x_vals[_iegen_22_iegen_16k+1] - _iegen_22_iegen_16Spline.x_vals[_iegen_22_iegen_16k])+ _iegen_22_iegen_16X * (1.0 - _iegen_22_iegen_16X) * (_iegen_22_iegen_16B - _iegen_22_iegen_16A)/(_iegen_22_iegen_16Spline.x_vals[_iegen_22_iegen_16k+1] - _iegen_22_iegen_16Spline.x_vals[_iegen_22_iegen_16k]);} 
#define s187(__x0)   double _iegen_22eval_Spline_df_return = _iegen_22_iegen_16eval_spline_df_return; 
#define s188(__x0)   if(_iegen_22n==0){_iegen_22v_diff_return = _iegen_22eval_Spline_df_return;} 
#define s189(__x0)   sources.dv[1] = _iegen_22v_diff_return; 
#define s190(__x0)   double _iegen_23r = r; 
#define s191(__x0)   double _iegen_23theta = theta; 
#define s192(__x0)   double _iegen_23phi = phi; 
#define s193(__x0)   int _iegen_23n = 1; 
#define s194(__x0)   NaturalCubicSpline_1D & _iegen_23Windu_Spline = spl.Windu_Spline; 
#define s195(__x0)   double _iegen_23r_eval = min(_iegen_23r, r_max); _iegen_23r_eval = max(_iegen_23r_eval, r_min); 
#define s196(__x0)   double _iegen_23u_diff_return = 0.0 
#define s197(__x0)   double _iegen_23_iegen_19x = _iegen_23r_eval; 
#define s198(__x0)   NaturalCubicSpline_1D & _iegen_23_iegen_19Spline = _iegen_23Windu_Spline; 
#define s199(__x0)   double _iegen_23_iegen_19_iegen_18x = _iegen_23_iegen_19x; 
#define s200(__x0)   double* _iegen_23_iegen_19_iegen_18x_vals = _iegen_23_iegen_19Spline.x_vals; 
#define s201(__x0)   int _iegen_23_iegen_19_iegen_18length = _iegen_23_iegen_19Spline.length; 
#define s202(__x0)   int& _iegen_23_iegen_19_iegen_18prev = _iegen_23_iegen_19Spline.accel; 
#define s203(__x0, i, __x2)   if(_iegen_23_iegen_19_iegen_18x >= _iegen_23_iegen_19_iegen_18x_vals[i] && _iegen_23_iegen_19_iegen_18x <= _iegen_23_iegen_19_iegen_18x_vals[i+1]) _iegen_23_iegen_19_iegen_18prev = i; 
#define s204(__x0)   int _iegen_23_iegen_19k = _iegen_23_iegen_19_iegen_18prev; 
#define s205(__x0)   double _iegen_23_iegen_19eval_spline_df_return = 0.0; 
#define s206(__x0)   if(_iegen_23_iegen_19k < _iegen_23_iegen_19Spline.length){double _iegen_23_iegen_19X = (_iegen_23_iegen_19x - _iegen_23_iegen_19Spline.x_vals[_iegen_23_iegen_19k])/(_iegen_23_iegen_19Spline.x_vals[_iegen_23_iegen_19k+1] - _iegen_23_iegen_19Spline.x_vals[_iegen_23_iegen_19k]); double _iegen_23_iegen_19A = _iegen_23_iegen_19Spline.slopes[_iegen_23_iegen_19k] * (_iegen_23_iegen_19Spline.x_vals[_iegen_23_iegen_19k+1] -_iegen_23_iegen_19Spline.x_vals[_iegen_23_iegen_19k]) - (_iegen_23_iegen_19Spline.f_vals[_iegen_23_iegen_19k+1] - _iegen_23_iegen_19Spline.f_vals[_iegen_23_iegen_19k]); double _iegen_23_iegen_19B = -_iegen_23_iegen_19Spline.slopes[_iegen_23_iegen_19k+1] * (_iegen_23_iegen_19Spline.x_vals[_iegen_23_iegen_19k+1] - _iegen_23_iegen_19Spline.x_vals[_iegen_23_iegen_19k]) + (_iegen_23_iegen_19Spline.f_vals[_iegen_23_iegen_19k+1] - _iegen_23_iegen_19Spline.f_vals[_iegen_23_iegen_19k]); _iegen_23_iegen_19eval_spline_df_return = (_iegen_23_iegen_19Spline.f_vals[_iegen_23_iegen_19k+1] - _iegen_23_iegen_19Spline.f_vals[_iegen_23_iegen_19k])/(_iegen_23_iegen_19Spline.x_vals[_iegen_23_iegen_19k+1] - _iegen_23_iegen_19Spline.x_vals[_iegen_23_iegen_19k]) + (1.0 - 2.0 * _iegen_23_iegen_19X) * (_iegen_23_iegen_19A * (1.0 - _iegen_23_iegen_19X) + _iegen_23_iegen_19B * _iegen_23_iegen_19X)/(_iegen_23_iegen_19Spline.x_vals[_iegen_23_iegen_19k+1] - _iegen_23_iegen_19Spline.x_vals[_iegen_23_iegen_19k])+ _iegen_23_iegen_19X * (1.0 - _iegen_23_iegen_19X) * (_iegen_23_iegen_19B - _iegen_23_iegen_19A)/(_iegen_23_iegen_19Spline.x_vals[_iegen_23_iegen_19k+1] - _iegen_23_iegen_19Spline.x_vals[_iegen_23_iegen_19k]);} 
#define s207(__x0)   double _iegen_23eval_Spline_df_return = _iegen_23_iegen_19eval_spline_df_return; 
#define s208(__x0)   if(_iegen_23n==0){_iegen_23u_diff_return = _iegen_23eval_Spline_df_return;} 
#define s209(__x0)   sources.du[1] = _iegen_23u_diff_return; 
#define s210(__x0)   double _iegen_24r = r; 
#define s211(__x0)   double _iegen_24theta = theta; 
#define s212(__x0)   double _iegen_24phi = phi; 
#define s213(__x0)   int _iegen_24n = 2; 
#define s214(__x0)   NaturalCubicSpline_1D & _iegen_24Temp_Spline = spl.Temp_Spline; 
#define s215(__x0)   double _iegen_24r_eval = min(_iegen_24r, r_max); _iegen_24r_eval = max(_iegen_24r_eval, r_min); 
#define s216(__x0)   double _iegen_24c_diff_return = 0.0 
#define s217(__x0)   double _iegen_24_iegen_11r = _iegen_24r; 
#define s218(__x0)   double _iegen_24_iegen_11theta = _iegen_24theta; 
#define s219(__x0)   double _iegen_24_iegen_11phi = _iegen_24phi; 
#define s220(__x0)   NaturalCubicSpline_1D & _iegen_24_iegen_11Temp_Spline = _iegen_24Temp_Spline; 
#define s221(__x0)   double _iegen_24_iegen_11r_eval = min(_iegen_24_iegen_11r, r_max); 
#define s222(__x0)   _iegen_24_iegen_11r_eval = max(_iegen_24_iegen_11r_eval, r_min); 
#define s223(__x0)   double _iegen_24_iegen_11_iegen_10x = _iegen_24_iegen_11r_eval; 
#define s224(__x0)   struct NaturalCubicSpline_1D & _iegen_24_iegen_11_iegen_10Spline = _iegen_24_iegen_11Temp_Spline; 
#define s225(__x0)   double _iegen_24_iegen_11_iegen_10_iegen_9x = _iegen_24_iegen_11_iegen_10x; 
#define s226(__x0)   double* _iegen_24_iegen_11_iegen_10_iegen_9x_vals = _iegen_24_iegen_11_iegen_10Spline.x_vals; 
#define s227(__x0)   int _iegen_24_iegen_11_iegen_10_iegen_9length = _iegen_24_iegen_11_iegen_10Spline.length; 
#define s228(__x0)   int& _iegen_24_iegen_11_iegen_10_iegen_9prev = _iegen_24_iegen_11_iegen_10Spline.accel; 
#define s229(__x0, i, __x2)   if(_iegen_24_iegen_11_iegen_10_iegen_9x >= _iegen_24_iegen_11_iegen_10_iegen_9x_vals[i] && _iegen_24_iegen_11_iegen_10_iegen_9x <= _iegen_24_iegen_11_iegen_10_iegen_9x_vals[i+1]) _iegen_24_iegen_11_iegen_10_iegen_9prev = i; 
#define s230(__x0)   int _iegen_24_iegen_11_iegen_10k = _iegen_24_iegen_11_iegen_10_iegen_9prev; 
#define s231(__x0)   double _iegen_24_iegen_11_iegen_10result = 0.0; 
#define s232(__x0)   if(_iegen_24_iegen_11_iegen_10k < _iegen_24_iegen_11_iegen_10Spline.length) { double _iegen_24_iegen_11_iegen_10X = (_iegen_24_iegen_11_iegen_10x - _iegen_24_iegen_11_iegen_10Spline.x_vals[_iegen_24_iegen_11_iegen_10k])/(_iegen_24_iegen_11_iegen_10Spline.x_vals[_iegen_24_iegen_11_iegen_10k+1] - _iegen_24_iegen_11_iegen_10Spline.x_vals[_iegen_24_iegen_11_iegen_10k]); double _iegen_24_iegen_11_iegen_10A = _iegen_24_iegen_11_iegen_10Spline.slopes[_iegen_24_iegen_11_iegen_10k] * (_iegen_24_iegen_11_iegen_10Spline.x_vals[_iegen_24_iegen_11_iegen_10k+1] - _iegen_24_iegen_11_iegen_10Spline.x_vals[_iegen_24_iegen_11_iegen_10k]) - (_iegen_24_iegen_11_iegen_10Spline.f_vals[_iegen_24_iegen_11_iegen_10k+1] - _iegen_24_iegen_11_iegen_10Spline.f_vals[_iegen_24_iegen_11_iegen_10k]); double _iegen_24_iegen_11_iegen_10B = -_iegen_24_iegen_11_iegen_10Spline.slopes[_iegen_24_iegen_11_iegen_10k+1] * (_iegen_24_iegen_11_iegen_10Spline.x_vals[_iegen_24_iegen_11_iegen_10k+1] - _iegen_24_iegen_11_iegen_10Spline.x_vals[_iegen_24_iegen_11_iegen_10k]) + (_iegen_24_iegen_11_iegen_10Spline.f_vals[_iegen_24_iegen_11_iegen_10k+1] - _iegen_24_iegen_11_iegen_10Spline.f_vals[_iegen_24_iegen_11_iegen_10k]); _iegen_24_iegen_11_iegen_10result = (1.0 - _iegen_24_iegen_11_iegen_10X) * _iegen_24_iegen_11_iegen_10Spline.f_vals[_iegen_24_iegen_11_iegen_10k] + _iegen_24_iegen_11_iegen_10X * _iegen_24_iegen_11_iegen_10Spline.f_vals[_iegen_24_iegen_11_iegen_10k+1] + _iegen_24_iegen_11_iegen_10X * (1.0 - _iegen_24_iegen_11_iegen_10X) * (_iegen_24_iegen_11_iegen_10A * (1.0 - _iegen_24_iegen_11_iegen_10X ) + _iegen_24_iegen_11_iegen_10B * _iegen_24_iegen_11_iegen_10X);} 
#define s233(__x0)   double _iegen_24_iegen_11c_result = sqrt(gamR * _iegen_24_iegen_11_iegen_10result); 
#define s234(__x0)   double _iegen_24c_return = _iegen_24_iegen_11c_result; 
#define s235(__x0)   double _iegen_24_iegen_13x = _iegen_24r_eval; 
#define s236(__x0)   NaturalCubicSpline_1D & _iegen_24_iegen_13Spline = _iegen_24Temp_Spline; 
#define s237(__x0)   double _iegen_24_iegen_13_iegen_12x = _iegen_24_iegen_13x; 
#define s238(__x0)   double* _iegen_24_iegen_13_iegen_12x_vals = _iegen_24_iegen_13Spline.x_vals; 
#define s239(__x0)   int _iegen_24_iegen_13_iegen_12length = _iegen_24_iegen_13Spline.length; 
#define s240(__x0)   int& _iegen_24_iegen_13_iegen_12prev = _iegen_24_iegen_13Spline.accel; 
#define s241(__x0, i, __x2)   if(_iegen_24_iegen_13_iegen_12x >= _iegen_24_iegen_13_iegen_12x_vals[i] && _iegen_24_iegen_13_iegen_12x <= _iegen_24_iegen_13_iegen_12x_vals[i+1]) _iegen_24_iegen_13_iegen_12prev = i; 
#define s242(__x0)   int _iegen_24_iegen_13k = _iegen_24_iegen_13_iegen_12prev; 
#define s243(__x0)   double _iegen_24_iegen_13eval_spline_df_return = 0.0; 
#define s244(__x0)   if(_iegen_24_iegen_13k < _iegen_24_iegen_13Spline.length){double _iegen_24_iegen_13X = (_iegen_24_iegen_13x - _iegen_24_iegen_13Spline.x_vals[_iegen_24_iegen_13k])/(_iegen_24_iegen_13Spline.x_vals[_iegen_24_iegen_13k+1] - _iegen_24_iegen_13Spline.x_vals[_iegen_24_iegen_13k]); double _iegen_24_iegen_13A = _iegen_24_iegen_13Spline.slopes[_iegen_24_iegen_13k] * (_iegen_24_iegen_13Spline.x_vals[_iegen_24_iegen_13k+1] -_iegen_24_iegen_13Spline.x_vals[_iegen_24_iegen_13k]) - (_iegen_24_iegen_13Spline.f_vals[_iegen_24_iegen_13k+1] - _iegen_24_iegen_13Spline.f_vals[_iegen_24_iegen_13k]); double _iegen_24_iegen_13B = -_iegen_24_iegen_13Spline.slopes[_iegen_24_iegen_13k+1] * (_iegen_24_iegen_13Spline.x_vals[_iegen_24_iegen_13k+1] - _iegen_24_iegen_13Spline.x_vals[_iegen_24_iegen_13k]) + (_iegen_24_iegen_13Spline.f_vals[_iegen_24_iegen_13k+1] - _iegen_24_iegen_13Spline.f_vals[_iegen_24_iegen_13k]); _iegen_24_iegen_13eval_spline_df_return = (_iegen_24_iegen_13Spline.f_vals[_iegen_24_iegen_13k+1] - _iegen_24_iegen_13Spline.f_vals[_iegen_24_iegen_13k])/(_iegen_24_iegen_13Spline.x_vals[_iegen_24_iegen_13k+1] - _iegen_24_iegen_13Spline.x_vals[_iegen_24_iegen_13k]) + (1.0 - 2.0 * _iegen_24_iegen_13X) * (_iegen_24_iegen_13A * (1.0 - _iegen_24_iegen_13X) + _iegen_24_iegen_13B * _iegen_24_iegen_13X)/(_iegen_24_iegen_13Spline.x_vals[_iegen_24_iegen_13k+1] - _iegen_24_iegen_13Spline.x_vals[_iegen_24_iegen_13k])+ _iegen_24_iegen_13X * (1.0 - _iegen_24_iegen_13X) * (_iegen_24_iegen_13B - _iegen_24_iegen_13A)/(_iegen_24_iegen_13Spline.x_vals[_iegen_24_iegen_13k+1] - _iegen_24_iegen_13Spline.x_vals[_iegen_24_iegen_13k]);} 
#define s245(__x0)   double _iegen_24eval_spline_df_return = _iegen_24_iegen_13eval_spline_df_return; 
#define s246(__x0)   if(_iegen_24n==0){_iegen_24c_diff_return = gamR / (2.0 * _iegen_24c_return) * _iegen_24eval_spline_df_return;} 
#define s247(__x0)   sources.dc[2] = _iegen_24c_diff_return; 
#define s248(__x0)   sources.dw[2] = 0; 
#define s249(__x0)   double _iegen_25r = r; 
#define s250(__x0)   double _iegen_25theta = theta; 
#define s251(__x0)   double _iegen_25phi = phi; 
#define s252(__x0)   int _iegen_25n = 2; 
#define s253(__x0)   NaturalCubicSpline_1D & _iegen_25Windv_Spline = spl.Windv_Spline; 
#define s254(__x0)   double _iegen_25r_eval = min(_iegen_25r, r_max); _iegen_25r_eval = max(_iegen_25r_eval, r_min); 
#define s255(__x0)   double _iegen_25v_diff_return = 0.0 
#define s256(__x0)   double _iegen_25_iegen_16x = _iegen_25r_eval; 
#define s257(__x0)   NaturalCubicSpline_1D & _iegen_25_iegen_16Spline = _iegen_25Windv_Spline; 
#define s258(__x0)   double _iegen_25_iegen_16_iegen_15x = _iegen_25_iegen_16x; 
#define s259(__x0)   double* _iegen_25_iegen_16_iegen_15x_vals = _iegen_25_iegen_16Spline.x_vals; 
#define s260(__x0)   int _iegen_25_iegen_16_iegen_15length = _iegen_25_iegen_16Spline.length; 
#define s261(__x0)   int& _iegen_25_iegen_16_iegen_15prev = _iegen_25_iegen_16Spline.accel; 
#define s262(__x0, i, __x2)   if(_iegen_25_iegen_16_iegen_15x >= _iegen_25_iegen_16_iegen_15x_vals[i] && _iegen_25_iegen_16_iegen_15x <= _iegen_25_iegen_16_iegen_15x_vals[i+1]) _iegen_25_iegen_16_iegen_15prev = i; 
#define s263(__x0)   int _iegen_25_iegen_16k = _iegen_25_iegen_16_iegen_15prev; 
#define s264(__x0)   double _iegen_25_iegen_16eval_spline_df_return = 0.0; 
#define s265(__x0)   if(_iegen_25_iegen_16k < _iegen_25_iegen_16Spline.length){double _iegen_25_iegen_16X = (_iegen_25_iegen_16x - _iegen_25_iegen_16Spline.x_vals[_iegen_25_iegen_16k])/(_iegen_25_iegen_16Spline.x_vals[_iegen_25_iegen_16k+1] - _iegen_25_iegen_16Spline.x_vals[_iegen_25_iegen_16k]); double _iegen_25_iegen_16A = _iegen_25_iegen_16Spline.slopes[_iegen_25_iegen_16k] * (_iegen_25_iegen_16Spline.x_vals[_iegen_25_iegen_16k+1] -_iegen_25_iegen_16Spline.x_vals[_iegen_25_iegen_16k]) - (_iegen_25_iegen_16Spline.f_vals[_iegen_25_iegen_16k+1] - _iegen_25_iegen_16Spline.f_vals[_iegen_25_iegen_16k]); double _iegen_25_iegen_16B = -_iegen_25_iegen_16Spline.slopes[_iegen_25_iegen_16k+1] * (_iegen_25_iegen_16Spline.x_vals[_iegen_25_iegen_16k+1] - _iegen_25_iegen_16Spline.x_vals[_iegen_25_iegen_16k]) + (_iegen_25_iegen_16Spline.f_vals[_iegen_25_iegen_16k+1] - _iegen_25_iegen_16Spline.f_vals[_iegen_25_iegen_16k]); _iegen_25_iegen_16eval_spline_df_return = (_iegen_25_iegen_16Spline.f_vals[_iegen_25_iegen_16k+1] - _iegen_25_iegen_16Spline.f_vals[_iegen_25_iegen_16k])/(_iegen_25_iegen_16Spline.x_vals[_iegen_25_iegen_16k+1] - _iegen_25_iegen_16Spline.x_vals[_iegen_25_iegen_16k]) + (1.0 - 2.0 * _iegen_25_iegen_16X) * (_iegen_25_iegen_16A * (1.0 - _iegen_25_iegen_16X) + _iegen_25_iegen_16B * _iegen_25_iegen_16X)/(_iegen_25_iegen_16Spline.x_vals[_iegen_25_iegen_16k+1] - _iegen_25_iegen_16Spline.x_vals[_iegen_25_iegen_16k])+ _iegen_25_iegen_16X * (1.0 - _iegen_25_iegen_16X) * (_iegen_25_iegen_16B - _iegen_25_iegen_16A)/(_iegen_25_iegen_16Spline.x_vals[_iegen_25_iegen_16k+1] - _iegen_25_iegen_16Spline.x_vals[_iegen_25_iegen_16k]);} 
#define s266(__x0)   double _iegen_25eval_Spline_df_return = _iegen_25_iegen_16eval_spline_df_return; 
#define s267(__x0)   if(_iegen_25n==0){_iegen_25v_diff_return = _iegen_25eval_Spline_df_return;} 
#define s268(__x0)   sources.dv[2] = _iegen_25v_diff_return; 
#define s269(__x0)   double _iegen_26r = r; 
#define s270(__x0)   double _iegen_26theta = theta; 
#define s271(__x0)   double _iegen_26phi = phi; 
#define s272(__x0)   int _iegen_26n = 2; 
#define s273(__x0)   NaturalCubicSpline_1D & _iegen_26Windu_Spline = spl.Windu_Spline; 
#define s274(__x0)   double _iegen_26r_eval = min(_iegen_26r, r_max); _iegen_26r_eval = max(_iegen_26r_eval, r_min); 
#define s275(__x0)   double _iegen_26u_diff_return = 0.0 
#define s276(__x0)   double _iegen_26_iegen_19x = _iegen_26r_eval; 
#define s277(__x0)   NaturalCubicSpline_1D & _iegen_26_iegen_19Spline = _iegen_26Windu_Spline; 
#define s278(__x0)   double _iegen_26_iegen_19_iegen_18x = _iegen_26_iegen_19x; 
#define s279(__x0)   double* _iegen_26_iegen_19_iegen_18x_vals = _iegen_26_iegen_19Spline.x_vals; 
#define s280(__x0)   int _iegen_26_iegen_19_iegen_18length = _iegen_26_iegen_19Spline.length; 
#define s281(__x0)   int& _iegen_26_iegen_19_iegen_18prev = _iegen_26_iegen_19Spline.accel; 
#define s282(__x0, i, __x2)   if(_iegen_26_iegen_19_iegen_18x >= _iegen_26_iegen_19_iegen_18x_vals[i] && _iegen_26_iegen_19_iegen_18x <= _iegen_26_iegen_19_iegen_18x_vals[i+1]) _iegen_26_iegen_19_iegen_18prev = i; 
#define s283(__x0)   int _iegen_26_iegen_19k = _iegen_26_iegen_19_iegen_18prev; 
#define s284(__x0)   double _iegen_26_iegen_19eval_spline_df_return = 0.0; 
#define s285(__x0)   if(_iegen_26_iegen_19k < _iegen_26_iegen_19Spline.length){double _iegen_26_iegen_19X = (_iegen_26_iegen_19x - _iegen_26_iegen_19Spline.x_vals[_iegen_26_iegen_19k])/(_iegen_26_iegen_19Spline.x_vals[_iegen_26_iegen_19k+1] - _iegen_26_iegen_19Spline.x_vals[_iegen_26_iegen_19k]); double _iegen_26_iegen_19A = _iegen_26_iegen_19Spline.slopes[_iegen_26_iegen_19k] * (_iegen_26_iegen_19Spline.x_vals[_iegen_26_iegen_19k+1] -_iegen_26_iegen_19Spline.x_vals[_iegen_26_iegen_19k]) - (_iegen_26_iegen_19Spline.f_vals[_iegen_26_iegen_19k+1] - _iegen_26_iegen_19Spline.f_vals[_iegen_26_iegen_19k]); double _iegen_26_iegen_19B = -_iegen_26_iegen_19Spline.slopes[_iegen_26_iegen_19k+1] * (_iegen_26_iegen_19Spline.x_vals[_iegen_26_iegen_19k+1] - _iegen_26_iegen_19Spline.x_vals[_iegen_26_iegen_19k]) + (_iegen_26_iegen_19Spline.f_vals[_iegen_26_iegen_19k+1] - _iegen_26_iegen_19Spline.f_vals[_iegen_26_iegen_19k]); _iegen_26_iegen_19eval_spline_df_return = (_iegen_26_iegen_19Spline.f_vals[_iegen_26_iegen_19k+1] - _iegen_26_iegen_19Spline.f_vals[_iegen_26_iegen_19k])/(_iegen_26_iegen_19Spline.x_vals[_iegen_26_iegen_19k+1] - _iegen_26_iegen_19Spline.x_vals[_iegen_26_iegen_19k]) + (1.0 - 2.0 * _iegen_26_iegen_19X) * (_iegen_26_iegen_19A * (1.0 - _iegen_26_iegen_19X) + _iegen_26_iegen_19B * _iegen_26_iegen_19X)/(_iegen_26_iegen_19Spline.x_vals[_iegen_26_iegen_19k+1] - _iegen_26_iegen_19Spline.x_vals[_iegen_26_iegen_19k])+ _iegen_26_iegen_19X * (1.0 - _iegen_26_iegen_19X) * (_iegen_26_iegen_19B - _iegen_26_iegen_19A)/(_iegen_26_iegen_19Spline.x_vals[_iegen_26_iegen_19k+1] - _iegen_26_iegen_19Spline.x_vals[_iegen_26_iegen_19k]);} 
#define s286(__x0)   double _iegen_26eval_Spline_df_return = _iegen_26_iegen_19eval_spline_df_return; 
#define s287(__x0)   if(_iegen_26n==0){_iegen_26u_diff_return = _iegen_26eval_Spline_df_return;} 
#define s288(__x0)   sources.du[2] = _iegen_26u_diff_return; 
#define s289(__x0)   sources.nu_mag = sqrt( nu[0]*nu[0] + nu[1]*nu[1] + nu[2]*nu[2]); 
#define s290(__x0)   sources.c_gr[0] =  sources.c*nu[0]/sources.nu_mag + sources.w; 
#define s291(__x0)   sources.c_gr[1] =  sources.c*nu[1]/sources.nu_mag + sources.v; 
#define s292(__x0)   sources.c_gr[2] =  sources.c*nu[2]/sources.nu_mag + sources.u; 
#define s293(__x0)   sources.c_gr_mag = sqrt(pow(sources.c_gr[0],2) + pow(sources.c_gr[1],2) + pow(sources.c_gr[2],2)); 
#define s294(__x0)   sources.GeoCoeff[0] = 1.0; 
#define s295(__x0)   sources.GeoCoeff[1] = 1.0/r 
#define s296(__x0)   sources.GeoCoeff[2] = 1.0/(r*cos(theta)); 
#define s297(__x0)   sources.GeoTerms[0] = 0.0; 
#define s298(__x0)   sources.GeoTerms[1] = (nu[0]*sources.v - nu[1]*sources.w); 
#define s299(__x0)   sources.GeoTerms[2] = (nu[0]*sources.u - nu[2]*sources.w)*cos(theta) + (nu[1]*sources.u - nu[2]*sources.v)*sin(theta); 
#define s300(__x0)   sources.GeoTerms[0] += 1.0/r * (nu[1]*sources.c_gr[1] + nu[2]*sources.c_gr[2]); 
#define s301(__x0)   sources.GeoTerms[1] += -nu[0]*sources.c_gr[1] + nu[2]*sources.c_gr[2]*tan(theta); 


//t1 = 0; 
unsigned int t2 = 0; 
//t3 = 0; 

s0(1);
s1(2);
s2(3);
s3(4);
s4(5);
s5(6);
s6(7);
s7(8);
s8(9);
s9(10);
s10(11);
s11(12);
for(t2 = 0; t2 <= _iegen_2_iegen_1_iegen_0length-1; t2++) {
  s12(13,t2,0);
}
s13(14);
s14(15);
s15(16);
s16(17);
s17(18);
s18(19);
s19(20);
s20(21);
s21(22);
s22(23);
s23(24);
s24(25);
s25(26);
s26(27);
s27(28);
s28(29);
s29(30);
for(t2 = 0; t2 <= _iegen_5_iegen_4_iegen_3length-1; t2++) {
  s30(31,t2,0);
}
s31(32);
s32(33);
s33(34);
s34(35);
s35(36);
s36(37);
s37(38);
s38(39);
s39(40);
s40(41);
s41(42);
s42(43);
s43(44);
s44(45);
s45(46);
s46(47);
for(t2 = 0; t2 <= _iegen_8_iegen_7_iegen_6length-1; t2++) {
  s47(48,t2,0);
}
s48(49);
s49(50);
s50(51);
s51(52);
s52(53);
s53(54);
s54(55);
s55(56);
s56(57);
s57(58);
s58(59);
s59(60);
s60(61);
s61(62);
s62(63);
s63(64);
s64(65);
s65(66);
s66(67);
s67(68);
s68(69);
s69(70);
s70(71);
for(t2 = 0; t2 <= _iegen_14_iegen_11_iegen_10_iegen_9length-1; t2++) {
  s71(72,t2,0);
}
s72(73);
s73(74);
s74(75);
s75(76);
s76(77);
s77(78);
s78(79);
s79(80);
s80(81);
s81(82);
s82(83);
for(t2 = 0; t2 <= _iegen_14_iegen_13_iegen_12length-1; t2++) {
  s83(84,t2,0);
}
s84(85);
s85(86);
s86(87);
s87(88);
s88(89);
s89(90);
s90(91);
s91(92);
s92(93);
s93(94);
s94(95);
s95(96);
s96(97);
s97(98);
s98(99);
s99(100);
s100(101);
s101(102);
s102(103);
s103(104);
for(t2 = 0; t2 <= _iegen_17_iegen_16_iegen_15length-1; t2++) {
  s104(105,t2,0);
}
s105(106);
s106(107);
s107(108);
s108(109);
s109(110);
s110(111);
s111(112);
s112(113);
s113(114);
s114(115);
s115(116);
s116(117);
s117(118);
s118(119);
s119(120);
s120(121);
s121(122);
s122(123);
s123(124);
for(t2 = 0; t2 <= _iegen_20_iegen_19_iegen_18length-1; t2++) {
  s124(125,t2,0);
}
s125(126);
s126(127);
s127(128);
s128(129);
s129(130);
s130(131);
s131(132);
s132(133);
s133(134);
s134(135);
s135(136);
s136(137);
s137(138);
s138(139);
s139(140);
s140(141);
s141(142);
s142(143);
s143(144);
s144(145);
s145(146);
s146(147);
s147(148);
s148(149);
s149(150);
for(t2 = 0; t2 <= _iegen_21_iegen_11_iegen_10_iegen_9length-1; t2++) {
  s150(151,t2,0);
}
s151(152);
s152(153);
s153(154);
s154(155);
s155(156);
s156(157);
s157(158);
s158(159);
s159(160);
s160(161);
s161(162);
for(t2 = 0; t2 <= _iegen_21_iegen_13_iegen_12length-1; t2++) {
  s162(163,t2,0);
}
s163(164);
s164(165);
s165(166);
s166(167);
s167(168);
s168(169);
s169(170);
s170(171);
s171(172);
s172(173);
s173(174);
s174(175);
s175(176);
s176(177);
s177(178);
s178(179);
s179(180);
s180(181);
s181(182);
s182(183);
for(t2 = 0; t2 <= _iegen_22_iegen_16_iegen_15length-1; t2++) {
  s183(184,t2,0);
}
s184(185);
s185(186);
s186(187);
s187(188);
s188(189);
s189(190);
s190(191);
s191(192);
s192(193);
s193(194);
s194(195);
s195(196);
s196(197);
s197(198);
s198(199);
s199(200);
s200(201);
s201(202);
s202(203);
for(t2 = 0; t2 <= _iegen_23_iegen_19_iegen_18length-1; t2++) {
  s203(204,t2,0);
}
s204(205);
s205(206);
s206(207);
s207(208);
s208(209);
s209(210);
s210(211);
s211(212);
s212(213);
s213(214);
s214(215);
s215(216);
s216(217);
s217(218);
s218(219);
s219(220);
s220(221);
s221(222);
s222(223);
s223(224);
s224(225);
s225(226);
s226(227);
s227(228);
s228(229);
for(t2 = 0; t2 <= _iegen_24_iegen_11_iegen_10_iegen_9length-1; t2++) {
  s229(230,t2,0);
}
s230(231);
s231(232);
s232(233);
s233(234);
s234(235);
s235(236);
s236(237);
s237(238);
s238(239);
s239(240);
s240(241);
for(t2 = 0; t2 <= _iegen_24_iegen_13_iegen_12length-1; t2++) {
  s241(242,t2,0);
}
s242(243);
s243(244);
s244(245);
s245(246);
s246(247);
s247(248);
s248(249);
s249(250);
s250(251);
s251(252);
s252(253);
s253(254);
s254(255);
s255(256);
s256(257);
s257(258);
s258(259);
s259(260);
s260(261);
s261(262);
for(t2 = 0; t2 <= _iegen_25_iegen_16_iegen_15length-1; t2++) {
  s262(263,t2,0);
}
s263(264);
s264(265);
s265(266);
s266(267);
s267(268);
s268(269);
s269(270);
s270(271);
s271(272);
s272(273);
s273(274);
s274(275);
s275(276);
s276(277);
s277(278);
s278(279);
s279(280);
s280(281);
s281(282);
for(t2 = 0; t2 <= _iegen_26_iegen_19_iegen_18length-1; t2++) {
  s282(283,t2,0);
}
s283(284);
s284(285);
s285(286);
s286(287);
s287(288);
s288(289);
s289(290);
s290(291);
s291(292);
s292(293);
s293(294);
s294(295);
s295(296);
s296(297);
s297(298);
s298(299);
s299(300);
s300(301);
s301(302);

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
