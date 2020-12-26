// Lab 8
// Bubble Sort

int swap (int *a, int *b) {
   int temp = *a;
   *a = *b;
   *b = temp;
   return 1;
}

// will modify the input array
// return 0 for success and -1 for failure
int bubbleSort(int *array, int size) {
   int n = size, swapped = -1, status = -1;

   while (1) {
      swapped = -1;
      status = -1;
      for (int i=1;i<n;i++) {
         if (array[i-1] > array[i]) {
            swap(&array[i-1],&array[i]);
            swapped = 0;
         }
      }

      if (swapped == -1) {
         status = 0;
         break;
      }
   }

   return status;
}