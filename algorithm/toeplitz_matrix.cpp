#include "common.h"

USESTD

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        auto rows = matrix.size();
        auto cols = matrix[0].size();

        for (int r = 0; r < rows; r++) {
            size_t i = r, j = 0;
            while (i < rows && j < cols) {
                if (matrix[i++][j++] != matrix[r][0])
                    return false;
            }
        }

        for (int c = 1; c < cols; c++) {
            size_t i = 0, j = c;
            while (i < rows && j < cols) {
                if (matrix[i++][j++] != matrix[0][c])
                    return false;
            }
        }

        return true;
    }
};