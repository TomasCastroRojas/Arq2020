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
  xorl %eax, %eax
  bucle:
    cmpl $0, %edx
    jz retorno
    cmpsb (%rdi), (%rsi)
    jnz distintas
    decl %edx
    jmp bucle

  distintas:
    incl %eax
  retorno:
    ret
