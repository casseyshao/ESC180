// Lab 10

#include <stdio.h>
#include <stdlib.h>

/* assume caller will not provide an allocated data structure for matrixOut */
/* replace all negative entries in matrixIn with 0 */
/* output result via matrixOut */
/* return 0 for success and -1 for failure */
int fil(float *matrixIn, int rows, int cols, float **matrixOut);

int fil(float *matrixIn, int rows, int cols, float **matrixOut) {
   if (matrixIn == NULL) {
      return -1;
   }

   (*matrixOut) = (float*)malloc(sizeof(float)*rows*cols);

   for (int i=0;i<rows;i++) {
      for (int j=0;j<cols;j++) {
         if (matrixIn[(i*cols)+j] < 0) {
            (*matrixOut)[(i*cols)+j] = 0;
         } else {
            (*matrixOut)[(i*cols)+j] = matrixIn[(i*rows)+j];
         }
      }
   }
   return 0;
}

int main(void) {
   float matrixIn[9] = {0,3,4,2,-1,-5,-7,9,1};
   int rows = 3;
   int cols = 3;
   float *matrixOut = NULL;
   int r = fil(matrixIn,rows,cols,&matrixOut);

   printf("Input matrix\n");
   for (int i=0;i<rows;i++) {
      for (int j=0;j<cols;j++) {
         printf("%f ", matrixIn[(i*cols)+j]);
      }
      printf("\n");
   }

   printf("Output matrix\n");
   for (int i=0;i<rows;i++) {
      for (int j=0;j<cols;j++) {
         printf("%f ", matrixOut[(i*cols)+j]);
      }
      printf("\n");
   }

   return 0;
}
