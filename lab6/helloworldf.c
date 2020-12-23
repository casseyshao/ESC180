/* Lab 6 */
/* gcc -o hwf helloworldf.c */

#include <stdio.h>

float myAbs(float x);
float bsqrt(float x,float tol);

int main(void) {
   int i;
   for(i=0;i<10;i++){
      float sqrt;
      sqrt=bsqrt((float)i,0.001);
      printf("The sqrt of %d is %f\n",i,sqrt);
   }
   return 0;
}

/* Return absolute value of x */
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
float bsqrt(float x, float dacc) {

   // estimate square root (half of square)
   float est = x/(float)2.0;

   // check that difference between x and square of estimates is less than desired accuracy
   while (1) {
      if (myAbs(x - (est*est)) < dacc) {
         break;
      }
      est = (est + (x/(float)est));
      est = est/(float)2.0;
   }

   return est;
}