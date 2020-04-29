#include "common.h"

USESTD 

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        auto size = A.size();
        vector<bool> result;

        int num = 0;

        for (int i = 0; i < size; i++) {
            num = i == 0 ? A[i] : ((num << 1) | A[i]);
            result.push_back(num % 5 == 0);
            num %= 10;
        }

        return result;
    }
};