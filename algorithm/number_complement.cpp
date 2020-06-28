#include "common.h"

USESTD

class Solution {
public:
    int findComplement(int num) {
        int comp = 0;
        int bitwise = 0;

        while (num > 0) {
            int bit = ((num & 0x1) == 0) ? 1 : 0;
            comp |= (bit << bitwise);
            bitwise++;
            num >>= 1;
        }
        
        return comp;
    }
};