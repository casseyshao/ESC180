// Lab 8

#include <stdio.h>
#include "ge.c"

// caller of ge_fw() and ge_bw() allocates matrix and matrix_out

int main(void) {

   int numRows = 3;
   int numCols = 3;
   float matrixIn[3*3] = {1,1,1,0,1,2,0,2,1};
   float matrixOut[3*3] = {1,1,1,0,1,2,0,2,1};

   /* print matrixIn and matrixOut */
   printf("Before GE:\n");
   for (int i=0;i<numRows;i++) {
      for (int j=0;j<numCols;j++) {
         printf("%f ",matrixIn[(i*numCols)+j]);
      }
      printf("\n");
   }

   /* testing forward step */
   int r = ge_fw(matrixIn,numRows,numCols,matrixOut);
   printf("After forward step:\n");
   for (int i=0;i<numRows;i++) {
      for (int j=0;j<numCols;j++) {
         printf("%f ",matrixOut[(i*numCols)+j]);
      }
      printf("\n");
   }

   /* testing backward step */
   r = ge_bw(matrixIn,numRows,numCols,matrixOut);
   printf("After backward step:\n");
   for (int i=0;i<numRows;i++) {
      for (int j=0;j<numCols;j++) {
         printf("%f ",matrixOut[(i*numCols)+j]);
      }
      printf("\n");
   }

   numRows = 3;
   numCols = 2;
   float iMatrix[3*2] = {1,5,-2,-7,3,4};
   float oMatrix[3*2] = {1,5,-2,-7,3,4};

   /* print matrixIn and matrixOut */
   printf("Before GE:\n");
   for (int i=0;i<numRows;i++) {
      for (int j=0;j<numCols;j++) {
         printf("%f ",iMatrix[(i*numCols)+j]);
      }
      printf("\n");
   }

   /* testing forward step */
   r = ge_fw(iMatrix,numRows,numCols,oMatrix);
   printf("After forward step:\n");
   for (int i=0;i<numRows;i++) {
      for (int j=0;j<numCols;j++) {
         printf("%f ",oMatrix[(i*numCols)+j]);
      }
      printf("\n");
   }

   /* testing backward step */
   r = ge_bw(iMatrix,numRows,numCols,oMatrix);
   printf("After backward step:\n");
   for (int i=0;i<numRows;i++) {
      for (int j=0;j<numCols;j++) {
         printf("%f ",oMatrix[(i*numCols)+j]);
      }
      printf("\n");
   }

   return 0;   
}
