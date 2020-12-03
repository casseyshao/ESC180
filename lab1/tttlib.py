# Lab 1

# No argument
# Return list corresponding to an unoccupied board
def genBoard():
   return [0,0,0,0,0,0,0,0,0]

# T is data structure for TTT board
# Board position is printed if position is unoccupied
# X printed if board position occupied by value 1
# O printed if board position occupied by value 2
def printBoard(T):

   # check to ensure that the list has exactly 9 elements
   if (len(T)!=9):
      return False

   acc = []

   for i in range (0,9):
      if (T[i]==0):
         acc = acc+[i]
      elif (T[i]==1):
         acc = acc+["X"]
      elif (T[i]==2):
         acc = acc+["O"]
      else:
         return False

   print(" " + str(acc[0]) + " | " + str(acc[1]) + " | " + str(acc[2]))
   print("---|---|---")
   print(" " + str(acc[3]) + " | " + str(acc[4]) + " | " + str(acc[5]))
   print("---|---|---")
   print(" " + str(acc[6]) + " | " + str(acc[7]) + " | " + str(acc[8]))
   return True

# Return game state:
# Return 0 for board in play
# Return 1 for X won
# Return 2 for O won
# Return 3 for draw
# Return -1 for error with T
def analyzeBoard(T):

   # check to ensure that the list has exactly 9 elements
   if (len(T)!=9):
      return -1

   # check to ensure that the number of X's to O's is within a range of + or - 1
   Xcount = 0
   Ocount = 0

   for element in T:
      if (element==1):
         Xcount = Xcount+1
      elif (element==2):
         Ocount = Ocount+1

   if (((Xcount-Ocount)>1)or((Ocount-Xcount)>1)):
      return -1

   # check to ensure that elements in T have values 0, 1, or 2
   for element in T:
      if ((element!=0)and(element!=1)and(element!=2)):
         return -1

   # at start of game, neither X nor O has won, so both are False
   Xwin = False
   Owin = False

   # ways for X to win
   if(
   (T[0]==1 and T[1]==1 and T[2]==1) or
   (T[3]==1 and T[4]==1 and T[5]==1) or
   (T[6]==1 and T[7]==1 and T[8]==1) or
   (T[0]==1 and T[3]==1 and T[6]==1) or
   (T[1]==1 and T[4]==1 and T[7]==1) or
   (T[2]==1 and T[5]==1 and T[8]==1) or
   (T[0]==1 and T[4]==1 and T[8]==1) or
   (T[6]==1 and T[4]==1 and T[2]==1)):
      Xwin = True

   # ways for O to win 
   if(
   (T[0]==2 and T[1]==2 and T[2]==2) or
   (T[3]==2 and T[4]==2 and T[5]==2) or
   (T[6]==2 and T[7]==2 and T[8]==2) or
   (T[0]==2 and T[3]==2 and T[6]==2) or
   (T[1]==2 and T[4]==2 and T[7]==2) or
   (T[2]==2 and T[5]==2 and T[8]==2) or
   (T[0]==2 and T[4]==2 and T[8]==2) or
   (T[6]==2 and T[4]==2 and T[2]==2)):
      Owin = True

   if ((Xwin==True)and(Owin==True)):
      return -1
   elif ((Xwin==True)and(Owin==False)):
      return 1
   elif ((Xwin==False)and(Owin==True)):
      return 2
   elif 0 in T: # if there is a 0 in T, board still in play, not all spots filled
      return 0
   else:
      return 3
