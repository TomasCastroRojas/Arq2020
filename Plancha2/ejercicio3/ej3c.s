.global main
main:
  movl $-1, %eax
  andl $-256, %eax
  ret
