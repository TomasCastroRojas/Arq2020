#include <stdio.h>
#include <ieee754.h>

#define EXP(X)  (((*(unsigned*)(&X)) >> 23) & 0xff)
#define FRACCION(X) ((*(unsigned*)(&X)) & 0x7fffff)


int main () {
  float numero = 3.14;
  union ieee754_float num;
  num.f = numero;

  printf ("exponente: %d\n", EXP (numero));
  printf ("chequeo exponente: %d\n", num.ieee.exponent);

  printf ("mantisa: %d\n", FRACCION (numero));
  printf ("chequeo mantisa: %d\n", num.ieee.mantissa);
  return 0;
}