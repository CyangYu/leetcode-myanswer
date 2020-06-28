#include "common.h"

USESTD

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int r = 0; r < 9; r++) {
            int n = 0;
            int row[10] = {0};
            int col[10] = {0};
            int grid[10] = {0};

            for (int c = 0; c < 9; c++) {       // per row
                if (board[r][c] != '.') {     
                    n = board[r][c] - '0';
                    if (++col[n] > 1)
                        return false;
                }
            }

            for (int c = 0; c < 9; c++) {
                if (board[c][r] != '.') {       // per col
                    n = board[c][r] - '0';
                    if (++row[n] > 1)
                        return false; 
                }
            }

            for (int g = 0; g < 9; g++) {       // per grid
                int x = (r / 3) * 3 + (g / 3);
                int y = (r % 3) * 3 + (g % 3);
                if (board[x][y] != '.') {
                    n = board[x][y] - '0';
                    if (++grid[n] > 1)
                        return false;
                }
            }
        }
        
        return true;
    }
};