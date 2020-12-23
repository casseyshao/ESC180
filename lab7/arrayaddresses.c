// Lab 7

#include<stdio.h>

int main(void) {
   int a[10];
   int i;
   printf("the size of an integer in my version of C is %lu\n", sizeof(int));
   printf("a is %p\n",a);
   for (i=0;i<10;i=i+1){
      printf(" the ADDRESS OF a[%d] is %p\n",i, &(a[i]));
   }
   return 0;
}