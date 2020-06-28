#include "common.h"

USESTD 

class Solution {
public:
    bool isUgly(int num) {
        int prime = 2;

        if (num < 1) return false;            
        while (num > 1) {
            if (num % prime == 0) num /= prime;
            else prime++;
        }

        return (prime < 7);
    }
};