#include "common.h"

USESTD 

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) return -1;

        set<int> s;
        for (int i = 0; i < nums.size(); i++) {
            if (s.find(nums[i]) == s.end()) {
                s.insert(nums[i]);
            } else {
                return nums[i];
            }
        }

        return -1;
    }
};
