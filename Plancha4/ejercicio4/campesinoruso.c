#include <stdio.h>
#include <stdlib.h>

// COMPILAR UTILIZANDO: arm-linux-gnueabi-gcc -static -marm -o campesino_ruso.out -g campesinoruso.c ej4.s

unsigned int campesino_ruso(unsigned int i, unsigned int j);

/*unsigned int campesino_ruso(unsigned int i, unsigned int j) {
  unsigned int res = 0;
  unsigned iter = 0;
  while (j > 1) {
    if (j & 1) {
      res += i;
      j -= 1;
      printf ("iter %d -- res = %d -- j = %d\n", iter, res, j);
      iter++;
    } else {
      i *= 2;
      j /= 2;
      printf ("iter %d -- i = %d -- j = %d\n", iter, i, j);
      iter++;
    }
  }
  return res + i;
}*/

int main (int argc, char* argv[]) {
  if (argc == 3){
    unsigned int a = atoi(argv[1]);
    unsigned int b = atoi(argv[2]);
    printf ("El resultado es: %d\n", campesino_ruso(a, b));
  }
  else printf ("No se ingreso la cantidad correcta de argumentos");
}