.data
  cadena: .asciz "123456"
.text
.global main
main:
  movq $cadena, %rdi
  movb $'3', %sil #Probar luego con diferentes valores (1,a,5....)
.global busca
busca:
  xorq %rcx, %rcx
  bucle:
    cmpb (%rdi), %sil
    jz encuentra
    cmpq $0, (%rdi)
    jz noEncuentra
    inc %rdi
    jmp bucle
  encuentra:
    movq %rdi, %rax
    jmp fin
  noEncuentra:
    movq $-1, %rax
  fin:
    ret
