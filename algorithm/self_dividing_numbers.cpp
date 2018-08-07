#include "common.h"

USESTD;

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> v;
        int num, n;

        for (int i = left; i <= right; i++) {
            num = i;
            while (num > 0) {
                n = num % 10;
                if (n == 0 || i % n != 0)
                    break;
                num /= 10;
            }

            if (num == 0) 
                v.push_back(i);
        }

        return v;
    }
};