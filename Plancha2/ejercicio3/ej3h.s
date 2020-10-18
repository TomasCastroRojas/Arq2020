.global main
main:
  movl $0x80000000, %eax
  addl $0x80000000, %eax
  ret
