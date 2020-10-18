.global main
main:
  xorq %rax, %rax
  movw $-1, %ax
  movw $2, %cx
  mulw %cx
  sal $16, %edx
  orl %edx, %eax
  ret
