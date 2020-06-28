#include "common.h"

USESTD

class Solution {
public:
    int majorityElement(vector<int> &nums) {
        int count = 0;
        int majority = nums[0];
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == majority) {
                count++;
            } else {
                count--;
                if (count == 0) {
                    majority = nums[i + 1];
                }
            }
        }
        
        return majority;        
    }
};