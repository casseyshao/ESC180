// Lab 10

#include<stdio.h>
#include<stdlib.h>

int g(char **array, int size);

int g(char **array, int size) {
   /* f declares array of char elements char *array */
   if (size <= 0) {
      return -1;
   }

   (*array) = (char *)malloc(sizeof(char)*size);

   return 0;
}
