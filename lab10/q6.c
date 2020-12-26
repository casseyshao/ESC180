// Lab 10

/* data structure to handle four-variable multi-term polynomials */
struct fourVarPolynomialTerm {
   float coefficient;
   float exponent;
   char varLetter; /* 4 variables */
   struct fourVarPolynomialTerm *next; /* polynomial is multi-term */
}