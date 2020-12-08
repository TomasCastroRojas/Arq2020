.global campesino_ruso
.global main
main:
  MOV r0, #2         @ r0 = i
  MOV r1, #3         @ r1 = j
  EOR r2, r2, r2     @ r2 = res = 0
campesino_ruso:
  ANDS r3, r1, #1    @ j & 1
  ADDNE r2, r2, r0   @ res += i
  SUBNE r1, r1, #1   @ j -= 1;
  LSLEQ r0, #1       @ i += 2;
  LSREQ r1, #1       @ j /= 2;
  CMP r1, #1
  BHI campesino_ruso @ jump if j > 1
  ADD r0, r0, r2     @ i += res
  Bx lr
