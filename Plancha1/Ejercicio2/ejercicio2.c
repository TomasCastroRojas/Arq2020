#include <stdlib.h>
#include <stdio.h>

int es_one (long n, int b) {
  while (b < 0 || b > 63) {
    printf ("Ingrese un numero de bit menor a 64:\n");
    scanf ("%d", &b);
  }
  int operando = 1;
  int resultado = (n & (operando << b)) >> b;
  return resultado;
}

int main () {
  long numero;
  int indiceBit, resultado;
  printf ("Ingrese el numero y el indice: \n");
  scanf ("%ld %d", &numero, &indiceBit);
  resultado = es_one (numero, indiceBit);
  if (resultado) printf ("Hay un uno en el indice ingresado\n");
  else printf ("No habia un uno en el indice ingresado\n");
}