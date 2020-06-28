#include "common.h"

USESTD 

class Solution {
public:
    int mySqrt(int x) {
        long g = x;
        
        while(g * g > x) {
            g = (g + x / g) >> 1;
        }
        return g;
    }
};