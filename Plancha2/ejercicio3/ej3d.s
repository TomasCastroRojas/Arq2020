.global main
main:
  movl $0xAA, %eax
  sal $24, %eax
  orl $0xAA, %eax
  ret
