#include "../run.h"

void kernel_case4(float (&B)[16][32], float (&C)[32][32], float (&A)[16][32])  {
 float temp_A[16][32];
 for (int i = 0; i < 0 + 16; i++) {
   for (int j = 0; j < 0 + 32; j++) {
     if (j >= 0 && j < 32) {
       if (i >= 0 && i < 16) {
         temp_A[i][j] = 0;
         if (j >= 0 && j < 32) {
           if (i >= 0 && i < 16) {
             temp_A[i][j] = temp_A[i][j] + A[i][j];
           }
         }
         for (int k = 0; k < 0 + 32; k++) {
           if (j >= 0 && j < 32) {
             if (k >= 0 && k < 32) {
               if (k >= 0 && k < 32) {
                 if (i >= 0 && i < 16) {
                   temp_A[i][j] = temp_A[i][j] + B[i][k] * C[k][j];
                 }
               }
             }
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
         A[i][j] = temp_A[i][j];
       }
     }
   }
 }
}
