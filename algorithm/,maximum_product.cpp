#include "common.h"

USESTD;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        auto size = nums.size();
        sort(nums.begin(), nums.end());
        
        int idx = -1;
        for (int i = 0; i < size; i++)
            if (nums[i] > 0)
                idx = i;
        
        if (idx == -1) {
            return nums[size - 1] * nums[size - 2] * nums[size - 3];
        } else {
            int l = nums[0] * nums[1];
            int h = nums[size - 3] * nums[size - 2];
            
            if (nums[0] < 0) {
                return l < h ? nums[size - 1] * h : nums[size - 1] * l; 
            } else {
                return nums[size - 1] * h;
            }
        }
    }
};