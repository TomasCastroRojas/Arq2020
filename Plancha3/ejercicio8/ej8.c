#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LARGO 10000
#define BILLION 1E9

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


  free (arrayA);
  free (arrayB);
  return 0;
}