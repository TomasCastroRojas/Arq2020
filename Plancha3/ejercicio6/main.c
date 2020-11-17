#include <stdio.h>

int solve (float a, float b, float c, float d, float e, float f, float *x, float *y);

int main () {
  float x, y;
  solve (3, 2, 3, -1, 5, 16, &x, &y);
  printf ("x = %f y = %f\n", x, y);
  return 0;
}