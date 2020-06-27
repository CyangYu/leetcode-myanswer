#include "common.h"

USESTD 

class Solution {
public:
    int xorOperation(int n, int start) {
        int num = 0;
        for (int i = 1; i < n; i++) {
            num ^= start + i * 2;
        }
        return num;
    }
};