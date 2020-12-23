# Lab 3
# Part D

import functools # for reduce()
import operator # for multiplication function in reduce()

# return sum of a and b
def reducingSum(a,b):
   return (a+b)

# return nth fibonacci number
def fibo(n):
   if ((n==0) or (n==1)):
      return 1
   else:
      return (fibo(n-1) + fibo(n-2))

# return a list up to the nth fibonacci number
def fiboL(n):
   L = []
   for i in range (0,n):
      L += [fibo(i)]
   return L

# return product of the first n fibonacci numbers
def fiboProd(n):
   l = fiboL(n)

   product = 1

   for element in l:
      product = product*element

   return product

# return product of the first n fibonacci numbers using reduce
def redfibo(n):
   l = fiboL(n)

   return functools.reduce(operator.mul,l)

# prints first 10 fibonacci numbers
for i in range(0,10):
   print(fibo(i))

# prints list of first 10 fibonacci numbers
l = fiboL(10)
print(l)

# prints product of first 10 fibonacci numbers
print(fiboProd(10))

# prints product of first 10 fibonacci numbers
print(redfibo(10))