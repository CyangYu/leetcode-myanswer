#include "common.h"

USESTD 

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int m = nums.size(), n = nums[0].size();
        if (r * c != m * n)
            return nums;
        vector<vector<int>> reshaped(r);
        for (int i = 0; i < r * c; i++) {
            reshaped.resize(c);
            reshaped[i/c][i%c] = nums[i/n][i%n];
        }
        return reshaped;
    }
};