# Lab 4

# class extends python with a new 'datatype'
class counter:

   #initCnt is the starting value of cnt variable in the class
   def __init__(self,initCnt):
      self.cnt = initCnt
   
   def evolve(self,x):
      self.cnt = self.cnt + x

   def getState(self):
      return self.cnt