.data
format: .asciz "%ld\n"
formatHex: .asciz "0x%08X\n"
i:      .quad 0xDEADBEEF
.text
.global main
main:
  #Ejemplo
  movq $format, %rdi
  movq $1234, %rsi
  xorq %rax, %rax
  call printf

  #Apartado a
  movq $format, %rdi
  movq %rsp, %rsi
  xorq %rax, %rax
  call printf

  #Apartado b
  movq $format, %rdi
  movq $format, %rsi
  xorq %rax, %rax
  call printf

  #Apartado c
  movq $formatHex, %rdi
  movq $format, %rsi
  xorq %rax, %rax
  call printf

  #Apartado d
  movq $format, %rdi
  movq (%rsp), %rsi
  xorq %rax, %rax
  call printf

  #Apartado e
  movq $format, %rdi
  movq 8(%rsp), %rsi
  xorq %rax, %rax
  call printf

  #Apartado f
  movq $formatHex, %rdi
  movq i, %rsi
  xorq %rax, %rax
  call printf

  #Apartado g
  movq $format, %rdi
  leaq i, %rsi
  xorq %rax, %rax
  call printf

  ret
