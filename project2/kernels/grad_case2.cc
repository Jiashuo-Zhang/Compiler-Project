#include "../run2.h"

void grad_case2(float (&A)[4][16], float (&dB)[4][16], float (&dA)[4][16]) {
 int id0;
 int id1;
 float temp_dA[4][16];
 for (int id0 = 0; id0 < 0 + 4; id0++) {
   for (int id1 = 0; id1 < 0 + 16; id1++) {
     temp_dA[id0][id1] = 0;
   }
 }
 for (int i = 0; i < 0 + 4; i++) {
   for (int j = 0; j < 0 + 16; j++) {
     if (j >= 0 && j < 16) {
       if (i >= 0 && i < 4) {
         if (j >= 0 && j < 16) {
           if (i >= 0 && i < 4) {
             if (j >= 0 && j < 16) {
               if (i >= 0 && i < 4) {
                 id0 = i;
                 id1 = j;
                 temp_dA[id0][id1] = temp_dA[id0][id1] + dB[i][j] * A[i][j];
               }
             }
           }
         }
         if (j >= 0 && j < 16) {
           if (i >= 0 && i < 4) {
             if (j >= 0 && j < 16) {
               if (i >= 0 && i < 4) {
                 id0 = i;
                 id1 = j;
                 temp_dA[id0][id1] = temp_dA[id0][id1] + A[i][j] * dB[i][j];
               }
             }
           }
         }
       }
     }
   }
 }
 for (int id0 = 0; id0 < 0 + 4; id0++) {
   for (int id1 = 0; id1 < 0 + 16; id1++) {
     dA[id0][id1] = temp_dA[id0][id1];
   }
 }
}
