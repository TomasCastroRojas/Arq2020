#include <stdio.h>
#include <math.h>
#include <ieee754.h>

#define EXP(X)  ((*(int*)(&X) >> 23) & 0xff)
#define FRACCION(X) ((*(int*)(&X)) & 0x7fffff)

int myisnan (float numero) {
  return (EXP(numero) == 255) && (FRACCION(numero) != 0);
}

int myisnan2 (float numero) {
  union ieee754_float num;
  num.f = numero;
  return num.ieee_nan.quiet_nan == 1;
}

int main() {
  float g = 0.0;
  float f = 0.0 / g;
  float inf = 1.0 / g;
  printf ("f: %f\n", f);
  printf ("inf: %f\n", inf);
  if (f == NAN)
    printf("Es NAN\n");
  if (isnan (f))
    printf ("isNaN dice que sı́\n");
  if (myisnan (f))
    printf ("myisNaN dice que sı́\n");
  if (myisnan2 (f))
    printf ("myisNaN2 dice que sı́\n");

  if (inf == INFINITY)
    printf ("Es +infinito\n");
  inf += 1;
  if (inf == INFINITY)
    printf ("+infinito + 1 es +infinito\n");
  // Aca vemos que con +infinito no sucede lo mismo que con NaN
  // Intuimos que esto ocurre asi ya que NaN tiene varias representaciones
  // mientras que la representacion de +infinto es unica.
  // Luego al sumar un valor a +infinito es igual a +infinito lo cual tiene
  // sentido matematicamente. Computacionalmente creemos que C o el compilador
  // debe identificar que es +infinito y no modifica su representacion.
  return 0;
}