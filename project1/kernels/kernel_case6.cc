#include "../run.h"

void kernel_case6(float (&B)[2][16][7][7], float (&C)[8][16][3][3], float (&A)[2][8][5][5])  {
 float temp_A[2][8][5][5];
 for (int k = 0; k < 0 + 8; k++) {
   for (int n = 0; n < 0 + 2; n++) {
     for (int p = 0; p < 0 + 5; p++) {
       for (int q = 0; q < 0 + 5; q++) {
         if (q >= 0 && q < 5) {
           if (p >= 0 && p < 5) {
             if (k >= 0 && k < 8) {
               if (n >= 0 && n < 2) {
                 temp_A[n][k][p][q] = 0;
                 if (q >= 0 && q < 5) {
                   if (p >= 0 && p < 5) {
                     if (k >= 0 && k < 8) {
                       if (n >= 0 && n < 2) {
                         temp_A[n][k][p][q] = temp_A[n][k][p][q] + A[n][k][p][q];
                       }
                     }
                   }
                 }
                 for (int c = 0; c < 0 + 16; c++) {
                   for (int r = 0; r < 0 + 3; r++) {
                     for (int s = 0; s < 0 + 3; s++) {
                       if (s >= 0 && s < 3) {
                         if (r >= 0 && r < 3) {
                           if (c >= 0 && c < 16) {
                             if (k >= 0 && k < 8) {
                               if (q + s >= 0 && q + s < 7) {
                                 if (p + r >= 0 && p + r < 7) {
                                   if (c >= 0 && c < 16) {
                                     if (n >= 0 && n < 2) {
                                       temp_A[n][k][p][q] = temp_A[n][k][p][q] + B[n][c][p + r][q + s] * C[k][c][r][s];
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
                 }
               }
             }
           }
         }
       }
     }
   }
 }
 for (int k = 0; k < 0 + 8; k++) {
   for (int n = 0; n < 0 + 2; n++) {
     for (int p = 0; p < 0 + 5; p++) {
       for (int q = 0; q < 0 + 5; q++) {
         if (q >= 0 && q < 5) {
           if (p >= 0 && p < 5) {
             if (k >= 0 && k < 8) {
               if (n >= 0 && n < 2) {
                 A[n][k][p][q] = temp_A[n][k][p][q];
               }
             }
           }
         }
       }
     }
   }
 }
}
