#include "common.h"

USESTD

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int rows = A.size();
        int cols = A[0].size();

        for (int r = 0; r < rows; r++) {
            int low = 0, high = cols - 1;
            while (low <= high) {
                swap(A[r][low++], A[r][high--]);
            }

            for (int c = 0; c < cols; c++) 
                A[r][c] = A[r][c] == 0 ? 1 : 0;
        }

        return A;     
    }
};
