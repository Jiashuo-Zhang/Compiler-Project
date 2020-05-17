#include "../run.h"

void kernel_case7(float (&A)[32][16], float (&B)[16][32])  {
 float temp_B[16][32];
 for (int i = 0; i < 0 + 16; i++) {
   for (int j = 0; j < 0 + 32; j++) {
     if (j >= 0 && j < 32) {
       if (i >= 0 && i < 16) {
         temp_B[i][j] = 0;
         if (i >= 0 && i < 16) {
           if (j >= 0 && j < 32) {
             temp_B[i][j] = temp_B[i][j] + A[j][i];
           }
         }
       }
     }
   }
 }
 for (int i = 0; i < 0 + 16; i++) {
   for (int j = 0; j < 0 + 32; j++) {
     if (j >= 0 && j < 32) {
       if (i >= 0 && i < 16) {
         B[i][j] = temp_B[i][j];
       }
     }
   }
 }
}
