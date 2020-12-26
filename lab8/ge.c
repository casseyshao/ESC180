// Lab 8
// Gaussian Elimination
// using Pivoting

// caller of ge_fw() and ge_bw() allocates matrix and matrix_out
// define matrix via mathematical relationship to obtain [r,c] element of matrix M
// M[(r*num_columns)+c]


// return 0 for success and -1 for failure
// rows is number of rows in matrix (similar to cols)
int ge_fw(float *matrix, int rows, int cols, float *matrix_out) {
   if (matrix==NULL || matrix_out ==NULL || rows==0 || cols==0) {
      return -1;
   }

   int currRowIdx = 0;
   while (currRowIdx < rows-1) {

      // find first row with nonzero entry in first column
      for (int i=currRowIdx;i<rows;i++) {
         if ((i == currRowIdx) && (matrix_out[(i*cols)+currRowIdx] != 0)) {
            break;
         } else if (matrix_out[(i*cols)+currRowIdx] != 0) {
            // interchange with first row (make that first row in matrix_out)
            // want first row to have nonzero entry in first column
            for (int j=currRowIdx;j<cols;j++) {
               float temp = matrix_out[(currRowIdx*cols)+j];
               matrix_out[(currRowIdx*cols)+j] = matrix_out[(i*cols)+j];
               matrix_out[(i*cols)+j] = temp;
               break;
            }
            break;
         }
      }

      // add multiples of first row to lower rows
      // want lower entries of first column to be zero
      for (int i=currRowIdx+1;i<rows;i++) {
         float factor = 1;

         if (matrix_out[(currRowIdx*cols)+currRowIdx] == 0) {
            break;
         } else {
            factor = (float)matrix_out[(i*cols)+currRowIdx]/matrix_out[(currRowIdx*cols)+currRowIdx];
         }

         for (int j=currRowIdx;j<cols;j++) {
            if (matrix_out[(currRowIdx*cols)+j] == 0) {
               continue;
            }
            matrix_out[(i*cols)+j] = matrix_out[(i*cols)+j]-((matrix_out[(currRowIdx*cols)+j]*factor));
         }
      }

      // for submatrix arising from deleting the first row and column
      // apply forward step to submatrix
      currRowIdx+=1;
   }

   return 0;
}

// return 0 for success and -1 for failure
// rows is number of rows in matrix (similar to cols)
int ge_bw(float *matrix, int rows, int cols, float *matrix_out) {
   if (matrix==NULL || matrix_out ==NULL || rows==0 || cols==0) {
      return -1;
   }

   int currRowIdx = rows-1;
   float normFactor = 1.0;
   int nonZeroRow = 0;
   while (currRowIdx > 0) {

      normFactor = 1.0;
      nonZeroRow = 0;
      int nonZeroCol = 0;

      // find last nonzero row
      int i = 0;
      if (cols >= rows) {
         i = currRowIdx;
      } else {
         i = cols-1;
      }

      // find first nonzero entry in last nonzero row
      while (i>=0) {
         if (matrix_out[(currRowIdx*cols)+i] != 0) {
            normFactor = matrix_out[(currRowIdx*cols)+i];
            nonZeroCol = i;
            nonZeroRow = 1;
            break;
         } else {
            i-=1;
         }
      }

      if (nonZeroRow == 0) {
         currRowIdx-=1;
         continue; // this row is all zeros, check rows above
      }

      // normalize row by its first nonzero entry
      for (int i=0;i<cols;i++) {
         if (matrix_out[(currRowIdx*cols)+i] == 0) {
            continue;
         }
         matrix_out[(currRowIdx*cols)+i] = (float)matrix_out[(currRowIdx*cols)+i]/normFactor;
      }

      // add multiples of this row to previous rows
      // want all entries in column containing leading 1 to be zeros
      for (int i=currRowIdx-1;i>-1;i--) {
         float factor = matrix_out[(i*cols)+nonZeroCol]/matrix_out[(currRowIdx*cols)+nonZeroCol];
         for (int j=0;j<cols;j++) {
            matrix_out[(i*cols)+j] = matrix_out[(i*cols)+j]-((matrix_out[(currRowIdx*cols)+j]*factor));
         }
      }

      // form submatrix obtained by deleting this row
      // apply backward step to submatrix
      currRowIdx-=1;
   }

   // normalize first row
   normFactor = matrix_out[0];
   for (int i=0;i<cols;i++) {
      if (matrix_out[i] == 0) {
         continue;
      }
      matrix_out[i] = (float)matrix_out[i]/normFactor;
   }

   return 0;
}
