#include "common.h"

USESTD 

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int major = 0, count = 0;

        for (int i = 0, size = nums.size(); i < size; i++) {
            if (count == 0) major = nums[i];
            if (nums[i] != major) count--;
            else count++;
        }

        return count <= 0 ? -1 : major;
    }
};