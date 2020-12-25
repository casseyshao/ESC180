# Test Lab 2

from tttlib import *

T= genBoard()

printBoard(T)

while True:

   player = 2

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

   printBoard(T)

   state = analyzeBoard(T)

   # check if state says X won and act accordingly and break
   # check if state says draw and act accordingly and break
   if (state==1):
      print("X won! Game over!")
      break
   elif (state==3):
      print("Draw! Game over!")
      break

   print("Computer's turn")
   # computer's turn
   while (True):
      moveO = genWinningMove(T,player)
      if (moveO>=0):
         print("Winning move")
         T[int(moveO)] = 2
         break
      
      moveO = genNonLoser(T,player)
      if (moveO>=0):
         print("Not losing move")
         T[int(moveO)] = 2
         break
      
      moveO = genRandomMove(T,player)
      if (moveO>=0):
         print("Random move")
         T[int(moveO)] = 2
         break

      moveO = genOpenMove(T,player)
      if (moveO>=0):
         print("Open move")
         T[int(moveO)] = 2
         break

   state = analyzeBoard(T)

   printBoard(T)

   #check if state says O won and act accordingly and break
   #check if state says draw and act accordingly and break
   if (state == 2):
      print("O won! Game over!")
      break
   elif (state == 3):
      print("Draw! Game over!")
      break
