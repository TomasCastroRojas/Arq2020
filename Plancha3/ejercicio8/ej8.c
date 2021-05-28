#include <stdio.h>
#include <stdlib.h>
#define LARGO 10

void sum_simd (float *a, float *b, int len);

float* crear_array (float valInicial, float inc, int largo){
  float *arreglo = malloc (sizeof (float) * largo);
  for (int i = 0; i < largo; i++) {
    arreglo[i] = valInicial;
    valInicial += inc;
  }
  return arreglo;
}

void imprimir_array (float *arr, int len) {
  for (int i = 0; i < len; i++) printf ("%d: %f\n", i, arr[i]);
}

int main () {
  float *arrayA = crear_array (1, 1, LARGO);
  float *arrayB = crear_array (1, 1, LARGO);

  printf ("Arreglo A\n");
  imprimir_array (arrayA, LARGO);
  printf ("Arreglo B\n");
  imprimir_array (arrayB, LARGO);
  sum_simd (arrayA, arrayB, LARGO);
  printf ("Arreglo suma\n");
  imprimir_array (arrayA, LARGO);

  free (arrayA);
  free (arrayB);
  return 0;
}