#include "common.h"

USESTD

class Solution {
public:
    inline int average(vector<vector<int>> &M, size_t row, size_t col, int r, int c)
    {
        int sum = 0, count = 0;
        int _r = 0, _c = 0;
        
        for (int i = 0; i < 3; i++) {
            _r = r - 1 + i;
            if (_r < 0 || _r >= row)
                continue;

            for (int j = 0; j < 3; j++) {
                _c = c - 1 + j;
                if  (_c < 0 || _c >= col)
                    continue;
                count++;
                sum += M[_r][_c];
            }
        }
        
        return (int)(sum / count);
    }

    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        auto row = M.size();
        auto col = M[0].size();

        vector<vector<int>> result;

        for (int i = 0; i < row; i++) {
            vector<int> _row;
            for (int j = 0; j < col; j++) {
                _row.push_back(average(M, row, col, i, j));
            }
        }

        return result;
    }
};