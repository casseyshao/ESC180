// Lab 10

#include <stdio.h>
#include <stdlib.h>

/* To handle general numbers, the types of a and b should be int* */
/* n is number of elements inside the input vectors->type int */
/* The output is of type int ** (caller did not allocate output) */

/* compute output vector that contains vector sum of a and b */
int nsum(int *a, int *b, int n, int **output) {
   if (a == NULL || b == NULL || output == NULL) {
      return -1;
   }

   *output = (int *)malloc(sizeof(int)*n);
   for (int i=0;i<n;i++) {
      (*output)[i] = a[i] + b[i];
   }
   return 0;
}

int main(void) {
   int vecA[4] = {3,2,1,4};
   int vecB[4] = {6,9,8,7};
   int *outVec = NULL;

   int r = nsum(vecA,vecB,4,&outVec);
   
   printf("Vector A:\n");
   for (int i=0;i<4;i++) {
      printf("%d ",vecA[i]);
   }
   printf("\n");

   printf("Vector B:\n");
   for (int i=0;i<4;i++) {
      printf("%d ",vecB[i]);
   }
   printf("\n");

   printf("Output vector:\n");
   for (int i=0;i<4;i++) {
      printf("%d ",outVec[i]);
   }
   printf("\n");

   return 0;
}
