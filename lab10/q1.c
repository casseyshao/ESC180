#include <stdio.h>
#include <stdlib.h>

/* return average of an array of floats */
/* use most general argument type for array->pointer (context of lectures) */
float average(float *array, int size);

float average(float *array, int size) {
   if (array == NULL) {
      return -1;
   }

   float sum = 0.0;
   for(int i=0;i<size;i++) {
      sum = sum+array[i];
   }

   return((float)sum/size);
}

/*
int main(void) {
   int size = 5;
   float testArray[5] = {1.0,2.5,3.0,4.5,5.0};
   printf("Should be 3.2: %f\n",average(testArray,size));
   return 0;
}
*/
