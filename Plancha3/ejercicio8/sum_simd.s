.global sum_simd

sum_simd:
  condicion:
    cmpq $0, %rdx
    jz final
    cmpq $4, %rdx
    jl bucleS
  #Bucle Packed
    movaps (%rdi), %xmm0
    movaps (%rsi), %xmm1
    addps %xmm1, %xmm0
    movaps %xmm0, (%rdi)
    addq $16, %rsi
    addq $16, %rdi
    subq $4, %rdx
    jmp condicion
  bucleS:
    movss (%rdi), %xmm0
    movss (%rsi), %xmm1
    addss %xmm1, %xmm0
    movss %xmm0, (%rdi)
    addq $4, %rsi
    addq $4, %rdi
    decq %rdx
    jmp condicion
  final:
