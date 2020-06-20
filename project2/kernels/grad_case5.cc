#include "../run2.h"

void grad_case5(float (&C)[32][32], float (&D)[4][32], float (&dA)[16][32], float (&dB)[16][32][4]) {
 int id0;
 int id1;
 int id2;
 float temp_dB[16][32][4];
 for (int id0 = 0; id0 < 0 + 16; id0++) {
   for (int id1 = 0; id1 < 0 + 32; id1++) {
     for (int id2 = 0; id2 < 0 + 4; id2++) {
       temp_dB[id0][id1][id2] = 0;
     }
   }
 }
 for (int i = 0; i < 0 + 16; i++) {
   for (int k = 0; k < 0 + 32; k++) {
     for (int l = 0; l < 0 + 4; l++) {
       if (l >= 0 && l < 4) {
         if (k >= 0 && k < 32) {
           if (i >= 0 && i < 16) {
             for (int j = 0; j < 0 + 32; j++) {
               if (j >= 0 && j < 32) {
                 if (l >= 0 && l < 4) {
                   if (j >= 0 && j < 32) {
                     if (k >= 0 && k < 32) {
                       if (j >= 0 && j < 32) {
                         if (i >= 0 && i < 16) {
                           id0 = i;
                           id1 = k;
                           id2 = l;
                           temp_dB[id0][id1][id2] = temp_dB[id0][id1][id2] + dA[i][j] * C[k][j] * D[l][j];
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
 for (int id0 = 0; id0 < 0 + 16; id0++) {
   for (int id1 = 0; id1 < 0 + 32; id1++) {
     for (int id2 = 0; id2 < 0 + 4; id2++) {
       dB[id0][id1][id2] = temp_dB[id0][id1][id2];
     }
   }
 }
}
