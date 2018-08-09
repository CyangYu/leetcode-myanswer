#include "common.h"

USESTD

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        auto size = nums.size();
        
        if (size == 0)
            return false;
        
        sort(nums.begin(), nums.end());
        for (int i = 0; i < size - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                return true;
            }
        }
        return false;
    }
};