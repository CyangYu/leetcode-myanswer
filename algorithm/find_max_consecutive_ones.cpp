#include "common.h"

USESTD;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCount = 0, lastIdx = 0, idx = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                lastIdx = idx; 
                idx = i;
                maxCount = max(maxCount, idx - lastIdx);
            }
        }

        return maxCount;
    }
};