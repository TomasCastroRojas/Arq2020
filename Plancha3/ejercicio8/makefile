SUM = ../ejercicio7/sum.s

comparar: comparar.c sum_simd.s $(SUM)
	gcc -o comparar.out -Wall -Werror -g comparar.c sum_simd.s $(SUM)

sum_simd: ej8.c sum_simd.s
	gcc -o sum_simd.out -Wall -Werror -g ej8.c sum_simd.s