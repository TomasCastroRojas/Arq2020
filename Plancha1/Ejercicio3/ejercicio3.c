#include <stdlib.h>
#include <stdio.h>

void printbin (unsigned long n) {
  int numero[64];
  for (int i = 63; i >= 0; --i) {
    numero[i] = n % 2;
    n = n / 2;
  }
  printf ("El numero en binario es:");
  for (int i = 0; i < 64; ++i) {
    if (i % 8 == 0) printf (" ");
    printf ("%d", numero[i]);
  }
  printf ("\n");
}

int main () {
  unsigned long N;
  printf ("Ingrese un numero: ");
  scanf ("%ld", &N);
  printbin (N);
}