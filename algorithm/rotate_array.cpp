#include "common.h"

USESTD 

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        auto size = nums.size();
        k = (k < size) ? k : k % size;
        
        int step = size - k;
        for (int i = size - k; i < size; i++) {
            for (int j = 0; j < step; j++) {
                int temp = nums[i- j];
                nums[i - j] = nums[i - j - 1];
                nums[i - j - 1] = temp;
            }
        }
    }
};
