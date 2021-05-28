.global solve

solve:
  pushq %rbp
  movq %rsp, %rbp

  #Calculo del determinante para saber si el sistema tiene solucion
  movss %xmm0, %xmm6    #Copio el valor de 'a' a una variable auxiliar
  movss %xmm1, %xmm7    #Copio el valor de 'b' a una variable auxiliar
  mulss %xmm4, %xmm6    # a*e
  mulss %xmm3, %xmm7    # b*d 
  subss %xmm7, %xmm6    # a*e - b*d
  subss %xmm7, %xmm7    # igualo a cero
  ucomiss %xmm7, %xmm6  # pregunto si el determinante es cero
  jz noSolucion         # si es igual a cero el sistema no tiene solucion

  ucomiss %xmm7, %xmm2  # pregunto si c es igual a cero
  jnz noHomogeneo
  ucomiss %xmm7, %xmm5  # pregunto si f es igual a cero
  jnz noHomogeneo

  # Caso homogeneo
  movss %xmm7, (%rdi)   # x = 0
  movss %xmm7, (%rsi)   # y = 0
  xorb %eax, %eax
  jmp final

  noHomogeneo:
  #Determinamos si es un caso tringular
  ucomiss %xmm7, %xmm0  # Triangular superior invertida
  jz triangularInv
  ucomiss %xmm7, %xmm3  # Triangular superior
  jz triangularSup

  # Caso contrario realizamos Gauss
  divss %xmm0, %xmm3    # d = d/a
  movss %xmm1, %xmm6    # Copio el valor de 'b' a una variable auxiliar
  movss %xmm2, %xmm7    # Copio el valor de 'c' a una variable auxiliar
  mulss %xmm3, %xmm6    # b * (d/a)
  subss %xmm6, %xmm4    # e = e -  b * (d/a)
  mulss %xmm3, %xmm7    # c * (d/a)
  subss %xmm7, %xmm5    # f = f - c * (d/a)

  triangularSup:
    divss %xmm4, %xmm5  # f = f/e
    movss %xmm5, (%rsi) # y = f
    mulss %xmm5, %xmm1  # b = b*y
    subss %xmm1, %xmm2  # c = c - b
    divss %xmm0, %xmm2  # c = c/a
    movss %xmm2, (%rdi) # x = c
    xorb %eax, %eax
    jmp final

  triangularInv:
    divss %xmm1, %xmm2  # c/b
    movss %xmm2, (%rsi) # y = c/b
    mulss %xmm2, %xmm4  # e = e*y
    subss %xmm4, %xmm5  # f = f - e
    divss %xmm3, %xmm4  # f = f/d
    movss %xmm4, (%rdi) # x = f
    xorb %eax, %eax
    jmp final

  noSolucion:
    xorb %eax, %eax
    subb $1, %eax

  final:
  movq %rbp, %rsp
  popq %rbp
  ret
