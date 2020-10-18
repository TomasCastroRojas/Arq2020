.global main
main:
  xorl %eax, %eax
  orl $5, %eax
  sal $8, %eax
  ret
