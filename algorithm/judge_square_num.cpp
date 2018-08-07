#include "common.h"

class Solution {
public:
    bool judgeSquareSum(int c) {
        int sqr_t = (int)sqrt(c); 
        for (int a = sqr_t; a >= 0; a--) {
            int sa = a * a;
            if (sa == c)
                return true;
            int d = c - sa;
            int t = (int)sqrt(d);
            if (t * t == d)
                return true;
        }

        return false;
    }
};