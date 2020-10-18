#include <stdio.h>
#include <stdlib.h>

void swap (int *a, int* b, int* c) {
  *a = *a ^ *b ^ *c;
  *b = *a ^ *b ^ *c; // (a ^ *b ^ *c) ^ b ^ c = a;
  *c = *a ^ *b ^ *c; // (a ^ *b ^ *c) ^ a ^ c = b;
  *a = *a ^ *b ^ *c; // (a ^ *b ^ *c) ^ a ^ b = c;
}

int main () {
  int a, b, c;
  printf ("Ingrese 3 numeros: \n");
  scanf ("%d %d %d", &a, &b, &c);
  swap (&a, &b, &c);
  printf ("a = %d, b = %d, c = %d\n", a, b, c);
}