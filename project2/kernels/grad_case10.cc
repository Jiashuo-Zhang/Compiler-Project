#include "../run2.h"

void grad_case10(float (&dA)[8][8], float (&dB)[10][8]) {
 int id0;
 int id1;
 float temp_dB[10][8];
 for (int id0 = 0; id0 < 0 + 10; id0++) {
   for (int id1 = 0; id1 < 0 + 8; id1++) {
     temp_dB[id0][id1] = 0;
   }
 }
 for (int i = 0; i < 0 + 8; i++) {
   for (int j = 0; j < 0 + 8; j++) {
     if (j >= 0 && j < 8) {
       if (i + 2 >= 0 && i + 2 < 10) {
         if (j >= 0 && j < 8) {
           if (i >= 0 && i < 8) {
             if (j >= 0 && j < 8) {
               if (i >= 0 && i < 8) {
                 if (j >= 0 && j < 8) {
                   if (i >= 0 && i < 8) {
                     id0 = i + 2;
                     id1 = j;
                     temp_dB[id0][id1] = temp_dB[id0][id1] + dA[i][j] + dA[i][j] + dA[i][j] / (3);
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
 for (int id0 = 0; id0 < 0 + 10; id0++) {
   for (int id1 = 0; id1 < 0 + 8; id1++) {
     dB[id0][id1] = temp_dB[id0][id1];
   }
 }
}
