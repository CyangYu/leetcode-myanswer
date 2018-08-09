#include "common.h"

USESTD

class Solution {
public: 
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size(), r = 0;
        int cols = matrix[0].size(), c = 0;
        
        vector<int> v;

       

        return v;
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
    matrix.push_back(row2);

    Solution solution;
    vector<int> result = solution.findDiagonalOrder(matrix);
    for (auto e : result)
        printf("%d ", e);
    putchar('\n');
    return 0;
}