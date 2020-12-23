// Lab 6
/* gcc -o bsqrt.out bsqrt.c */

#include<stdio.h>

float myAbs(float x);
float bsqrt(float x, float tol);

float myAbs(float x) {
   if (x>0){
      return x;
   } else if (x<0){
      return -x;
   } else{
      return 0;
   }
}

/* Takes in a float arg x and a float arg accuracy
 * Return a float result that is square root of x
 * Computed via babylonian sqrt method */
float bsqrt(float x, float tol) {

   // estimate square root (half of square)
   float est = x/(float)2.0;

   // check that difference between x and square of estimates is less than desired accuracy
   while (1) {
      if (myAbs(x - (est*est)) < tol) {
         break;
      }
      est = (est + (x/(float)est));
      est = est/(float)2.0;
   }

   return est;
}

int main(void) {
   float x = 0;
   float tol = 0;
   printf("Enter a float: ");
   scanf("%f",&x);
   printf("Again: ");
   scanf("%f",&tol);
   float answerbsqrt = bsqrt(x,tol);
   printf("bsqrt returned %f\n", answerbsqrt);
   return 0;
}