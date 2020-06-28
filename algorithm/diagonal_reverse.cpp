#include "common.h"

USESTD

class Solution {
public: 
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> result;

        bool down = false;

        int rows = matrix.size(), r = 0;
        if (rows == 0) return result;

        int cols = matrix[0].size(), c = 0;
        if (cols == 0) return result;

        int all = rows * cols;
        while (result.size() < all) {
            if (down == true) {
                while (r < rows && c >= 0) {
                    result.push_back(matrix[r++][c--]);
                }

                r--;
                c++;
                if (c < 0) { c = 0; }
                if (r == rows - 1) c++;
                if (r < rows - 1) r++;
                down = false;
            } else {
                while (r >= 0 && c < cols) {
                    result.push_back(matrix[r--][c++]);
                }
                
                r++;
                c--;
                if (r < 0) { r = 0;}
                if (c == cols - 1) r++;
                if (c < cols - 1) c++;
                down = true;
            }
        }

        return result;
    }
};
