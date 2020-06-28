#include "common.h"
#include "node.h"

USESTD

class Solution {
public:
    inline int nbits(char ch) {
        if (ch == 0)
            return 0;
        else if (ch == 1 || ch == 2 || ch == 4 || ch == 8)
            return 1;
        else if (ch == 3 || ch == 5 || ch == 6 || ch == 9 || ch == 10 || ch == 12)
            return 2;
        else if (ch == 7 || ch == 11 || ch == 13 || ch == 14)
            return 3;
        else if (ch == 15)
            return 4;
        else
            return (int)ch;
    }

    int countPrimeSetBits(int L, int R) {
        int bitCount = 0;
        int primeCount = 0;
        
        for (int i = L; i <= R; i++) {
            int _i = i;
            for (int j = 0; j < 5; j++) {
                if (_i == 0)
                    break;
                bitCount += nbits(_i & 0x0F);
                _i >>= 4;
                
            }

            if (bitCount == 2 || bitCount == 3 || bitCount == 5 || bitCount == 7 ||
                bitCount == 11 || bitCount == 13 || bitCount == 17 || bitCount == 19) {
                    primeCount++;
            }
            
            bitCount = 0;
        }

        return primeCount;
    }
};