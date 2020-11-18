#include <stdio.h>

int solve (float a, float b, float c, float d, float e, float f, float *x, float *y);

int main () {
  float x, y;
  int soluble = solve (3, 2, 3, -1, 5, 16, &x, &y);
  if (soluble == 0)
    printf ("Hay solucion: x = %f y = %f\n", x, y);
  else printf ("No hay solucion\n");
  return 0;
}