#include "../run.h"

void kernel_case10(float (&B)[10][10], float (&A)[8][8]) {
 float temp_A[8][8];
 for (int i = 0; i < 0 + 8; i++) {
   for (int j = 0; j < 0 + 8; j++) {
     if (j >= 0 && j < 8) {
       if (i >= 0 && i < 8) {
         temp_A[i][j] = 0;
         if (j >= 0 && j < 10) {
           if (i + 2 >= 0 && i + 2 < 10) {
             if (j >= 0 && j < 10) {
               if (i + 1 >= 0 && i + 1 < 10) {
                 if (j >= 0 && j < 10) {
                   if (i >= 0 && i < 10) {
                     temp_A[i][j] = temp_A[i][j] + (B[i][j] + B[i + 1][j] + B[i + 2][j]) / (3);
                   }
                 }
               }
             }
           }
         }
       }
     }
   }
 }
 for (int i = 0; i < 0 + 8; i++) {
   for (int j = 0; j < 0 + 8; j++) {
     if (j >= 0 && j < 8) {
       if (i >= 0 && i < 8) {
         A[i][j] = temp_A[i][j];
       }
     }
   }
 }
}
