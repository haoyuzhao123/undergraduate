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
    _C.allprint;
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
    _T40 = 12
    parm _T40
    _T41 =  call _Alloc
    _T42 = 0
    *(_T41 + 4) = _T42
    *(_T41 + 8) = _T42
    _T43 = VTBL <_A>
    *(_T41 + 0) = _T43
    return _T41
}

FUNCTION(_B_New) {
memo ''
_B_New:
    _T44 = 20
    parm _T44
    _T45 =  call _Alloc
    _T46 = 0
    *(_T45 + 4) = _T46
    *(_T45 + 8) = _T46
    *(_T45 + 12) = _T46
    *(_T45 + 16) = _T46
    _T47 = VTBL <_B>
    *(_T45 + 0) = _T47
    return _T45
}

FUNCTION(_C_New) {
memo ''
_C_New:
    _T48 = 20
    parm _T48
    _T49 =  call _Alloc
    _T50 = 0
    *(_T49 + 4) = _T50
    *(_T49 + 8) = _T50
    *(_T49 + 12) = _T50
    *(_T49 + 16) = _T50
    _T51 = VTBL <_C>
    *(_T49 + 0) = _T51
    return _T49
}

FUNCTION(_D_New) {
memo ''
_D_New:
    _T52 = 28
    parm _T52
    _T53 =  call _Alloc
    _T54 = 0
    _T55 = 4
    _T56 = (_T53 + _T52)
_L40:
    _T57 = (_T56 - _T55)
    _T56 = _T57
    _T58 = (_T52 - _T55)
    _T52 = _T58
    if (_T52 == 0) branch _L41
    *(_T56 + 0) = _T54
    branch _L40
_L41:
    _T59 = VTBL <_D>
    *(_T56 + 0) = _T59
    return _T56
}

FUNCTION(_E_New) {
memo ''
_E_New:
    _T60 = 28
    parm _T60
    _T61 =  call _Alloc
    _T62 = 0
    _T63 = 4
    _T64 = (_T61 + _T60)
_L43:
    _T65 = (_T64 - _T63)
    _T64 = _T65
    _T66 = (_T60 - _T63)
    _T60 = _T66
    if (_T60 == 0) branch _L44
    *(_T64 + 0) = _T62
    branch _L43
_L44:
    _T67 = VTBL <_E>
    *(_T64 + 0) = _T67
    return _T64
}

FUNCTION(_F_New) {
memo ''
_F_New:
    _T68 = 36
    parm _T68
    _T69 =  call _Alloc
    _T70 = 0
    _T71 = 4
    _T72 = (_T69 + _T68)
_L46:
    _T73 = (_T72 - _T71)
    _T72 = _T73
    _T74 = (_T68 - _T71)
    _T68 = _T74
    if (_T68 == 0) branch _L47
    *(_T72 + 0) = _T70
    branch _L46
_L47:
    _T75 = VTBL <_F>
    *(_T72 + 0) = _T75
    return _T72
}

FUNCTION(_G_New) {
memo ''
_G_New:
    _T76 = 24
    parm _T76
    _T77 =  call _Alloc
    _T78 = 0
    _T79 = 4
    _T80 = (_T77 + _T76)
_L49:
    _T81 = (_T80 - _T79)
    _T80 = _T81
    _T82 = (_T76 - _T79)
    _T76 = _T82
    if (_T76 == 0) branch _L50
    *(_T80 + 0) = _T78
    branch _L49
_L50:
    _T83 = VTBL <_G>
    *(_T80 + 0) = _T83
    return _T80
}

FUNCTION(_Main_New) {
memo ''
_Main_New:
    _T84 = 4
    parm _T84
    _T85 =  call _Alloc
    _T86 = VTBL <_Main>
    *(_T85 + 0) = _T86
    return _T85
}

FUNCTION(_A.setA) {
memo '_T0:4 _T1:8 _T2:12'
_A.setA:
    _T87 = *(_T0 + 4)
    *(_T0 + 4) = _T1
    _T88 = *(_T0 + 8)
    *(_T0 + 8) = _T2
}

FUNCTION(_A.print) {
memo '_T3:4'
_A.print:
    _T89 = " a="
    parm _T89
    call _PrintString
    _T90 = *(_T3 + 4)
    parm _T90
    call _PrintInt
    _T91 = " a1="
    parm _T91
    call _PrintString
    _T92 = *(_T3 + 8)
    parm _T92
    call _PrintInt
    _T93 = " "
    parm _T93
    call _PrintString
}

FUNCTION(_A.allprint) {
memo '_T4:4'
_A.allprint:
    parm _T4
    _T94 = *(_T4 + 0)
    _T95 = VTBL <_A>
    _T96 = *(_T95 + 12)
    call _T96
}

