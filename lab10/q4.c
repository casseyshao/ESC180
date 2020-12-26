// Lab 10

/*This is a recursive function*/

/* f(5):
 * return 5*f(3)

 * f(3):
 * return 3*f(1)

 * f(1):
 * return 1*f(-1)

 * f(-1):
 * return 2

 * 2*1*3*5 = 30 */

#include <stdio.h>

int f(int x) {
   if (x==-1) {
      return 2;
   } else {
      return x*f(x-2);
   }
}

int main(void) {
   printf("%d\n",f(5));
   return 0;
}
