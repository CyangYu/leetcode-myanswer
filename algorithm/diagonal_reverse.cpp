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

int main(int argc, char *argv[])
{
    vector<vector<int>> matrix;
    vector<int> row0 = { 1, 2, 3 };
    vector<int> row1 = { 4, 5, 6 };
    vector<int> row2 = { 7, 8, 9 };

    matrix.push_back(row0);
    matrix.push_back(row1);
    //matrix.push_back(row2);

    Solution solution;
    vector<int> result = solution.findDiagonalOrder(matrix);
    for (auto e : result)
        printf("%d ", e);
    putchar('\n');
    return 0;
}