FUNCTION(_A.fun) {
memo '_T5:4'
_A.fun:
    _T97 = "A"
    parm _T97
    call _PrintString
    parm _T5
    _T98 = *(_T5 + 0)
    _T99 = VTBL <_A>
    _T100 = *(_T99 + 12)
    call _T100
    _T101 = "\n"
    parm _T101
    call _PrintString
}

FUNCTION(_B.setB) {
memo '_T6:4 _T7:8 _T8:12'
_B.setB:
    _T102 = *(_T6 + 12)
    *(_T6 + 12) = _T7
    _T103 = *(_T6 + 16)
    *(_T6 + 16) = _T8
}

FUNCTION(_B.print) {
memo '_T9:4'
_B.print:
    _T104 = " b="
    parm _T104
    call _PrintString
    _T105 = *(_T9 + 12)
    parm _T105
    call _PrintInt
    _T106 = " b1="
    parm _T106
    call _PrintString
    _T107 = *(_T9 + 16)
    parm _T107
    call _PrintInt
    _T108 = " "
    parm _T108
    call _PrintString
}

FUNCTION(_B.allprint) {
memo '_T10:4'
_B.allprint:
    parm _T10
    _T109 = *(_T10 + 0)
    _T110 = VTBL <_A>
    _T111 = *(_T110 + 16)
    call _T111
    parm _T10
    _T112 = *(_T10 + 0)
    _T113 = VTBL <_B>
    _T114 = *(_T113 + 12)
    call _T114
}

FUNCTION(_B.fun) {
memo '_T11:4'
_B.fun:
    _T115 = "B"
    parm _T115
    call _PrintString
    parm _T11
    _T116 = *(_T11 + 0)
    _T117 = VTBL <_A>
    _T118 = *(_T117 + 16)
    call _T118
    parm _T11
    _T119 = *(_T11 + 0)
    _T120 = VTBL <_B>
    _T121 = *(_T120 + 12)
    call _T121
    _T122 = "\n"
    parm _T122
    call _PrintString
}

FUNCTION(_C.setC) {
memo '_T12:4 _T13:8 _T14:12'
_C.setC:
    _T123 = *(_T12 + 12)
    *(_T12 + 12) = _T13
    _T124 = *(_T12 + 16)
    *(_T12 + 16) = _T14
}

FUNCTION(_C.print) {
memo '_T15:4'
_C.print:
    _T125 = " c="
    parm _T125
    call _PrintString
    _T126 = *(_T15 + 12)
    parm _T126
    call _PrintInt
    _T127 = " c1="
    parm _T127
    call _PrintString
    _T128 = *(_T15 + 16)
    parm _T128
    call _PrintInt
    _T129 = " "
    parm _T129
    call _PrintString
}

FUNCTION(_C.allprint) {
memo '_T16:4'
_C.allprint:
    parm _T16
    _T130 = *(_T16 + 0)
    _T131 = VTBL <_C>
    _T132 = *(_T131 + 12)
    call _T132
}

FUNCTION(_C.fun) {
memo '_T17:4'
_C.fun:
    _T133 = "C"
    parm _T133
    call _PrintString
    parm _T17
    _T134 = *(_T17 + 0)
    _T135 = VTBL <_A>
    _T136 = *(_T135 + 16)
    call _T136
    parm _T17
    _T137 = *(_T17 + 0)
    _T138 = VTBL <_C>
    _T139 = *(_T138 + 12)
    call _T139
    _T140 = "\n"
    parm _T140
    call _PrintString
}

FUNCTION(_D.setD) {
memo '_T18:4 _T19:8 _T20:12'
_D.setD:
    _T141 = *(_T18 + 20)
    *(_T18 + 20) = _T19
    _T142 = *(_T18 + 24)
    *(_T18 + 24) = _T20
}

FUNCTION(_D.print) {
memo '_T21:4'
_D.print:
    _T143 = " d="
    parm _T143
    call _PrintString
    _T144 = *(_T21 + 20)
    parm _T144
    call _PrintInt
    _T145 = " d1="
    parm _T145
    call _PrintString
    _T146 = *(_T21 + 24)
    parm _T146
    call _PrintInt
    _T147 = " "
    parm _T147
    call _PrintString
}

FUNCTION(_D.allprint) {
memo '_T22:4'
_D.allprint:
    parm _T22
    _T148 = *(_T22 + 0)
    _T149 = VTBL <_B>
    _T150 = *(_T149 + 16)
    call _T150
    parm _T22
    _T151 = *(_T22 + 0)
    _T152 = VTBL <_D>
    _T153 = *(_T152 + 12)
    call _T153
}

