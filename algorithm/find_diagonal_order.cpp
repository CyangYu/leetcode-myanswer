#include "common.h"

USESTD

class Solution {
public:
    enum Direction { Up, Down, None };
    
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        Direction dir = Up;

        vector<int> v;
        int rows = matrix.size();
        int cols = matrix[0].size();
        int r = 0, c = 0;
        
        while (r != rows - 1 || c != cols - 1) {
            if (dir == Up) {
                while (r >= 0 && c < cols) 
                    v.push_back(matrix[r--][c++]);
                
                dir = Down;
                if (r < 0) r = 0;
                if (c == cols) c = cols - 1;
            } else if (dir == Down) {
                while (r < rows && c >= 0) 
                    v.push_back(matrix[r++][c--]);
                
                dir = Up;
                if (c < 0) c = 0;
                if (r == rows) r = rows - 1;
            }   
        }

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