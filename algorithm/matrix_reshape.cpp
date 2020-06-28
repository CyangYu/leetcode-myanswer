#include "common.h"

USESTD 

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int rows = nums.size();
        int cols = nums[0].size();
        
        if (r * c != rows * cols) 
            return nums;

        vector<vector<int>> matrix;
        
        for (int i = 0; i < r; i++) {
            vector<int> row;
            for (int j = 0; j < c; j++) {
                int idx = i * c + j;
                row.push_back(nums[idx / cols][idx % cols]);
            }
            matrix.push_back(row);
        }

        return matrix;
    }
};
