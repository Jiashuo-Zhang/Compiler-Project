#include "../run2.h"

void grad_case4(float (&B)[16][32], float (&C)[32][32], float (&dA)[16][32], float (&dB)[16][32], float (&dC)[32][32]) {
 int id0;
 int id1;
 float temp_dB[16][32];
 float temp_dC[32][32];
 for (int id0 = 0; id0 < 0 + 16; id0++) {
   for (int id1 = 0; id1 < 0 + 32; id1++) {
     temp_dB[id0][id1] = 0;
   }
 }
 for (int i = 0; i < 0 + 16; i++) {
   for (int k = 0; k < 0 + 32; k++) {
     if (k >= 0 && k < 32) {
       if (i >= 0 && i < 16) {
         for (int j = 0; j < 0 + 32; j++) {
           if (j >= 0 && j < 32) {
             if (k >= 0 && k < 32) {
               if (j >= 0 && j < 32) {
                 if (i >= 0 && i < 16) {
                   id0 = i;
                   id1 = k;
                   temp_dB[id0][id1] = temp_dB[id0][id1] + dA[i][j] * C[k][j];
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
     dB[id0][id1] = temp_dB[id0][id1];
   }
 }
 for (int id0 = 0; id0 < 0 + 32; id0++) {
   for (int id1 = 0; id1 < 0 + 32; id1++) {
     temp_dC[id0][id1] = 0;
   }
 }
 for (int j = 0; j < 0 + 32; j++) {
   for (int k = 0; k < 0 + 32; k++) {
     if (j >= 0 && j < 32) {
       if (k >= 0 && k < 32) {
         for (int i = 0; i < 0 + 16; i++) {
           if (j >= 0 && j < 32) {
             if (i >= 0 && i < 16) {
               if (k >= 0 && k < 32) {
                 if (i >= 0 && i < 16) {
                   id0 = k;
                   id1 = j;
                   temp_dC[id0][id1] = temp_dC[id0][id1] + B[i][k] * dA[i][j];
                 }
               }
             }
           }
         }
       }
     }
   }
 }
 for (int id0 = 0; id0 < 0 + 32; id0++) {
   for (int id1 = 0; id1 < 0 + 32; id1++) {
     dC[id0][id1] = temp_dC[id0][id1];
   }
 }
}
