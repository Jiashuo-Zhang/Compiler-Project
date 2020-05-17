#include "../run.h"

void kernel_example(float (&B)[32][16], float (&C)[32][16], float (&A)[32][16])  {
 float temp_A[32][16];
 for (int i = 0; i < 0 + 32; i++) {
   for (int j = 0; j < 0 + 16; j++) {
     if (j >= 0 && j < 16) {
       if (i >= 0 && i < 32) {
         temp_A[i][j] = 0;
         if (j >= 0 && j < 16) {
           if (i >= 0 && i < 32) {
             if (j >= 0 && j < 16) {
               if (i >= 0 && i < 32) {
                 temp_A[i][j] = temp_A[i][j] + C[i][j] * B[i][j];
               }
             }
           }
         }
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
