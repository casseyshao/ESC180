// Lab 10

/* values of all variables at point HERE:
 * a points to c
 * b points to c
 * c = 0;
 * d = 100;
 * q = 110; */

#include <stdio.h>

int main(void) {
   int *b;
   int **a;
   int c = 10;
   int d = 20;
   int q = 30;
   b = &c;
   a = &b;
   q = **a;
   *b = 0;
   d = c+100;
   q = q+100;
   /* HERE */

   /* a points to c */
   printf("**a: %d   *b: %d   c: %d\n", **a, *b, c);
   /* b points to c */
   printf("b: %p   &c: %p\n", (void *)b, (void *)&c);
   /* c = 0 */
   printf("c: %d\n", c);
   /* d = 100 */
   printf("d: %d\n", d);
   /* q = 110 */
   printf("q: %d\n", q);

   return 0;
}
