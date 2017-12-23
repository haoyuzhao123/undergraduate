VTABLE(_A) {
    <empty>
    A
    _A.setA;
    _A.print;
    _A.allprint;
    _A.fun;
}

VTABLE(_B) {
    _A
    B
    _A.setA;
    _B.print;
    _B.allprint;
    _B.fun;
    _B.setB;
}

VTABLE(_C) {
    _A
    C
    _A.setA;
    _C.print;
    _C.allprint;
    _C.fun;
    _C.setC;
}

VTABLE(_D) {
    _B
    D
    _A.setA;
    _D.print;
    _D.allprint;
    _D.fun;
    _B.setB;
    _D.setD;
}

VTABLE(_E) {
    _C
    E
    _A.setA;
    _E.print;
    _E.allprint;
    _E.fun;
    _C.setC;
    _E.setE;
}

VTABLE(_F) {
    _E
    F
    _A.setA;
    _F.print;
    _F.allprint;
    _F.fun;
    _C.setC;
    _E.setE;
    _F.setF;
}

VTABLE(_G) {
    _C
    G
    _A.setA;
    _G.print;
    _G.allprint;
    _G.fun;
    _C.setC;
    _G.setG;
}

VTABLE(_Main) {
    <empty>
    Main
}

FUNCTION(_A_New) {
memo ''
_A_New:
    _T41 = 12
    parm _T41
    _T42 =  call _Alloc
    _T43 = 0
    *(_T42 + 4) = _T43
    *(_T42 + 8) = _T43
    _T44 = VTBL <_A>
    *(_T42 + 0) = _T44
    return _T42
}

FUNCTION(_B_New) {
memo ''
_B_New:
    _T45 = 20
    parm _T45
    _T46 =  call _Alloc
    _T47 = 0
    *(_T46 + 4) = _T47
    *(_T46 + 8) = _T47
    *(_T46 + 12) = _T47
    *(_T46 + 16) = _T47
    _T48 = VTBL <_B>
    *(_T46 + 0) = _T48
    return _T46
}

FUNCTION(_C_New) {
memo ''
_C_New:
    _T49 = 20
    parm _T49
    _T50 =  call _Alloc
    _T51 = 0
    *(_T50 + 4) = _T51
    *(_T50 + 8) = _T51
    *(_T50 + 12) = _T51
    *(_T50 + 16) = _T51
    _T52 = VTBL <_C>
    *(_T50 + 0) = _T52
    return _T50
}

FUNCTION(_D_New) {
memo ''
_D_New:
    _T53 = 28
    parm _T53
    _T54 =  call _Alloc
    _T55 = 0
    _T56 = 4
    _T57 = (_T54 + _T53)
_L41:
    _T58 = (_T57 - _T56)
    _T57 = _T58
    _T59 = (_T53 - _T56)
    _T53 = _T59
    if (_T53 == 0) branch _L42
    *(_T57 + 0) = _T55
    branch _L41
_L42:
    _T60 = VTBL <_D>
    *(_T57 + 0) = _T60
    return _T57
}

FUNCTION(_E_New) {
memo ''
_E_New:
    _T61 = 28
    parm _T61
    _T62 =  call _Alloc
    _T63 = 0
    _T64 = 4
    _T65 = (_T62 + _T61)
_L44:
    _T66 = (_T65 - _T64)
    _T65 = _T66
    _T67 = (_T61 - _T64)
    _T61 = _T67
    if (_T61 == 0) branch _L45
    *(_T65 + 0) = _T63
    branch _L44
_L45:
    _T68 = VTBL <_E>
    *(_T65 + 0) = _T68
    return _T65
}

FUNCTION(_F_New) {
memo ''
_F_New:
    _T69 = 36
    parm _T69
    _T70 =  call _Alloc
    _T71 = 0
    _T72 = 4
    _T73 = (_T70 + _T69)
_L47:
    _T74 = (_T73 - _T72)
    _T73 = _T74
    _T75 = (_T69 - _T72)
    _T69 = _T75
    if (_T69 == 0) branch _L48
    *(_T73 + 0) = _T71
    branch _L47
_L48:
    _T76 = VTBL <_F>
    *(_T73 + 0) = _T76
    return _T73
}

