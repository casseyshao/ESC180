# Lab 8
# Bubble Sort

# return [status, rval]
# status is True (success) or False (fail)
# rval is sorted list
def bubbleSort(array):
   n = len(array)
   while True:
      swapped = False
      status = False
      for i in range (1,n):
         if (array[i-1] > array[i]):
            array[i],array[i-1] = array[i-1],array[i]
            swapped = True

      if (swapped == False):
         status = True
         break   

   return [status, array]