FUNCTION(_D.fun) {
memo '_T23:4'
_D.fun:
    _T154 = "D"
    parm _T154
    call _PrintString
    parm _T23
    _T155 = *(_T23 + 0)
    _T156 = VTBL <_B>
    _T157 = *(_T156 + 16)
    call _T157
    parm _T23
    _T158 = *(_T23 + 0)
    _T159 = VTBL <_D>
    _T160 = *(_T159 + 12)
    call _T160
    _T161 = "\n"
    parm _T161
    call _PrintString
}

FUNCTION(_E.setE) {
memo '_T24:4 _T25:8 _T26:12'
_E.setE:
    _T162 = *(_T24 + 20)
    *(_T24 + 20) = _T25
    _T163 = *(_T24 + 24)
    *(_T24 + 24) = _T26
}

FUNCTION(_E.print) {
memo '_T27:4'
_E.print:
    _T164 = " e="
    parm _T164
    call _PrintString
    _T165 = *(_T27 + 20)
    parm _T165
    call _PrintInt
    _T166 = " e1="
    parm _T166
    call _PrintString
    _T167 = *(_T27 + 24)
    parm _T167
    call _PrintInt
    _T168 = " "
    parm _T168
    call _PrintString
}

FUNCTION(_E.fun) {
memo '_T28:4'
_E.fun:
    _T169 = "E"
    parm _T169
    call _PrintString
    parm _T28
    _T170 = *(_T28 + 0)
    _T171 = VTBL <_E>
    _T172 = *(_T171 + 16)
    call _T172
    parm _T28
    _T173 = *(_T28 + 0)
    _T174 = VTBL <_E>
    _T175 = *(_T174 + 12)
    call _T175
    _T176 = "\n"
    parm _T176
    call _PrintString
}

FUNCTION(_F.setF) {
memo '_T29:4 _T30:8 _T31:12'
_F.setF:
    _T177 = *(_T29 + 28)
    *(_T29 + 28) = _T30
    _T178 = *(_T29 + 32)
    *(_T29 + 32) = _T31
}

FUNCTION(_F.print) {
memo '_T32:4'
_F.print:
    _T179 = " f="
    parm _T179
    call _PrintString
    _T180 = *(_T32 + 28)
    parm _T180
    call _PrintInt
    _T181 = " f1="
    parm _T181
    call _PrintString
    _T182 = *(_T32 + 32)
    parm _T182
    call _PrintInt
    _T183 = " "
    parm _T183
    call _PrintString
}

FUNCTION(_F.allprint) {
memo '_T33:4'
_F.allprint:
    parm _T33
    _T184 = *(_T33 + 0)
    _T185 = VTBL <_E>
    _T186 = *(_T185 + 16)
    call _T186
    parm _T33
    _T187 = *(_T33 + 0)
    _T188 = VTBL <_F>
    _T189 = *(_T188 + 12)
    call _T189
}

FUNCTION(_F.fun) {
memo '_T34:4'
_F.fun:
    _T190 = "F"
    parm _T190
    call _PrintString
    parm _T34
    _T191 = *(_T34 + 0)
    _T192 = VTBL <_E>
    _T193 = *(_T192 + 16)
    call _T193
    parm _T34
    _T194 = *(_T34 + 0)
    _T195 = VTBL <_F>
    _T196 = *(_T195 + 12)
    call _T196
    _T197 = "\n"
    parm _T197
    call _PrintString
}

FUNCTION(_G.setG) {
memo '_T35:4 _T36:8'
_G.setG:
    _T198 = *(_T35 + 20)
    *(_T35 + 20) = _T36
}

FUNCTION(_G.print) {
memo '_T37:4'
_G.print:
    _T199 = " g="
    parm _T199
    call _PrintString
    _T200 = *(_T37 + 20)
    parm _T200
    call _PrintInt
}

FUNCTION(_G.allprint) {
memo '_T38:4'
_G.allprint:
    parm _T38
    _T201 = *(_T38 + 0)
    _T202 = VTBL <_C>
    _T203 = *(_T202 + 16)
    call _T203
    parm _T38
    _T204 = *(_T38 + 0)
    _T205 = VTBL <_G>
    _T206 = *(_T205 + 12)
    call _T206
}

FUNCTION(_G.fun) {
memo '_T39:4'
_G.fun:
    _T207 = "G"
    parm _T207
    call _PrintString
    parm _T39
    _T208 = *(_T39 + 0)
    _T209 = VTBL <_C>
    _T210 = *(_T209 + 16)
    call _T210
    parm _T39
    _T211 = *(_T39 + 0)
    _T212 = VTBL <_G>
    _T213 = *(_T212 + 12)
    call _T213
    _T214 = "\n"
    parm _T214
    call _PrintString
}

