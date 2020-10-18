.global main
main:
  xorl %eax, %eax
  orl $1, %eax
  sal $31, %eax
  ret
