#include "common.h"

USESTD

class Solution {
public:
    bool hasAlternatingBits(int n) {
        int temp = n ^ (n >> 1);
        return (temp & (temp + 1)) == 0;
    }
};