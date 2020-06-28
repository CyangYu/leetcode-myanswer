#include "common.h"

USESTD 

class Solution {
public:
    long long reverse(int x) {
        int n = 0;
        long long r = 0;
        int num = std::abs(x);

        while (num > 0) {
            n = num % 10;
            num /= 10;
            r = r * 10 + n;
        }
        if (sizeof(r) > sizeof(int))
            return 0;
        else
            return (x < 0) ? -r : r;
    }
};
