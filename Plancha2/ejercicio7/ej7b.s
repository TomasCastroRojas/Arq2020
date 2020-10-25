.text
.global main
main:
  movq $64, %rcx
  xorb %bl,%bl
ciclo:
  rol $1, %rax
  adcb $0, %bl
  loop ciclo
  movb %bl, %al
  ret
