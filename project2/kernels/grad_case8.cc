#include "../run2.h"

void grad_case8(float (&dB)[32], float (&dA)[2][16]) {
 int id0;
 int id1;
 float temp_dA[2][16];
 for (int id0 = 0; id0 < 0 + 2; id0++) {
   for (int id1 = 0; id1 < 0 + 16; id1++) {
     temp_dA[id0][id1] = 0;
   }
 }
 for (int i = 0; i < 0 + 32; i++) {
   if (i % 16 >= 0 && i % 16 < 16) {
     if (i / 16 >= 0 && i / 16 < 2) {
       if (i >= 0 && i < 32) {
         id0 = i / 16;
         id1 = i % 16;
         temp_dA[id0][id1] = temp_dA[id0][id1] + dB[i];
       }
     }
   }
 }
 for (int id0 = 0; id0 < 0 + 2; id0++) {
   for (int id1 = 0; id1 < 0 + 16; id1++) {
     dA[id0][id1] = temp_dA[id0][id1];
   }
 }
}
