#include "../run2.h"

void grad_case6(float (&C)[8][16][3][3], float (&dA)[2][8][5][5], float (&dB)[2][16][7][7]) {
 int id0;
 int id1;
 int id2;
 int id3;
 float temp_dB[2][16][7][7];
 for (int id0 = 0; id0 < 0 + 2; id0++) {
   for (int id1 = 0; id1 < 0 + 16; id1++) {
     for (int id2 = 0; id2 < 0 + 7; id2++) {
       for (int id3 = 0; id3 < 0 + 7; id3++) {
         temp_dB[id0][id1][id2][id3] = 0;
       }
     }
   }
 }
 for (int c = 0; c < 0 + 16; c++) {
   for (int n = 0; n < 0 + 2; n++) {
     for (int p = 0; p < 0 + 5; p++) {
       for (int q = 0; q < 0 + 5; q++) {
         for (int r = 0; r < 0 + 3; r++) {
           for (int s = 0; s < 0 + 3; s++) {
             if (q + s >= 0 && q + s < 7) {
               if (p + r >= 0 && p + r < 7) {
                 if (c >= 0 && c < 16) {
                   if (n >= 0 && n < 2) {
                     for (int k = 0; k < 0 + 8; k++) {
                       if (s >= 0 && s < 3) {
                         if (r >= 0 && r < 3) {
                           if (c >= 0 && c < 16) {
                             if (k >= 0 && k < 8) {
                               if (q >= 0 && q < 5) {
                                 if (p >= 0 && p < 5) {
                                   if (k >= 0 && k < 8) {
                                     if (n >= 0 && n < 2) {
                                       id0 = n;
                                       id1 = c;
                                       id2 = p + r;
                                       id3 = q + s;
                                       temp_dB[id0][id1][id2][id3] = temp_dB[id0][id1][id2][id3] + dA[n][k][p][q] * C[k][c][r][s];
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
 for (int id0 = 0; id0 < 0 + 2; id0++) {
   for (int id1 = 0; id1 < 0 + 16; id1++) {
     for (int id2 = 0; id2 < 0 + 7; id2++) {
       for (int id3 = 0; id3 < 0 + 7; id3++) {
         dB[id0][id1][id2][id3] = temp_dB[id0][id1][id2][id3];
       }
     }
   }
 }
}
