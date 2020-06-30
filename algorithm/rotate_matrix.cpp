#include "common.h"

USESTD

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int temp = 0;
        auto rowlen = matrix.size();
        auto collen = matrix[0].size();
        
        for (int r = 1; r < rowlen; r++) {
            for (int c = 0; c < r; c++) {
                temp = matrix[r][c];
                matrix[r][c] = matrix[c][r];
                matrix[c][r] = temp;
            }
        }

        for (int r = 0; r < rowlen; r++) {
            for (int i = 0; i < collen / 2; i++) {
                temp = matrix[r][i];
                matrix[r][i] = matrix[r][collen - 1 - i];
                matrix[r][collen - 1 - i] = temp; 
            }
        }
    }
};