#include "../run2.h"

void grad_case9(float (&dB)[4][6], float (&dA)[4]) {
 int id0;
 float temp_dA[4];
 for (int id0 = 0; id0 < 0 + 4; id0++) {
   temp_dA[id0] = 0;
 }
 for (int i = 0; i < 0 + 4; i++) {
   if (i >= 0 && i < 4) {
     for (int j = 0; j < 0 + 6; j++) {
       if (j >= 0 && j < 6) {
         if (i >= 0 && i < 4) {
           id0 = i;
           temp_dA[id0] = temp_dA[id0] + dB[i][j];
         }
       }
     }
   }
 }
 for (int id0 = 0; id0 < 0 + 4; id0++) {
   dA[id0] = temp_dA[id0];
 }
}
