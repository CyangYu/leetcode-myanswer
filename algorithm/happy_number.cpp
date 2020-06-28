#include "common.h"

USESTD 

class Solution {
public:
    bool isHappy(int n) {
        int mod, result;

        while (n != 1 && n != 4) {
            result = 0;
            while (n > 0) {
                mod = n % 10;
                n /= 10;
                result += mod * mod; 
            }
            n = result;
        }

        return (n == 1);
    }
};
