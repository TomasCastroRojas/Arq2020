.global main
main:
  xorl %eax, %eax
  orl $1, %eax
  sal $8, %eax
  notl %eax
  andl $-1, %eax
  ret
