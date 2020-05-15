#include "common.h"
#include "node.h"

USESTD 

class Solution {
public:
    int fib(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;

        uint64_t num = 0;
        uint64_t n0 = 0, n1 = 1;

        for (int i = 2; i <= n; i++) {
            num = (n0 + n1) % 1000000007;
            n0 = n1;
            n1 = num;
        }

        return num;
    }
};  