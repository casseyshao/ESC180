// Lab 10

#include <stdio.h>

struct blah { 
   int id;
   int val[4];
   char label[4];
   int *data;
};

/*sizeof(struct blah) = 4 + (4*4) + (1*4) + 8 = 32 bytes*/

int main(void) {
   printf("Size of struct blah is: %lu bytes\n", sizeof(struct blah));
   return 0;
}
