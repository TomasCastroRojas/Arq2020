.data
  cadenalarga: .asciz "123456"
  cadenacorta: .asciz "123"
.text
.global main
main:
  movq $cadenalarga, %rdi
  movq $cadenacorta, %rsi
  movl $3, %edx #debe ser la longitud de cadenacorta
.global compara
compara:
  xorb %al, %al
  bucle:
    cmpl $0, %edx
    jz retorno
    cmpq %rdi, %rsi
    jnz distintas
    incq %rdi
    incq %rsi
    decl %edx
    jmp bucle

  distintas:
    incb %al
  retorno:
    ret
