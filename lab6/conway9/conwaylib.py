# Lab 6

import random
from rule import *

class conway:

   def __init__(self,number_list,number_integers,integer_value):
      # x=conway(10,12,'zeros')
      # store consists of 10 lists, each is a list of 12 integers, all set to 0
      self.store=[]
      self.x = number_list
      self.y = number_integers

      # initialize internal lists within self.store
      self.store = [[0 for i in range (0,self.y)] for j in range (0,self.x)]

      for i in range (0, self.x):

         for j in range (0,self.y):
            if integer_value == "zeros":
               #2D structure->need to identify each element with an (x,y) coordinate
               self.store[i][j] = 0
            elif integer_value == "ones":
               self.store[i][j] = 1
            elif integer_value == "random":
               self.store[i][j] = int(random.randint(0,1))

   # return a string corresponding to contents of 'conway' internal 'store' variable
   def getDisp(self):
      string = ""

      # x represents rows
      for i in range (0,self.x):

         # y represents columns
         # loop through internal lists
         for j in range (0,self.y):
            if (self.store[i][j] == 0):
               string = string + " "
            elif (self.store[i][j] == 1):
               string = string + "*"

         string = string + "\n"

      return string
   
   # prints string that getDisp() returns
   def printDisp(self):
      sconway = self.getDisp()
      print(sconway)
   
      return True

   # set row,col element to have value val
   def setPos(self,row,col,val):

      if (row<0 or row>self.x or col<0 or col>self.y):
         print("row or column values are out of range")
         return False

      # val can only be 0 or 1
      if (val == 0 or val == 1):
         self.store[row][col] = val
         return True
      else:
         print("val has wrong value")
         return False

   # return a list of numbers that returns the values of the 8 neighbours (around that position)
   # upper left, top, upper right, left, right, bottom left, bottom, bottom right
   # on a boundary->roll-over
   def getNeighbours(self,row,col):
      neighbour_list = []

      if (row<0 or row>self.x or col<0 or col>self.y):
         print("wrong value for either row or col")
         return False
  
      neighbour_list += [self.store[(((row + self.x)-1)%self.x)][(((col + self.y)-1)%self.y)]]
      neighbour_list += [self.store[(((row + self.x)-1)%self.x)][((col + self.y)%self.y)]]
      neighbour_list += [self.store[(((row + self.x)-1)%self.x)][(((col + self.y)+1)%self.y)]]
      neighbour_list += [self.store[((row + self.x)%self.x)][(((col + self.y)-1)%self.y)]]
      neighbour_list += [self.store[((row + self.x)%self.x)][(((col + self.y)+1)%self.y)]]
      neighbour_list += [self.store[(((row + self.x)+1)%self.x)][(((col + self.y)-1)%self.y)]]
      neighbour_list += [self.store[(((row + self.x)+1)%self.x)][((col + self.y)%self.y)]]
      neighbour_list += [self.store[(((row + self.x)+1)%self.x)][(((col + self.y)+1)%self.y)]]

      return neighbour_list

   def evolve(self,rule_fcn):

      # same dimensions as conwaylib structure but all set to 0
      next_State = [[0 for i in range (0,self.y)] for j in range (0,self.x)]

      # apply rule to each element of the conwaylib structure
      # record the return value of rule as the value of the element you're setting
      for i in range (0,self.x):
         for j in range (0,self.y):
            next_State[i][j] = rule_fcn(self.store[i][j],self.getNeighbours(i,j))

      for i in range (0,self.x):
         for j in range (0,self.y):
            self.store[i][j] = next_State[i][j]

      return True