FUNCTION(_G_New) {
memo ''
_G_New:
    _T77 = 24
    parm _T77
    _T78 =  call _Alloc
    _T79 = 0
    _T80 = 4
    _T81 = (_T78 + _T77)
_L50:
    _T82 = (_T81 - _T80)
    _T81 = _T82
    _T83 = (_T77 - _T80)
    _T77 = _T83
    if (_T77 == 0) branch _L51
    *(_T81 + 0) = _T79
    branch _L50
_L51:
    _T84 = VTBL <_G>
    *(_T81 + 0) = _T84
    return _T81
}

FUNCTION(_Main_New) {
memo ''
_Main_New:
    _T85 = 4
    parm _T85
    _T86 =  call _Alloc
    _T87 = VTBL <_Main>
    *(_T86 + 0) = _T87
    return _T86
}

FUNCTION(_A.setA) {
memo '_T0:4 _T1:8 _T2:12'
_A.setA:
    _T88 = *(_T0 + 4)
    *(_T0 + 4) = _T1
    _T89 = *(_T0 + 8)
    *(_T0 + 8) = _T2
}

FUNCTION(_A.print) {
memo '_T3:4'
_A.print:
    _T90 = " a="
    parm _T90
    call _PrintString
    _T91 = *(_T3 + 4)
    parm _T91
    call _PrintInt
    _T92 = " a1="
    parm _T92
    call _PrintString
    _T93 = *(_T3 + 8)
    parm _T93
    call _PrintInt
    _T94 = " "
    parm _T94
    call _PrintString
}

FUNCTION(_A.allprint) {
memo '_T4:4'
_A.allprint:
    parm _T4
    _T95 = *(_T4 + 0)
    _T96 = VTBL <_A>
    _T97 = *(_T96 + 12)
    call _T97
}

FUNCTION(_A.fun) {
memo '_T5:4'
_A.fun:
    _T98 = "A"
    parm _T98
    call _PrintString
    parm _T5
    _T99 = *(_T5 + 0)
    _T100 = VTBL <_A>
    _T101 = *(_T100 + 12)
    call _T101
    _T102 = "\n"
    parm _T102
    call _PrintString
}

FUNCTION(_B.setB) {
memo '_T6:4 _T7:8 _T8:12'
_B.setB:
    _T103 = *(_T6 + 12)
    *(_T6 + 12) = _T7
    _T104 = *(_T6 + 16)
    *(_T6 + 16) = _T8
}

FUNCTION(_B.print) {
memo '_T9:4'
_B.print:
    _T105 = " b="
    parm _T105
    call _PrintString
    _T106 = *(_T9 + 12)
    parm _T106
    call _PrintInt
    _T107 = " b1="
    parm _T107
    call _PrintString
    _T108 = *(_T9 + 16)
    parm _T108
    call _PrintInt
    _T109 = " "
    parm _T109
    call _PrintString
}

FUNCTION(_B.allprint) {
memo '_T10:4'
_B.allprint:
    parm _T10
    _T110 = *(_T10 + 0)
    _T111 = VTBL <_A>
    _T112 = *(_T111 + 16)
    call _T112
    parm _T10
    _T113 = *(_T10 + 0)
    _T114 = VTBL <_B>
    _T115 = *(_T114 + 12)
    call _T115
}

FUNCTION(_B.fun) {
memo '_T11:4'
_B.fun:
    _T116 = "B"
    parm _T116
    call _PrintString
    parm _T11
    _T117 = *(_T11 + 0)
    _T118 = VTBL <_A>
    _T119 = *(_T118 + 16)
    call _T119
    parm _T11
    _T120 = *(_T11 + 0)
    _T121 = VTBL <_B>
    _T122 = *(_T121 + 12)
    call _T122
    _T123 = "\n"
    parm _T123
    call _PrintString
}

FUNCTION(_C.setC) {
memo '_T12:4 _T13:8 _T14:12'
_C.setC:
    _T124 = *(_T12 + 12)
    *(_T12 + 12) = _T13
    _T125 = *(_T12 + 16)
    *(_T12 + 16) = _T14
}

