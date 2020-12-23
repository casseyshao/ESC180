# Lab 6

# Arguments: a value and a list
# Sum the list:
# if value is 1: if sum is 2 or 3: return 1; else return 0
# otherwise: if sum is 3: return 1; else return 0
def rule(val,Lst):
   sum = 0
   for elem in Lst:
      sum = sum + elem

   if (val == 1):
      if ((sum == 2) or (sum == 3)):
         return 1
      else:
         return 0
   else:
      if (sum == 3):
         return 1
      else:
         return 0