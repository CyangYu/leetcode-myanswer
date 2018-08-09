#include "common.h"

USESTD

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        auto rows = A.size();
        auto cols = A[0].size();

        vector<vector<int>> matrix;
        for (int r = 0; r < cols; r++) {
            vector<int> row;
            for (int c = 0; c < rows; c++) {
                row.push_back(A[c][r]);
            }
            matrix.push_back(row);
        }

        return matrix;      
    }
};