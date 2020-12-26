// Lab 10

/* How many bytes are needed to store an array of 100 integers?*/

/* 100*4 = 400 bytes are required */

#include <stdio.h>

int main(void) {
    int iArray[100];
    for (int i=0;i<100;i++) {
        iArray[i] = i;
    }

    printf("Number of bytes needed to store array of 100 integers is: %lu\n",sizeof(iArray));
    return 0;
}
