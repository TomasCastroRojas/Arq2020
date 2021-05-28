.global campesino_ruso
campesino_ruso:
  EOR r2, r2, r2     @ r2 = res = 0
  bucle:
    CMP r1, #1
    BLS fin
    ANDS r3, r1, #1    @ j & 1
    ADDNE r2, r2, r0   @ res += i
    SUBNE r1, r1, #1   @ j -= 1;
    LSLEQ r0, #1       @ i += 2;
    LSREQ r1, #1       @ j /= 2;
    B bucle
  fin:
    ADD r0, r0, r2     @ i += res
    Bx lr
