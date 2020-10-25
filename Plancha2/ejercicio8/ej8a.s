.data
  cadena: .asciz "123456"
.text
.global main
main:
  movq $cadena, %rdi
  movb $'9', %sil #Probar luego con diferentes valores (1,a,5....)
.global busca
busca:
  xorq %rcx, %rcx
  bucle:
    cmpb (%rdi, %rcx), %sil
    jz encuentra
    cmpq $0, (%rdi, %rcx)
    jz noEncuentra
    inc %rcx
    jmp bucle
  encuentra:
    leaq (%rdi, %rcx), %rax
    jmp fin
  noEncuentra:
    movq $-1, %rax
  fin:
    ret
