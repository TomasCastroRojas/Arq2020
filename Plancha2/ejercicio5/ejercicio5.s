 .global fact1
fact1:
    pushq %rbp
    movq %rsp, %rbp
    cmpq $0, %rdi #Caso factorial (0)
    jnz recursion
    movq $1, %rax
    jmp final1

    recursion:
      cmpq $1, %rdi
      jz casobase
      pushq %rdi
      decq %rdi
      call fact1
      popq %rdi
      mulq %rdi
    final1:
        movq %rbp, %rsp
        popq %rbp
    ret
    casobase:
        movq %rdi, %rax
        jmp final1 

.global fact2
fact2:
    pushq %rbp
    movq %rsp, %rbp
    movq $1 , %rax
    cmpq $0, %rdi #Caso factorial (0)
    jz final
    movq %rdi , %rcx
    bucle:
        mulq %rcx
        loop bucle
    final:
      movq %rbp, %rsp
      popq %rbp
      ret
