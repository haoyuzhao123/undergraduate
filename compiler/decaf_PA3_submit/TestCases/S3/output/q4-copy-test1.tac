VTABLE(_Main) {
    <empty>
    Main
}

VTABLE(_animal) {
    <empty>
    animal
    _animal.setage;
    _animal.getage;
}

VTABLE(_people) {
    <empty>
    people
    _people.setaniage;
    _people.getage;
    _people.setage;
}

FUNCTION(_Main_New) {
memo ''
_Main_New:
    _T7 = 4
    parm _T7
    _T8 =  call _Alloc
    _T9 = VTBL <_Main>
    *(_T8 + 0) = _T9
    return _T8
}

FUNCTION(_animal_New) {
memo ''
_animal_New:
    _T10 = 8
    parm _T10
    _T11 =  call _Alloc
    _T12 = 0
    *(_T11 + 4) = _T12
    _T13 = VTBL <_animal>
    *(_T11 + 0) = _T13
    return _T11
}

FUNCTION(_people_New) {
memo ''
_people_New:
    _T14 = 24
    parm _T14
    _T15 =  call _Alloc
    _T16 = 0
    _T17 = 4
    _T18 = (_T15 + _T14)
_L17:
    _T19 = (_T18 - _T17)
    _T18 = _T19
    _T20 = (_T14 - _T17)
    _T14 = _T20
    if (_T14 == 0) branch _L18
    *(_T18 + 0) = _T16
    branch _L17
_L18:
    _T21 = VTBL <_people>
    *(_T18 + 0) = _T21
    return _T18
}

FUNCTION(main) {
memo ''
main:
    _T25 =  call _people_New
    _T23 = _T25
    parm _T23
    _T26 = *(_T23 + 0)
    _T27 = *(_T26 + 16)
    call _T27
    _T28 =  call _people_New
    _T29 = 4
    _T30 = 0
    _T31 = 0
    _T32 = 0
    _T31 = _T23
    _T32 = _T28
    _T33 = 24
_L19:
    if (_T33 == 0) branch _L20
    _T34 = *(_T31 + 0)
    *(_T32 + 0) = _T34
    _T35 = (_T31 + _T29)
    _T31 = _T35
    _T36 = (_T32 + _T29)
    _T32 = _T36
    _T37 = (_T33 - _T29)
    _T33 = _T37
    branch _L19
_L20:
    _T24 = _T28
    _T38 = 99
    parm _T24
    parm _T38
    _T39 = *(_T24 + 0)
    _T40 = *(_T39 + 8)
    call _T40
    _T41 = "a: \n"
    parm _T41
    call _PrintString
    parm _T23
    _T42 = *(_T23 + 0)
    _T43 = *(_T42 + 12)
    call _T43
    _T44 = "b: \n"
    parm _T44
    call _PrintString
    parm _T24
    _T45 = *(_T24 + 0)
    _T46 = *(_T45 + 12)
    call _T46
}

FUNCTION(_animal.setage) {
memo '_T0:4 _T1:8'
_animal.setage:
    _T47 = *(_T0 + 4)
    *(_T0 + 4) = _T1
}

FUNCTION(_animal.getage) {
memo '_T2:4'
_animal.getage:
    _T48 = *(_T2 + 4)
    parm _T48
    call _PrintInt
    _T49 = "\n"
    parm _T49
    call _PrintString
}

FUNCTION(_people.setaniage) {
memo '_T3:4 _T4:8'
_people.setaniage:
    _T50 = *(_T3 + 16)
    parm _T50
    parm _T4
    _T51 = *(_T50 + 0)
    _T52 = *(_T51 + 8)
    call _T52
}

FUNCTION(_people.getage) {
memo '_T5:4'
_people.getage:
    _T53 = *(_T5 + 4)
    parm _T53
    call _PrintInt
    _T54 = "\n"
    parm _T54
    call _PrintString
    _T55 = *(_T5 + 8)
    _T56 = *(_T5 + 12)
    parm _T55
    call _PrintInt
    _T57 = "+"
    parm _T57
    call _PrintString
    parm _T56
    call _PrintInt
    _T58 = "j"
    parm _T58
    call _PrintString
    _T59 = "\n"
    parm _T59
    call _PrintString
    _T60 = *(_T5 + 16)
    parm _T60
    _T61 = *(_T60 + 0)
    _T62 = *(_T61 + 12)
    call _T62
    _T63 = *(_T5 + 20)
    parm _T63
    call _PrintString
    _T64 = "\n"
    parm _T64
    call _PrintString
}

FUNCTION(_people.setage) {
memo '_T6:4'
_people.setage:
    _T65 = *(_T6 + 16)
    _T66 =  call _animal_New
    *(_T6 + 16) = _T66
    _T67 = 100
    parm _T6
    parm _T67
    _T68 = *(_T6 + 0)
    _T69 = VTBL <_people>
    _T70 = *(_T69 + 8)
    call _T70
    _T71 = *(_T6 + 4)
    _T72 = 10
    *(_T6 + 4) = _T72
    _T73 = *(_T6 + 20)
    _T74 = "11"
    *(_T6 + 20) = _T74
    _T75 = *(_T6 + 8)
    _T76 = *(_T6 + 12)
    _T77 = 89
    _T78 = 0
    _T79 = 8
    _T80 = 0
    _T80 = _T77
    _T81 = 0
    _T82 = (_T81 + _T79)
    _T83 = (_T80 + _T78)
    *(_T6 + 8) = _T83
    *(_T6 + 12) = _T82
}

