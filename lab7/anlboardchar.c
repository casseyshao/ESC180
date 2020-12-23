// Lab 7

#include <stdio.h>

// character array
int anlboard(char *T, int sizeT) {

   int Xcount = 0;
   int Ocount = 0;
   int Xwin = 0;
   int Owin = 0;

   if (sizeT !=9) {
      return -1;
   }

   for (int i=0;i<sizeT;i++) {
      if (T[i] == 'X') {
         Xcount = Xcount + 1;
      } else if (T[i] == 'O') {
         Ocount = Ocount + 1;
      }
      if ((T[i] != '-') && (T[i] != 'X') && (T[i] != 'O')) {
         return -1;
      }
   }

   if ((Xcount-Ocount > 1) || (Ocount-Xcount > 1)){ 
      return -1;
   }

   if(
   (T[0] == T[1] && T[1] == T[2] && T[2] == 'X') ||
   (T[3] == T[4] && T[4] == T[5] && T[5] == 'X') ||
   (T[6] == T[7] && T[7] == T[8] && T[8] == 'X') ||
   (T[0] == T[3] && T[3] == T[6] && T[6] == 'X') ||
   (T[1] == T[4] && T[4] == T[7] && T[7] == 'X') ||
   (T[2] == T[5] && T[5] == T[8] && T[8] == 'X') ||
   (T[0] == T[4] && T[4] == T[8] && T[8] == 'X') ||
   (T[6] == T[4] && T[4] == T[2] && T[2] == 'X')) {
      Xwin = 1;
   }

   if(
   (T[0] == T[1] && T[1] == T[2] && T[2] == 'O') ||
   (T[3] == T[4] && T[4] == T[5] && T[5] == 'O') ||
   (T[6] == T[7] && T[7] == T[8] && T[8] == 'O') ||
   (T[0] == T[3] && T[3] == T[6] && T[6] == 'O') ||
   (T[1] == T[4] && T[4] == T[7] && T[7] == 'O') ||
   (T[2] == T[5] && T[5] == T[8] && T[8] == 'O') ||
   (T[0] == T[4] && T[4] == T[8] && T[8] == 'O') ||
   (T[6] == T[4] && T[4] == T[2] && T[2] == 'O')) {
      Owin = 1;
   }

   if ((Xwin == 1) && (Owin == 1)){
      return -1;
   } else if ((Xwin == 1) && (Owin == 0)){
      return 1;
   } else if ((Xwin == 0) && (Owin == 1)){
      return 2;
   } else {
      for(int i=0;i<sizeT;i++){ 
         if(T[i]=='-'){
            return 0;
         }
       }
       return 3;
   }
}

// testing
int main(void) {
   // return 0 for game in play
   char TP[9] = {'-','X','-','-','O','-','-','-','-'};
   printf("Should be 0: %d\n",anlboard(TP,9));

   // return 1 for Xwin
   char TX[9] = {'X','X','X','O','O','-','-','-','-'};
   printf("Should be 1: %d\n",anlboard(TX,9));

   // return 2 for Owin
   char TO[9] = {'O','O','O','X','X','-','-','-','-'};
   printf("Should be 2: %d\n",anlboard(TO,9));

   // return 3 for draw
   char TD[9] = {'X','X','O','O','O','X','X','O','X'};
   printf("Should be 3: %d\n",anlboard(TD,9));

   // return -1 for invalid size
   char TIS[10] = {'-','-','-','-','-','-','-','-','-','-'};
   printf("Should be -1: %d\n",anlboard(TIS,10));

   // return -1 for invalid values in board
   char TIV[9] = {'A','-','-','-','-','-','-','-','-'};
   printf("Should be -1: %d\n",anlboard(TIV,9));
}