#include "common.h"

USESTD 

class Solution {
public:
    int convertInteger(int A, int B) {
        int C = A ^ B;
        int count = 0;

        for (int i = 0; i < 32; i++) {
            if ((B & 0x01) != (C & 0x01)) {
                count++;
            }

            B >>= 1;
            C >>= 1;
        }

        return count;
    }
};