FUNCTION(_C.print) {
memo '_T15:4'
_C.print:
    _T126 = " c="
    parm _T126
    call _PrintString
    _T127 = *(_T15 + 12)
    parm _T127
    call _PrintInt
    _T128 = " c1="
    parm _T128
    call _PrintString
    _T129 = *(_T15 + 16)
    parm _T129
    call _PrintInt
    _T130 = " "
    parm _T130
    call _PrintString
}

FUNCTION(_C.allprint) {
memo '_T16:4'
_C.allprint:
    parm _T16
    _T131 = *(_T16 + 0)
    _T132 = VTBL <_A>
    _T133 = *(_T132 + 16)
    call _T133
    parm _T16
    _T134 = *(_T16 + 0)
    _T135 = VTBL <_C>
    _T136 = *(_T135 + 12)
    call _T136
}

FUNCTION(_C.fun) {
memo '_T17:4'
_C.fun:
    _T137 = "C"
    parm _T137
    call _PrintString
    parm _T17
    _T138 = *(_T17 + 0)
    _T139 = VTBL <_A>
    _T140 = *(_T139 + 16)
    call _T140
    parm _T17
    _T141 = *(_T17 + 0)
    _T142 = VTBL <_C>
    _T143 = *(_T142 + 12)
    call _T143
    _T144 = "\n"
    parm _T144
    call _PrintString
}

FUNCTION(_D.setD) {
memo '_T18:4 _T19:8 _T20:12'
_D.setD:
    _T145 = *(_T18 + 20)
    *(_T18 + 20) = _T19
    _T146 = *(_T18 + 24)
    *(_T18 + 24) = _T20
}

FUNCTION(_D.print) {
memo '_T21:4'
_D.print:
    _T147 = " d="
    parm _T147
    call _PrintString
    _T148 = *(_T21 + 20)
    parm _T148
    call _PrintInt
    _T149 = " d1="
    parm _T149
    call _PrintString
    _T150 = *(_T21 + 24)
    parm _T150
    call _PrintInt
    _T151 = " "
    parm _T151
    call _PrintString
}

FUNCTION(_D.allprint) {
memo '_T22:4'
_D.allprint:
    parm _T22
    _T152 = *(_T22 + 0)
    _T153 = VTBL <_B>
    _T154 = *(_T153 + 16)
    call _T154
    parm _T22
    _T155 = *(_T22 + 0)
    _T156 = VTBL <_D>
    _T157 = *(_T156 + 12)
    call _T157
}

FUNCTION(_D.fun) {
memo '_T23:4'
_D.fun:
    _T158 = "D"
    parm _T158
    call _PrintString
    parm _T23
    _T159 = *(_T23 + 0)
    _T160 = VTBL <_B>
    _T161 = *(_T160 + 16)
    call _T161
    parm _T23
    _T162 = *(_T23 + 0)
    _T163 = VTBL <_D>
    _T164 = *(_T163 + 12)
    call _T164
    _T165 = "\n"
    parm _T165
    call _PrintString
}

FUNCTION(_E.setE) {
memo '_T24:4 _T25:8 _T26:12'
_E.setE:
    _T166 = *(_T24 + 20)
    *(_T24 + 20) = _T25
    _T167 = *(_T24 + 24)
    *(_T24 + 24) = _T26
}

FUNCTION(_E.print) {
memo '_T27:4'
_E.print:
    _T168 = " e="
    parm _T168
    call _PrintString
    _T169 = *(_T27 + 20)
    parm _T169
    call _PrintInt
    _T170 = " e1="
    parm _T170
    call _PrintString
    _T171 = *(_T27 + 24)
    parm _T171
    call _PrintInt
    _T172 = " "
    parm _T172
    call _PrintString
}

FUNCTION(_E.allprint) {
memo '_T28:4'
_E.allprint:
    parm _T28
    _T173 = *(_T28 + 0)
    _T174 = VTBL <_C>
    _T175 = *(_T174 + 16)
    call _T175
    parm _T28
    _T176 = *(_T28 + 0)
    _T177 = VTBL <_E>
    _T178 = *(_T177 + 12)
    call _T178
}

