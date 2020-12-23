// Lab 7
// TicTacToe

#include <stdio.h>

// integer array
int anlboard(int *T, int sizeT) {

   int Xcount = 0;
   int Ocount = 0;
   int Xwin = 0;
   int Owin = 0;

   if (sizeT !=9) {
      return -1;
   }

   for (int i=0;i<sizeT;i++) {
      if (T[i] == 1){
         Xcount = Xcount + 1;
      } else if (T[i] == 2) {
         Ocount = Ocount + 1;
      }
      if ((T[i] != 0) && (T[i] != 1) && (T[i] != 2)) {
         return -1;
      }
   }

   if ((Xcount-Ocount > 1) || (Ocount-Xcount > 1)) {
      return -1;
   }

   if(
   (T[0] == T[1] && T[1] == T[2] && T[2] == 1) ||
   (T[3] == T[4] && T[4] == T[5] && T[5] == 1) ||
   (T[6] == T[7] && T[7] == T[8] && T[8] == 1) ||
   (T[0] == T[3] && T[3] == T[6] && T[6] == 1) ||
   (T[1] == T[4] && T[4] == T[7] && T[7] == 1) ||
   (T[2] == T[5] && T[5] == T[8] && T[8] == 1) ||
   (T[0] == T[4] && T[4] == T[8] && T[8] == 1) ||
   (T[6] == T[4] && T[4] == T[2] && T[2] == 1)) {
      Xwin = 1;
   }

   if(
   (T[0] == T[1] && T[1] == T[2] && T[2] == 2) ||
   (T[3] == T[4] && T[4] == T[5] && T[5] == 2) ||
   (T[6] == T[7] && T[7] == T[8] && T[8] == 2) ||
   (T[0] == T[3] && T[3] == T[6] && T[6] == 2) ||
   (T[1] == T[4] && T[4] == T[7] && T[7] == 2) ||
   (T[2] == T[5] && T[5] == T[8] && T[8] == 2) ||
   (T[0] == T[4] && T[4] == T[8] && T[8] == 2) ||
   (T[6] == T[4] && T[4] == T[2] && T[2] == 2)) {
      Owin = 1;
   }

   if (Xwin == 1 && Owin == 1) {
      return -1;
   } else if (Xwin == 1 && Owin == 0) {
      return 1;
   } else if (Xwin == 0 && Owin == 1) {
      return 2;
   } else {
      for(int i=0;i<sizeT;i++) { 
         if(T[i]==0) {
            return 0;
         }
       }
       return 3;
   }
}

// testing
int main(void) {
   // return 0 for game in play
   int TP[9] = {0,1,0,0,2,0,0,0,0};
   printf("Should be 0: %d\n",anlboard(TP,9));

   // return 1 for Xwin
   int TX[9] = {1,1,1,2,2,0,0,0,0};
   printf("Should be 1: %d\n",anlboard(TX,9));

   // return 2 for Owin
   int TO[9] = {2,2,2,1,1,0,0,0,0};
   printf("Should be 2: %d\n",anlboard(TO,9));

   // return 3 for draw
   int TD[9] = {1,1,2,2,2,1,1,2,1};
   printf("Should be 3: %d\n",anlboard(TD,9));

   // return -1 for invalid size
   int TIS[10] = {0,0,0,0,0,0,0,0,0,0};
   printf("Should be -1: %d\n",anlboard(TIS,10));

   // return -1 for invalid values in board
   int TIV[9] = {3,0,0,0,0,0,0,0,0};
   printf("Should be -1: %d\n",anlboard(TIV,9));
}