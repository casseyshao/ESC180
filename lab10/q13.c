// Lab 10

#include <stdio.h>
#include <stdlib.h>

typedef struct {
   int valid;
   int value;
   int frequency; /* number of times value was found in n */
} arrayStruct;

int histogram(int *n,arrayStruct *m,int s);
int getmode(arrayStruct *m,int *mode);

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

/* m is defined as above */
/* mode is most frequent value of dataset in m (output) */
/* return 0 for success or -1 for failure */
int getmode(arrayStruct *m,int *mode) {
   if (m == NULL || mode == NULL) {
      return -1;
   }

   int mostFrequent = m[0].frequency;
   int mMode = m[0].value;

   int i = 0;
   while (m[i].valid == 1) {
      if (m[i].frequency > mostFrequent) {
         mostFrequent = m[i].frequency;
         mMode = m[i].value;
      }
      i++;
   }

   *mode = mMode;
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

   int mode = -1;
   r = getmode(arrS,&mode);
   printf("Mode is: %d\n",mode);

   return 0;
}
