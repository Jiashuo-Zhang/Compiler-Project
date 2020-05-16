#include "../run.h"

void kernel_case1(float (&A)[32][16])  {
 float temp_A[32][16];
 for (int i = 0; i < 0 + 32; i++) {
   for (int j = 0; j < 0 + 16; j++) {
     if (j >= 0 && j < 16) {
       if (i >= 0 && i < 32) {
         temp_A[i][j] = 0;
         temp_A[i][j] = temp_A[i][j] + 2;
       }
     }
   }
 }
 for (int i = 0; i < 0 + 32; i++) {
   for (int j = 0; j < 0 + 16; j++) {
     if (j >= 0 && j < 16) {
       if (i >= 0 && i < 32) {
         A[i][j] = temp_A[i][j];
       }
     }
   }
 }
}
