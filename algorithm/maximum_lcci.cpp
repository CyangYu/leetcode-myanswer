#include "common.h"

USESTD

class Solution {
public:
    int maximum(int a, int b) {
        uint64_t c = (uint64_t)a - (uint64_t)b;
        int arr[] = {a, b};

        c >>= 63;
        return arr[c & 0x1];
    }
};