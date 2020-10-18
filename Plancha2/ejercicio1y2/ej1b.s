.global main
main:  
  movb $0xFE, %al
  movb $-1, %bl
  addb %bl, %al
  incb %bl
  ret
