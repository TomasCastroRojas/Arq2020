#include <stdio.h>

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

int main () {
  printf ("resultado: %d\n", campesino_ruso(3, 2));
}