FUNCTION(main) {
memo ''
main:
    _T222 =  call _A_New
    _T215 = _T222
    _T223 =  call _B_New
    _T216 = _T223
    _T224 =  call _C_New
    _T217 = _T224
    _T225 =  call _D_New
    _T218 = _T225
    _T226 =  call _E_New
    _T219 = _T226
    _T227 =  call _F_New
    _T220 = _T227
    _T228 =  call _G_New
    _T221 = _T228
    _T229 = 10
    _T230 = 11
    parm _T215
    parm _T229
    parm _T230
    _T231 = *(_T215 + 0)
    _T232 = *(_T231 + 8)
    call _T232
    _T233 = 20
    _T234 = 21
    parm _T216
    parm _T233
    parm _T234
    _T235 = *(_T216 + 0)
    _T236 = *(_T235 + 8)
    call _T236
    _T237 = 22
    _T238 = 23
    parm _T216
    parm _T237
    parm _T238
    _T239 = *(_T216 + 0)
    _T240 = *(_T239 + 24)
    call _T240
    _T241 = 30
    _T242 = 31
    parm _T217
    parm _T241
    parm _T242
    _T243 = *(_T217 + 0)
    _T244 = *(_T243 + 8)
    call _T244
    _T245 = 32
    _T246 = 33
    parm _T217
    parm _T245
    parm _T246
    _T247 = *(_T217 + 0)
    _T248 = *(_T247 + 24)
    call _T248
    _T249 = 40
    _T250 = 41
    parm _T218
    parm _T249
    parm _T250
    _T251 = *(_T218 + 0)
    _T252 = *(_T251 + 8)
    call _T252
    _T253 = 42
    _T254 = 43
    parm _T218
    parm _T253
    parm _T254
    _T255 = *(_T218 + 0)
    _T256 = *(_T255 + 24)
    call _T256
    _T257 = 44
    _T258 = 45
    parm _T218
    parm _T257
    parm _T258
    _T259 = *(_T218 + 0)
    _T260 = *(_T259 + 28)
    call _T260
    _T261 = 50
    _T262 = 51
    parm _T219
    parm _T261
    parm _T262
    _T263 = *(_T219 + 0)
    _T264 = *(_T263 + 8)
    call _T264
    _T265 = 52
    _T266 = 53
    parm _T219
    parm _T265
    parm _T266
    _T267 = *(_T219 + 0)
    _T268 = *(_T267 + 24)
    call _T268
    _T269 = 54
    _T270 = 55
    parm _T219
    parm _T269
    parm _T270
    _T271 = *(_T219 + 0)
    _T272 = *(_T271 + 28)
    call _T272
    _T273 = 60
    _T274 = 61
    parm _T220
    parm _T273
    parm _T274
    _T275 = *(_T220 + 0)
    _T276 = *(_T275 + 8)
    call _T276
    _T277 = 62
    _T278 = 63
    parm _T220
    parm _T277
    parm _T278
    _T279 = *(_T220 + 0)
    _T280 = *(_T279 + 24)
    call _T280
    _T281 = 64
    _T282 = 65
    parm _T220
    parm _T281
    parm _T282
    _T283 = *(_T220 + 0)
    _T284 = *(_T283 + 28)
    call _T284
    _T285 = 66
    _T286 = 67
    parm _T220
    parm _T285
    parm _T286
    _T287 = *(_T220 + 0)
    _T288 = *(_T287 + 32)
    call _T288
    _T289 = 70
    _T290 = 71
    parm _T221
    parm _T289
    parm _T290
    _T291 = *(_T221 + 0)
    _T292 = *(_T291 + 8)
    call _T292
    _T293 = 72
    _T294 = 73
    parm _T221
    parm _T293
    parm _T294
    _T295 = *(_T221 + 0)
    _T296 = *(_T295 + 24)
    call _T296
    _T297 = 74
    parm _T221
    parm _T297
    _T298 = *(_T221 + 0)
    _T299 = *(_T298 + 28)
    call _T299
    parm _T215
    _T300 = *(_T215 + 0)
    _T301 = *(_T300 + 20)
    call _T301
    parm _T216
    _T302 = *(_T216 + 0)
    _T303 = *(_T302 + 20)
    call _T303
    parm _T217
    _T304 = *(_T217 + 0)
    _T305 = *(_T304 + 20)
    call _T305
    parm _T218
    _T306 = *(_T218 + 0)
    _T307 = *(_T306 + 20)
    call _T307
    parm _T219
    _T308 = *(_T219 + 0)
    _T309 = *(_T308 + 20)
    call _T309
    parm _T220
    _T310 = *(_T220 + 0)
    _T311 = *(_T310 + 20)
    call _T311
    parm _T221
    _T312 = *(_T221 + 0)
    _T313 = *(_T312 + 20)
    call _T313
}

