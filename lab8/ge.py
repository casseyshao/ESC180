# Lab 8
# Gaussian Elimination
# using Pivoting

# forward step
# argument: matrix->list of lists
# elements of matrix are floats
# return resultant matrix
# at end: entries in column beneath first nonzero entry in each row are all zero
def ge_fw(matrix):

   retMatrix = matrix
   numRow = len(retMatrix)
   numCol = len(retMatrix[0])
   currRowIdx = 0

   while (currRowIdx < (numRow-1)):
   
      # find first row with a nonzero entry in the first column
      for i in range (currRowIdx,numRow):
         if ((i==currRowIdx) and (retMatrix[i][currRowIdx] != 0)):
            break
         elif (retMatrix[i][currRowIdx] != 0):
            # interchange this row with first row
            retMatrix[currRowIdx], retMatrix[i] = retMatrix[i], retMatrix[currRowIdx]
            break

      # ensure lower entries of first of first column are all zero
      for i in range (currRowIdx+1,numRow,1):
         factor = 0

         if (retMatrix[currRowIdx][currRowIdx]==0):
            break

         # top right corner->first nonzero entry in that row
         if (retMatrix[currRowIdx][currRowIdx]!=0):
            factor = retMatrix[i][currRowIdx]/retMatrix[currRowIdx][currRowIdx]

         # subtract required multiple of first row to lower rows
         for j in range (currRowIdx,numCol):
            if (retMatrix[currRowIdx][j]==0):
               continue
            retMatrix[i][j] = retMatrix[i][j]-((retMatrix[currRowIdx][j])*factor)

      # do the same to all submatrices
      currRowIdx+=1

   return retMatrix

# backward step
# argument: matrix->list of lists
# return resultant matrix
# at end: matrix is in reduced normal form
def ge_bw(matrix):

   retMatrix = matrix
   numRow = len(matrix)
   numCol = len(retMatrix[0])
   currRowIdx = len(matrix)-1

   while (currRowIdx > 0):
      
      normFactor = 1
      nonZeroCol = 0 # index of column with nonzero value
      nonZero = 0

      # find last nonzero row
      i = 0

      if (numCol >= numRow):
         i = currRowIdx
      else:
         i = numCol-1

      while (i>=0):
         if (retMatrix[currRowIdx][i] != 0):
            normFactor = retMatrix[currRowIdx][i]
            nonZeroCol = i
            nonZero = 1
            break
         else:
            i-=1
     
      if (nonZero == 0):
         currRowIdx-=1
         continue # this row is all zeros, check earlier rows

      # normalize row by its first nonzero entry
      for i in range (0,numCol):
         if (retMatrix[currRowIdx][i] == 0):
            continue
         retMatrix[currRowIdx][i] = (retMatrix[currRowIdx][i])/normFactor

      # add multiples of this row to previous rows
      # want all entries in column containing leading 1 to be 0
      for i in range (currRowIdx-1,-1,-1):
         factor = retMatrix[i][nonZeroCol]/retMatrix[currRowIdx][nonZeroCol]   
         for j in range (0,numCol):
            retMatrix[i][j] = retMatrix[i][j]-((retMatrix[currRowIdx][j])*factor)

      # do the same to all submatrices
      # form submatrix obtained by deleting this row and apply backward step to it
      currRowIdx-=1

   # normalize first row
   normFactor = retMatrix[0][0]
   for i in range (0,numCol):
      if (retMatrix[0][i] == 0):
         continue
      retMatrix[0][i] = (retMatrix[0][i])/normFactor

   return retMatrix