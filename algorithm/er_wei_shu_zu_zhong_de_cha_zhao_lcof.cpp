#include "common.h"
#include "node.h"

USESTD 

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        if (rows == 0) return false;

        int cols = matrix[0].size();
        if (cols == 0) return false;

        for (int r = 0; r < rows; r++) {
            if (binarySearch(matrix[r], 0, cols, target)) return true;
        }

        return false;        
    }

    bool binarySearch(vector<int> &arr, int left, int right, int target) {
        int middle = 0;

        while (left < right) {
            middle = left + (right - left) / 2;
            if (arr[middle] == target) return true;
            else if (arr[middle] < target) left = middle + 1;
            else right = middle;
        }

        return false;
    }
};