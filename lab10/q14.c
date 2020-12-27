// Lab 10

#include <stdio.h>
#include <stdlib.h>

/* return the fibo 3 sequence element at position n */
/* fibo3 is defined as per: */
/* fibo3(0)=1, fibo3(1)=1, fibo3(2)=1, fibo3(3)=3, fibo3(4)=5, fibo3(5)=9... */
/* via recursion */
int fibo(int n);

int fibo(int n) {
   int sum = 0;
   if (n==0 || n==1 || n==2) {
      return 1;
   } else {
      sum = fibo(n-1) + fibo(n-2) + fibo(n-3);
      return sum;
   }
}

int main(void) {
   printf("fibo3(0)=%d\n",fibo(0));
   printf("fibo3(1)=%d\n",fibo(1));
   printf("fibo3(2)=%d\n",fibo(2));
   printf("fibo3(3)=%d\n",fibo(3));
   printf("fibo3(4)=%d\n",fibo(4));
   printf("fibo3(5)=%d\n",fibo(5));
   printf("fibo3(6)=%d\n",fibo(6));
   return 0;
}
