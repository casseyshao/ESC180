// Lab 10

#include <stdio.h>
#include <stdlib.h>

struct singleVarPolynomialTerm {
   float coefficient;
   float exponent;
   struct singleVarPolynomialTerm *next;
};

typedef struct singleVarPolynomialTerm term;

int displayPoly(term *polynomial);
int integrate(term *polynomial);

int displayPoly(term *polynomial) {
   if (polynomial == NULL) {
      return -1;
   }

   term *curr = polynomial;
   printf("y = ");
   while (curr!=NULL) {
      printf("(%f)x",curr->coefficient);
      /* instructions say assume exponents are non-negative */
      if (curr->exponent > 1) {
         printf("^(%f)",curr->exponent);
      }

      curr = curr->next;
      if (curr == NULL) {
         printf("\n");
      } else {
         printf(" + ");
      }
   }
   
   return 0;
}

int integrate (term *polynomial) {
   if (polynomial == NULL) {
      return -1;
   }

   term *curr = polynomial;
   while (curr != NULL) {
      float newCoeff = (float)curr->coefficient/((curr->exponent)+1);
      float newExp = (curr->exponent)+1;
      curr->coefficient = newCoeff;
      curr->exponent = newExp;
      curr = curr->next;
   }

   return 0;
}

int main(void) {
   term *testPoly = malloc(sizeof(term));
   testPoly->coefficient = 1;
   testPoly->exponent = 1;
   testPoly->next = NULL;
   term *curr = testPoly;
   int i = 2;
   while (i < 4) {
      term *testPoly = malloc(sizeof(term));
      testPoly->coefficient = i;
      testPoly->exponent = i;
      testPoly->next = NULL;
      curr->next = testPoly;
      if (i != 3) {
         curr = testPoly;
      }
      i++;
   }
   displayPoly(testPoly);
   integrate(testPoly);
   displayPoly(testPoly);
   return 0;
}
