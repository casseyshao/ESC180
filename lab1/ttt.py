# Test Lab 1
# Pseudocode given in lab instructions

from tttlib import *

T = genBoard()

while (True):

   printBoard(T)

   # check moveX for valid input
   # if valid and if T is unoccupied at moveX, set appropriate position of T to X
   # check index number and then its element value
   while (True):
      moveX = int(input("X move: "))
      if ((moveX>=0)and(moveX<= 8)and(T[moveX]==0)):
         T[int(moveX)] = 1
         break
      else:
         print(str(moveX) + " is an invalid move. Try again!")

   state = analyzeBoard(T)

   # check if state says X won and act accordingly and break
   # check if state says draw and act accordingly and break
   if (state==1):
      print("X won! Game over!")
      break
   elif (state==3):
      print("Draw! Game over!")
      break

   printBoard(T)

   # check moveO for valid input
   # if valid and if T is unoccupied at moveO, set appropriate position of T to O
   # check index number and then its element value
   while True:
      moveO = int(input("O move: "))
      if ((moveO>=0)and(moveO<=8)and(T[int(moveO)]==0)):
         T[int(moveO)] = 2
         break
      else:
         print(str(moveO) + " is an invalid move. Try again!")

   state = analyzeBoard(T)

   #check if state says O won and act accordingly and break
   #check if state says draw and act accordingly and break
   if (state == 2):
      print("O won! Game over!")
      break
   elif (state == 3):
      print("Draw! Game over!")
      break
