#include <setjmp.h>
#include <stdio.h>
int setjmp2 (jmp_buf b);
void longjmp2(jmp_buf c,int valor);

int main() {
    jmp_buf b;
    int a = 1;
    int res;
    if ((res = setjmp2(b)) == 0) {
        printf("Haciendo cálculo...\n");
        a--;
        if (a == 0) {
            longjmp2(b, 10);
        }
        printf("%d\n", 1 / a);
    } 
    else {    
        printf("Error\n");
    }
    return 0;     
}