FUNCTION(_E.fun) {
memo '_T29:4'
_E.fun:
    _T179 = "E"
    parm _T179
    call _PrintString
    parm _T29
    _T180 = *(_T29 + 0)
    _T181 = VTBL <_C>
    _T182 = *(_T181 + 16)
    call _T182
    parm _T29
    _T183 = *(_T29 + 0)
    _T184 = VTBL <_E>
    _T185 = *(_T184 + 12)
    call _T185
    _T186 = "\n"
    parm _T186
    call _PrintString
}

FUNCTION(_F.setF) {
memo '_T30:4 _T31:8 _T32:12'
_F.setF:
    _T187 = *(_T30 + 28)
    *(_T30 + 28) = _T31
    _T188 = *(_T30 + 32)
    *(_T30 + 32) = _T32
}

FUNCTION(_F.print) {
memo '_T33:4'
_F.print:
    _T189 = " f="
    parm _T189
    call _PrintString
    _T190 = *(_T33 + 28)
    parm _T190
    call _PrintInt
    _T191 = " f1="
    parm _T191
    call _PrintString
    _T192 = *(_T33 + 32)
    parm _T192
    call _PrintInt
    _T193 = " "
    parm _T193
    call _PrintString
}

FUNCTION(_F.allprint) {
memo '_T34:4'
_F.allprint:
    parm _T34
    _T194 = *(_T34 + 0)
    _T195 = VTBL <_E>
    _T196 = *(_T195 + 16)
    call _T196
    parm _T34
    _T197 = *(_T34 + 0)
    _T198 = VTBL <_F>
    _T199 = *(_T198 + 12)
    call _T199
}

FUNCTION(_F.fun) {
memo '_T35:4'
_F.fun:
    _T200 = "F"
    parm _T200
    call _PrintString
    parm _T35
    _T201 = *(_T35 + 0)
    _T202 = VTBL <_E>
    _T203 = *(_T202 + 16)
    call _T203
    parm _T35
    _T204 = *(_T35 + 0)
    _T205 = VTBL <_F>
    _T206 = *(_T205 + 12)
    call _T206
    _T207 = "\n"
    parm _T207
    call _PrintString
}

FUNCTION(_G.setG) {
memo '_T36:4 _T37:8'
_G.setG:
    _T208 = *(_T36 + 20)
    *(_T36 + 20) = _T37
}

FUNCTION(_G.print) {
memo '_T38:4'
_G.print:
    _T209 = " g="
    parm _T209
    call _PrintString
    _T210 = *(_T38 + 20)
    parm _T210
    call _PrintInt
}

FUNCTION(_G.allprint) {
memo '_T39:4'
_G.allprint:
    parm _T39
    _T211 = *(_T39 + 0)
    _T212 = VTBL <_C>
    _T213 = *(_T212 + 16)
    call _T213
    parm _T39
    _T214 = *(_T39 + 0)
    _T215 = VTBL <_G>
    _T216 = *(_T215 + 12)
    call _T216
}

FUNCTION(_G.fun) {
memo '_T40:4'
_G.fun:
    _T217 = "G"
    parm _T217
    call _PrintString
    parm _T40
    _T218 = *(_T40 + 0)
    _T219 = VTBL <_C>
    _T220 = *(_T219 + 16)
    call _T220
    parm _T40
    _T221 = *(_T40 + 0)
    _T222 = VTBL <_G>
    _T223 = *(_T222 + 12)
    call _T223
    _T224 = "\n"
    parm _T224
    call _PrintString
}

