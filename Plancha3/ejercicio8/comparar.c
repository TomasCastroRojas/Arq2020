#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LARGO 100000
#define BILLION 1E9

void sum_simd (float *a, float *b, int len);

void sum (float *a, float *b, int len);

float* crear_array (float valInicial, float inc, int largo){
  float *arreglo = malloc (sizeof (float) * largo);
  for (int i = 0; i < largo; i++) {
    arreglo[i] = valInicial;
    valInicial += inc;
  }
  return arreglo;
}

int main () {
  float *arrayA_single = crear_array (1, 1, LARGO);
  float *arrayB_single = crear_array (1, 1, LARGO);

  float *arrayA_packed = crear_array (1, 1, LARGO);
  float *arrayB_packed = crear_array (1, 1, LARGO);

  // Ejecucion de la funcion
  struct timespec requestStart, requestEnd;
  clock_gettime (CLOCK_MONOTONIC_RAW , &requestStart);
  sum (arrayA_single, arrayB_single, LARGO);
  clock_gettime (CLOCK_MONOTONIC_RAW , &requestEnd);

  // Calculo de cuanto tiempo tomo
  double accum = (requestEnd.tv_sec - requestStart.tv_sec ) + (requestEnd.tv_nsec - requestStart.tv_nsec )/BILLION;
  printf ("Tiempo sum: %lf\n", accum);

  clock_gettime (CLOCK_MONOTONIC_RAW , &requestStart);
  sum_simd (arrayA_packed, arrayB_packed, LARGO);
  clock_gettime (CLOCK_MONOTONIC_RAW , &requestEnd);

  accum = (requestEnd.tv_sec - requestStart.tv_sec ) + (requestEnd.tv_nsec - requestStart.tv_nsec )/BILLION;
  printf ("Tiempo sum_simd: %lf\n", accum);


  free (arrayA_single);
  free (arrayB_single);
  free (arrayA_packed);
  free (arrayB_packed);
  return 0;
}