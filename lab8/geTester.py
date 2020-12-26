# Lab 8

from ge import *

# testing

# 3 by 3->2 zero rows
print("Input Matrix:")
mat = [[3,2,1],[6,4,2],[9,6,3]]
for i in range(0,len(mat)):
   print(mat[i])

print("After Forward Step:")
matf = ge_fw(mat)
# should print: [[3,2,1],[0,0,0],[0,0,0]]
for i in range(0,len(matf)):
   print(ge_fw(matf)[i])

print("After Backward Step:")
matb = ge_bw(matf)
# should print: [[1,2/3,1/3],[0,1,0],[0,0,0]]
for i in range(0,len(matb)):
   print(matb[i])

# 3 by 3->2 nonzero rows
print("Input Matrix:")
mat0 = [[1,1,1],[0,1,2],[0,2,1]]
for i in range(0,len(mat0)):
   print(mat0[i])

print("After Forward Step:")
mat0f = ge_fw(mat0)
# should print: [[1,1,1],[0,1,2],[0,0,-3]]
for i in range(0,len(mat0f)):
   print(ge_fw(mat0f)[i])

print("After Backward Step:")
mat0b = ge_bw(mat0f)
# should print: [[1,0,0],[0,1,0],[0,0,1]]
for i in range(0,len(mat0b)):
   print(mat0b[i])

# 3 by 2
print("Input Matrix:")
mat1 = [[1,5],[-2,-7],[3,4]]
for i in range(0,len(mat1)):
   print(mat1[i])

print("After Forward Step:")
mat1f = ge_fw(mat1)
# should print: [[1,5],[0,3],[0,0]]
for i in range(0,len(mat1f)):
   print(mat1f[i])

print("After Backward Step:")
mat1b = ge_bw(mat1f)
# should print: [[1,0],[0,1],[0,0]]
for i in range(0,len(mat1b)):
   print(mat1b[i])

# 2 by 3
print("Input Matrix:")
mat2 = [[1,5,3],[-2,-7,4]]
for i in range(0,len(mat2)):
   print(mat2[i])

print("After Forward Step:")
mat2f = ge_fw(mat2)
# should print: [[1,5],[0,3],[0,0]]
for i in range(0,len(mat2f)):
   print(mat2f[i])

print("After Backward Step:")
mat2b = ge_bw(mat2f)
# should print: [[1,0],[0,1],[0,0]]
for i in range(0,len(mat2b)):
   print(mat2b[i])