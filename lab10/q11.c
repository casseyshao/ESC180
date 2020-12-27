// Lab 10

#include <stdio.h>
#include <stdlib.h>

int isPrime(int n);
int isPrimeProduct(int n);

/* Use % (modulo) to get remainder->if remainder does not equal 0, we have a prime number */

/* a Prime is a natural number, >1, and not a product smaller natural numbers */
/* return 0 if n is a Prime and -1 otherwise */
int isPrime(int n) {
   for (int i=n-1;i>1;i--) {
      if (n%i == 0) {
         return -1;
      }
   }
   return 0;
}

/* return 0 if n is a product of two prime numbers and -1 otherwise */
/* if needed, use isPrime as a helper */
int isPrimeProduct(int n) {
   int i = 0;
   for (i=n-1;i>1;i--) {
      if ((n%i == 0) && (isPrime(i) == 0) && (isPrime((int)n/i) == 0)){
         return 0;
      }
   }
   return -1;
}

int main(void) {
   int r = isPrime(3);
   printf("Should be 0 (3 is prime): %d\n", r);
   r = isPrime(4);
   printf("Should be -1 (4 is not prime): %d\n", r);
   r = isPrimeProduct(21);
   printf("Should be 0 (21 is prime product): %d\n", r);
   r = isPrimeProduct(8);
   printf("Should be -1 (8 is not prime product): %d\n", r);
   return 0;
}
