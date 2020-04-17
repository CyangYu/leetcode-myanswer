#include "common.h"

USESTD 

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        auto n = nums.size();
        long sum = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }

        return (1 + n) * n / 2 - sum;
    }
};