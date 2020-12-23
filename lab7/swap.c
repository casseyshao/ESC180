// Lab 7

// address of (&)
// value at (*)

#include <stdio.h>

// Swap values of the two input arguments
int swap (int *a, int *b){
   int temporary = *a;
   *a = *b; // value at a gets value at b
   *b = temporary; // value at b gets old value at a
   return 1;
}

int main(void) {
   int a = 100;
   int b = 200;

   printf("a: %d\n",a);
   printf("b: %d\n",b);

   swap(&a,&b);

   printf("a: %d\n",a);
   printf("b: %d\n",b);
}