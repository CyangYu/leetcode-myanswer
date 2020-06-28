#include "common.h"

USESTD

class Solution {
public:
    int arrangeCoins(int n) {
        long long k = 2 * (long long)n;
        int nline = (int)sqrt(k);
        
        k = nline * nline + nline;
        if (k > 2 * n)
            return nline - 1;
        return nline;
    }
};
