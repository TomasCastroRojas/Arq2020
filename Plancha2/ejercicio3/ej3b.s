.global main
main:
  xorl %eax, %eax
  orl $1, %eax
  sal $31, %eax
  xorl %eax, %ebx
  orl $1, %ebx
  sal $15, %ebx
  orl %ebx, %eax
  ret
