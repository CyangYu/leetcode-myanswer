#incldue "common.h"

USESTD

class Solution {
public:
    int getSum(int a, int b) {
        return bit_add(a, b);
    }
    
    int bit_add(int a, int b) {
        if (b == 0)
            return a;
        int sum = a ^ b;
        int carry = (a & b) << 1;
        return bit_add(sum, carry);
    }
};