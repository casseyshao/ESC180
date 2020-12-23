// Lab 7

#include <stdio.h>

int fibo(int n);

// allow user to specify the number of fibonacci numbers
int main(void) {
   int val;
      
   printf("Enter an integer: ");
   scanf("%d",&val);

   for (int i=0;i<val;i=i+1){
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