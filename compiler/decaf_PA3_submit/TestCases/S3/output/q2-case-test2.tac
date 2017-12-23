VTABLE(_Main) {
    <empty>
    Main
}

FUNCTION(_Main_New) {
memo ''
_Main_New:
    _T0 = 4
    parm _T0
    _T1 =  call _Alloc
    _T2 = VTBL <_Main>
    *(_T1 + 0) = _T2
    return _T1
}

FUNCTION(main) {
memo ''
main:
    _T9 = 6
    _T3 = _T9
    _T10 = 2
    _T4 = _T10
    _T11 = 3
    _T5 = _T11
    _T12 = 3
    _T13 = (_T3 * _T12)
    _T14 = 0
    _T15 = 0
    _T16 = 0
    _T17 = 0
    _T18 = (_T13 == _T17)
    if (_T18 == 0) branch _L11
    _T19 = (_T4 + _T5)
    _T14 = _T19
    branch _L10
_L11:
    _T20 = 3
    _T21 = (_T13 == _T20)
    if (_T21 == 0) branch _L12
    _T22 = 3
    _T23 = (_T4 + _T22)
    _T14 = _T23
    branch _L10
_L12:
    _T24 = 9
    _T25 = (_T13 == _T24)
    if (_T25 == 0) branch _L13
    _T26 = 2
    _T27 = (_T5 * _T26)
    _T28 = 6
    _T29 = (_T27 + _T28)
    _T14 = _T29
    branch _L10
_L13:
    _T30 = 100
    _T14 = _T30
_L10:
    _T4 = _T14
    parm _T4
    call _PrintInt
    _T31 = "\n"
    parm _T31
    call _PrintString
    _T32 = 3
    _T6 = _T32
    _T33 = 0
    _T34 = 0
    _T35 = 0
    _T36 = 0
    _T37 = (_T6 == _T36)
    if (_T37 == 0) branch _L15
    _T38 = (_T4 + _T5)
    _T33 = _T38
    branch _L14
_L15:
    _T39 = 3
    _T40 = (_T6 == _T39)
    if (_T40 == 0) branch _L16
    _T41 = 3
    _T42 = (_T4 + _T41)
    _T33 = _T42
    branch _L14
_L16:
    _T43 = 6
    _T44 = (_T6 == _T43)
    if (_T44 == 0) branch _L17
    _T45 = 2
    _T46 = (_T5 * _T45)
    _T47 = 6
    _T48 = (_T46 + _T47)
    _T33 = _T48
    branch _L14
_L17:
    _T49 = 100
    _T33 = _T49
_L14:
    _T4 = _T33
    parm _T4
    call _PrintInt
    _T50 = "\n"
    parm _T50
    call _PrintString
    _T51 = 0
    _T52 = 0
    _T53 = 0
    _T54 = 0
    _T55 = (_T3 == _T54)
    if (_T55 == 0) branch _L19
    _T56 = (_T4 + _T5)
    _T51 = _T56
    branch _L18
_L19:
    _T57 = 3
    _T58 = (_T3 == _T57)
    if (_T58 == 0) branch _L20
    _T59 = 3
    _T60 = (_T4 + _T59)
    _T51 = _T60
    branch _L18
_L20:
    _T61 = 6
    _T62 = (_T3 == _T61)
    if (_T62 == 0) branch _L21
    _T63 = 2
    _T64 = (_T5 * _T63)
    _T65 = 6
    _T66 = (_T64 + _T65)
    _T51 = _T66
    branch _L18
_L21:
    _T67 = 100
    _T51 = _T67
_L18:
    _T4 = _T51
    parm _T4
    call _PrintInt
    _T68 = "\n"
    parm _T68
    call _PrintString
    _T69 = 6
    _T70 = (_T3 - _T69)
    _T71 = 0
    _T72 = 0
    _T73 = 0
    _T74 = 0
    _T75 = (_T70 == _T74)
    if (_T75 == 0) branch _L23
    _T76 = (_T4 + _T5)
    _T71 = _T76
    branch _L22
_L23:
    _T77 = 3
    _T78 = (_T70 == _T77)
    if (_T78 == 0) branch _L24
    _T79 = 3
    _T80 = (_T4 + _T79)
    _T71 = _T80
    branch _L22
_L24:
    _T81 = 9
    _T82 = (_T70 == _T81)
    if (_T82 == 0) branch _L25
    _T83 = 2
    _T84 = (_T5 * _T83)
    _T85 = 6
    _T86 = (_T84 + _T85)
    _T71 = _T86
    branch _L22
_L25:
    _T87 = 100
    _T71 = _T87
_L22:
    _T4 = _T71
    parm _T4
    call _PrintInt
    _T88 = "\n"
    parm _T88
    call _PrintString
    _T89 = 0
    _T90 = 0
    _T91 = 0
    _T92 = 0
    _T93 = (_T3 == _T92)
    if (_T93 == 0) branch _L27
    _T94 = (_T4 + _T5)
    _T89 = _T94
    branch _L26
_L27:
    _T95 = 3
    _T96 = (_T3 == _T95)
    if (_T96 == 0) branch _L28
    _T97 = 3
    _T98 = (_T4 + _T97)
    _T89 = _T98
    branch _L26
_L28:
    _T99 = 6
    _T100 = (_T3 == _T99)
    if (_T100 == 0) branch _L29
    _T101 = 2
    _T102 = (_T5 * _T101)
    _T103 = 6
    _T104 = (_T102 + _T103)
    _T89 = _T104
    branch _L26
_L29:
    _T105 = 100
    _T89 = _T105
_L26:
    _T106 = 0
    _T107 = 0
    _T107 = _T89
    _T7 = _T107
    _T8 = _T106
    parm _T7
    call _PrintInt
    _T108 = "+"
    parm _T108
    call _PrintString
    parm _T8
    call _PrintInt
    _T109 = "j"
    parm _T109
    call _PrintString
    _T110 = "\n"
    parm _T110
    call _PrintString
    _T111 = 0
    _T112 = 0
    _T113 = 0
    _T114 = 8
    _T115 = (_T3 == _T114)
    if (_T115 == 0) branch _L31
    _T116 = (_T4 + _T5)
    _T111 = _T116
    branch _L30
_L31:
    _T117 = 3
    _T118 = (_T3 == _T117)
    if (_T118 == 0) branch _L32
    _T119 = (_T4 + _T3)
    _T111 = _T119
    branch _L30
_L32:
    _T120 = 0
    _T121 = (_T3 == _T120)
    if (_T121 == 0) branch _L33
    _T122 = 8
    _T111 = _T122
    branch _L30
_L33:
    _T123 = 100
    _T111 = _T123
_L30:
    _T124 = 0
    _T125 = 0
    _T125 = _T111
    _T7 = _T125
    _T8 = _T124
    parm _T7
    call _PrintInt
    _T126 = "+"
    parm _T126
    call _PrintString
    parm _T8
    call _PrintInt
    _T127 = "j"
    parm _T127
    call _PrintString
    _T128 = "\n"
    parm _T128
    call _PrintString
}

