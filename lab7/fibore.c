// Lab 7

#include <stdio.h>

int fibo(int n);

int main(void) {
   int i;
   for (i=0;i<20;i=i+1){
      int f = fibo(i);
      printf("fibo(%d)=%d\n",i,f);
   }
   return 0;
}

// generate fibonacci numbers recursively
int fibo(int n) {
   if ((n==0) || (n==1)) {
      return 1;
   } else {
      return fibo(n-1)+fibo(n-2);
   }
}