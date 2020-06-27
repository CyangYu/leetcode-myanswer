#include "common.h"

USESTD

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        bool first = false;

        for (int i = 0, size = nums.size() - 1; i < size; i++) {
            if (nums[i] > nums[i + 1]) {
                if (first == false) {
                    first = true;
                } else {
                    return false;
                }
            }
        }

        return true;
    }
};