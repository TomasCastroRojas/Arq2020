#include "guindows.h"
#include <stdio.h>

static task t1, t2, t3, taskmain;

static void ft1() {
  int var1;
  printf ("var1: %p\n", &var1);
  for (double d = -1; ; d += 0.001) {
    printf("d = %f\n", d);
    TRANSFER(t1, t2);
  }
}

static void ft2() {
  int var2;
  printf ("var2: %p\n", &var2);
  for (unsigned i = 0; i < 10000; i++) {
    printf("i = %u\n", i);
    TRANSFER(t2, t3);
  }
}

static void ft3() {
  int var3;
  printf ("var3: %p\n", &var3);
  for (unsigned i = 0; i < 5; i++) {
    printf("t3 i = %u\n", i);
    TRANSFER(t3, t1);
  }
  TRANSFER(t3, taskmain);
}

int main() {
  stack (t1, ft1);
  stack (t2, ft2);
  stack (t3, ft3);
  TRANSFER (taskmain, t1);
  return 0;
}

/* Las direcciones de las variables locales son:
var1: 0x7ffe1a93171c
var2: 0x7ffe1a932740
var3: 0x7ffe1a933730

Podemos ver que hay mucha diferencia entre las direcciones de las variables
locales. 
*/