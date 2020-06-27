#include "common.h"

USESTD 

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int left = 0, right = 0;
        int size = nums.size();
        
        for (int i = 1; i < size; i++) {
            right += nums[i];
        }
        
        for (int i = 0; i < size; i++) {
            if (left == right) {
                return i;
            }

            left += nums[i];
            right -= nums[i + 1];
        }

        return -1; 
    }
};