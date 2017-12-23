VTABLE(_A) {
    <empty>
    A
    _A.init;
    _A.set;
    _A.printa;
}

VTABLE(_B) {
    <empty>
    B
    _B.setb;
    _B.printb;
}

VTABLE(_Main) {
    <empty>
    Main
}

FUNCTION(_A_New) {
memo ''
_A_New:
    _T7 = 8
    parm _T7
    _T8 =  call _Alloc
    _T9 = 0
    *(_T8 + 4) = _T9
    _T10 = VTBL <_A>
    *(_T8 + 0) = _T10
    return _T8
}

FUNCTION(_B_New) {
memo ''
_B_New:
    _T11 = 8
    parm _T11
    _T12 =  call _Alloc
    _T13 = 0
    *(_T12 + 4) = _T13
    _T14 = VTBL <_B>
    *(_T12 + 0) = _T14
    return _T12
}

FUNCTION(_Main_New) {
memo ''
_Main_New:
    _T15 = 4
    parm _T15
    _T16 =  call _Alloc
    _T17 = VTBL <_Main>
    *(_T16 + 0) = _T17
    return _T16
}

FUNCTION(_A.init) {
memo '_T0:4'
_A.init:
    _T18 = *(_T0 + 4)
    _T19 =  call _B_New
    *(_T0 + 4) = _T19
}

FUNCTION(_A.set) {
memo '_T1:4 _T2:8'
_A.set:
    _T20 = *(_T1 + 4)
    parm _T20
    parm _T2
    _T21 = *(_T20 + 0)
    _T22 = *(_T21 + 8)
    call _T22
}

FUNCTION(_A.printa) {
memo '_T3:4'
_A.printa:
    _T23 = *(_T3 + 4)
    parm _T23
    _T24 = *(_T23 + 0)
    _T25 = *(_T24 + 12)
    call _T25
}

FUNCTION(_B.setb) {
memo '_T4:4 _T5:8'
_B.setb:
    _T26 = *(_T4 + 4)
    *(_T4 + 4) = _T5
}

FUNCTION(_B.printb) {
memo '_T6:4'
_B.printb:
    _T27 = *(_T6 + 4)
    parm _T27
    call _PrintInt
}

FUNCTION(main) {
memo ''
main:
    _T30 =  call _A_New
    _T28 = _T30
    _T32 = 1
    _T31 = _T32
    parm _T28
    _T33 = *(_T28 + 0)
    _T34 = *(_T33 + 8)
    call _T34
    parm _T28
    parm _T31
    _T35 = *(_T28 + 0)
    _T36 = *(_T35 + 12)
    call _T36
    _T37 =  call _A_New
    _T38 = 0
    _T39 = 0
    _T38 = _T28
    _T39 = _T37
    _T40 = 4
    _T41 = 0
    _T42 = (_T38 + _T40)
    _T38 = _T42
    _T43 = (_T39 + _T40)
    _T39 = _T43
    _T44 = *(_T38 + 0)
    _T45 =  call _B_New
    _T46 = 0
    _T47 = 0
    _T46 = _T44
    _T47 = _T45
    _T48 = 4
    _T49 = 0
    _T50 = (_T46 + _T48)
    _T46 = _T50
    _T51 = (_T47 + _T48)
    _T47 = _T51
    _T52 = *(_T46 + 0)
    *(_T47 + 0) = _T52
    _T53 = (_T46 + _T48)
    _T46 = _T53
    _T54 = (_T47 + _T48)
    _T47 = _T54
    *(_T39 + 0) = _T45
    _T55 = (_T38 + _T40)
    _T38 = _T55
    _T56 = (_T39 + _T40)
    _T39 = _T56
    _T29 = _T37
    _T57 = 2
    _T31 = _T57
    parm _T28
    parm _T31
    _T58 = *(_T28 + 0)
    _T59 = *(_T58 + 12)
    call _T59
    parm _T28
    _T60 = *(_T28 + 0)
    _T61 = *(_T60 + 16)
    call _T61
    parm _T29
    _T62 = *(_T29 + 0)
    _T63 = *(_T62 + 16)
    call _T63
}

