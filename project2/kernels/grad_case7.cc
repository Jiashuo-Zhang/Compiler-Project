#include "../run2.h"

void grad_case7(float (&dB)[16][32], float (&dA)[32][16]) {
 int id0;
 int id1;
 float temp_dA[32][16];
 for (int id0 = 0; id0 < 0 + 32; id0++) {
   for (int id1 = 0; id1 < 0 + 16; id1++) {
     temp_dA[id0][id1] = 0;
   }
 }
 for (int i = 0; i < 0 + 16; i++) {
   for (int j = 0; j < 0 + 32; j++) {
     if (i >= 0 && i < 16) {
       if (j >= 0 && j < 32) {
         if (j >= 0 && j < 32) {
           if (i >= 0 && i < 16) {
             id0 = j;
             id1 = i;
             temp_dA[id0][id1] = temp_dA[id0][id1] + dB[i][j];
           }
         }
       }
     }
   }
 }
 for (int id0 = 0; id0 < 0 + 32; id0++) {
   for (int id1 = 0; id1 < 0 + 16; id1++) {
     dA[id0][id1] = temp_dA[id0][id1];
   }
 }
}
