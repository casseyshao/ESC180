// Lab 10

/* data structure to represent multi-term, single variable polynomial */
struct singleVarPolynomialTerm {
   float coefficient;
   float exponent;
   struct singleVarPolynomialTerm *next;
}

typedef struct singleVarPolynomialTerm term;
