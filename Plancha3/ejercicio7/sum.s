.global sum

sum:
  bucle:
    cmpq $0, %rdx
    jz final
    movss (%rdi), %xmm0
    movss (%rsi), %xmm1
    addss %xmm1, %xmm0
    movss %xmm0, (%rdi)
    addq $4, %rsi
    addq $4, %rdi
    decq %rdx
    jmp bucle
    final:
  