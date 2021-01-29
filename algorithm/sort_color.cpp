#include "common.h"

USESTD 

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int colors[3] = {0};
        for (int i = 0, size = nums.size(); i < size; i++) {
            colors[nums[i]]++;
        }

        int idx = 0;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < colors[i]; j++) {
                nums[idx++] = i;
            }
        }
    }
};