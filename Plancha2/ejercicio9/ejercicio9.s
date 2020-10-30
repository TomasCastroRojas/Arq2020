.data
fmt: .string "%d"
entero: .long -100
funcs:  .quad f1
        .quad f2
        .quad f3
f1: movl $0, %esi; movq $fmt, %rdi; call printf; jmp fin
f2: movl $1, %esi; movq $fmt, %rdi; call printf; jmp fin
f3: movl $2, %esi; movq $fmt, %rdi; call printf; jmp fin

.global main
main:
  pushq %rbp
  movq %rsp, %rbp

  # Leemos el entero.
  movq $entero, %rsi
  movq $fmt, %rdi
  xorq %rax, %rax
  call scanf

  xorq %rax, %rax

  movl entero, %ebx
  movq funcs(, %ebx, 8), %rdx
  jmp *%rdx

  fin:
    movq %rbp, %rsp
    popq %rbp
  ret