FUNCTION(main) {
memo ''
main:
    _T232 =  call _A_New
    _T225 = _T232
    _T233 =  call _B_New
    _T226 = _T233
    _T234 =  call _C_New
    _T227 = _T234
    _T235 =  call _D_New
    _T228 = _T235
    _T236 =  call _E_New
    _T229 = _T236
    _T237 =  call _F_New
    _T230 = _T237
    _T238 =  call _G_New
    _T231 = _T238
    _T239 = 10
    _T240 = 11
    parm _T225
    parm _T239
    parm _T240
    _T241 = *(_T225 + 0)
    _T242 = *(_T241 + 8)
    call _T242
    _T243 = 20
    _T244 = 21
    parm _T226
    parm _T243
    parm _T244
    _T245 = *(_T226 + 0)
    _T246 = *(_T245 + 8)
    call _T246
    _T247 = 22
    _T248 = 23
    parm _T226
    parm _T247
    parm _T248
    _T249 = *(_T226 + 0)
    _T250 = *(_T249 + 24)
    call _T250
    _T251 = 30
    _T252 = 31
    parm _T227
    parm _T251
    parm _T252
    _T253 = *(_T227 + 0)
    _T254 = *(_T253 + 8)
    call _T254
    _T255 = 32
    _T256 = 33
    parm _T227
    parm _T255
    parm _T256
    _T257 = *(_T227 + 0)
    _T258 = *(_T257 + 24)
    call _T258
    _T259 = 40
    _T260 = 41
    parm _T228
    parm _T259
    parm _T260
    _T261 = *(_T228 + 0)
    _T262 = *(_T261 + 8)
    call _T262
    _T263 = 42
    _T264 = 43
    parm _T228
    parm _T263
    parm _T264
    _T265 = *(_T228 + 0)
    _T266 = *(_T265 + 24)
    call _T266
    _T267 = 44
    _T268 = 45
    parm _T228
    parm _T267
    parm _T268
    _T269 = *(_T228 + 0)
    _T270 = *(_T269 + 28)
    call _T270
    _T271 = 50
    _T272 = 51
    parm _T229
    parm _T271
    parm _T272
    _T273 = *(_T229 + 0)
    _T274 = *(_T273 + 8)
    call _T274
    _T275 = 52
    _T276 = 53
    parm _T229
    parm _T275
    parm _T276
    _T277 = *(_T229 + 0)
    _T278 = *(_T277 + 24)
    call _T278
    _T279 = 54
    _T280 = 55
    parm _T229
    parm _T279
    parm _T280
    _T281 = *(_T229 + 0)
    _T282 = *(_T281 + 28)
    call _T282
    _T283 = 60
    _T284 = 61
    parm _T230
    parm _T283
    parm _T284
    _T285 = *(_T230 + 0)
    _T286 = *(_T285 + 8)
    call _T286
    _T287 = 62
    _T288 = 63
    parm _T230
    parm _T287
    parm _T288
    _T289 = *(_T230 + 0)
    _T290 = *(_T289 + 24)
    call _T290
    _T291 = 64
    _T292 = 65
    parm _T230
    parm _T291
    parm _T292
    _T293 = *(_T230 + 0)
    _T294 = *(_T293 + 28)
    call _T294
    _T295 = 66
    _T296 = 67
    parm _T230
    parm _T295
    parm _T296
    _T297 = *(_T230 + 0)
    _T298 = *(_T297 + 32)
    call _T298
    _T299 = 70
    _T300 = 71
    parm _T231
    parm _T299
    parm _T300
    _T301 = *(_T231 + 0)
    _T302 = *(_T301 + 8)
    call _T302
    _T303 = 72
    _T304 = 73
    parm _T231
    parm _T303
    parm _T304
    _T305 = *(_T231 + 0)
    _T306 = *(_T305 + 24)
    call _T306
    _T307 = 74
    parm _T231
    parm _T307
    _T308 = *(_T231 + 0)
    _T309 = *(_T308 + 28)
    call _T309
    parm _T225
    _T310 = *(_T225 + 0)
    _T311 = *(_T310 + 20)
    call _T311
    parm _T226
    _T312 = *(_T226 + 0)
    _T313 = *(_T312 + 20)
    call _T313
    parm _T227
    _T314 = *(_T227 + 0)
    _T315 = *(_T314 + 20)
    call _T315
    parm _T228
    _T316 = *(_T228 + 0)
    _T317 = *(_T316 + 20)
    call _T317
    parm _T229
    _T318 = *(_T229 + 0)
    _T319 = *(_T318 + 20)
    call _T319
    parm _T230
    _T320 = *(_T230 + 0)
    _T321 = *(_T320 + 20)
    call _T321
    parm _T231
    _T322 = *(_T231 + 0)
    _T323 = *(_T322 + 20)
    call _T323
}

