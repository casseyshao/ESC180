// Lab 8

#include <stdio.h>
#include "sort.c"

// testing
int main(void) {

   int arrayA[5] = {2,5,4,1,3};
   int arrayASize = 5;

   for (int i=0;i<arrayASize;i++) {
      printf("%d ", arrayA[i]);
   }

   printf("\n");

   bubbleSort(arrayA, arrayASize);

   for (int i=0;i<arrayASize;i++) {
      printf("%d ", arrayA[i]);
   }

   printf("\n");

   int arrayB[5] = {2,2,5,1,5};
   int arrayBSize = 5;

   for (int i=0;i<arrayBSize;i++) {
      printf("%d ", arrayB[i]);
   }

   printf("\n");

   bubbleSort(arrayB, arrayBSize);

   for (int i=0;i<arrayBSize;i++) {
      printf("%d ", arrayB[i]);
   }

   printf("\n");

}