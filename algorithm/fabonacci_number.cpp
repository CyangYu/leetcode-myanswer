#include "common.h"

USESTD 

class Solution {
public:
    int fib(int N) {
        int a = 0, b = 1;
        int fibnum = 0;

        if (N == 0) return 0;
        else if (N == 1) return 1;
        else {
            for (int i = 2; i <= N; i++) {
                fibnum = a + b;
                a = b;
                b = fibnum;
            }
        }

        return fibnum;
    }
};
