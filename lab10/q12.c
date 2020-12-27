// Lab 10

#include <stdio.h>
#include <stdlib.h>

typedef struct {
   int valid;
   int value;
   int frequency; /* number of times value was found in n */
} arrayStruct;

/* n and m are caller-allocated arrays of equal size s */
/* n contains input integer data for this problem */
/* array m is an array of structs */
/* report frequencies in order that the values appear in n */
int histogram(int *n,arrayStruct *m,int s);

int histogram(int *n,arrayStruct *m,int s) {
   if (n == NULL || m == NULL) {
      return -1;
   }

   for (int i=0;i<s;i++) {
      for (int j=0;j<s;j++) {
         /* valid component for each element of m is set to 0 by caller initially */
         if ((m[j].valid == 1) && (m[j].value == n[i])) {
            m[j].frequency+=1;
            break;
         } else if (m[j].valid == 0){
            m[j].valid = 1;
            m[j].value = n[i];
            m[j].frequency = 1;
            break;
         }
      }
   }

   return 0;
}

int main(void) {
   int size = 15;
   int arr[15] = {1,2,3,2,2,2,2,1,5,3,4,3,4,2,2};
   arrayStruct arrS[15];
   /* valid component for each element of m is set to 0 by caller initially */
   for (int i=0;i<size;i++) {
      arrS[i].valid = 0;
      arrS[i].value = 0;
      arrS[i].frequency = 0;
   }

   int r = histogram(arr,arrS,size);

   for (int i=0;i<size;i++) {
      if (arrS[i].valid == 1) {
         printf("i: %d     value: %d     frequency: %d\n",i,arrS[i].value,arrS[i].frequency);
      }
   }

   return 0;
}
