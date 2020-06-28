#include "common.h"

USESTD

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {        
        size_t idx = 0;
        int count = 0, maxCount = 0;

        while (idx < nums.size()) {
            if (nums[idx] == 1) {
                for (int j = idx; j < nums.size() && nums[j] == 1; j++)
                    count++;

                idx += count;
                if (count > maxCount) {
                    maxCount = count;
                    count = 0;
                }
            } 

            idx++;
            count = 0;
        }

        return maxCount;
    }
};