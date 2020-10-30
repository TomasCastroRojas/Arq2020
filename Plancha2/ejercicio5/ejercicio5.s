 .global fact1
fact1:
    pushq %rbp
    movq %rsp, %rbp
    cmpq $1, %rdi
    jz casobase
    pushq %rdi
    decq %rdi
    call fact1
    popq %rdi
    mulq %rdi
    final:
        movq %rbp, %rsp
        popq %rbp
    ret
    casobase:
        movq %rdi, %rax
        jmp final 

.global fact2
fact2:
    movq $1 , %rax
    movq $0 , %rcx
    movq %rdi , %rcx
    bucle:
        imulq %rcx, %rax
        loop bucle
    ret
