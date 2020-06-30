#include "common.h"

USESTD

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> v;

        if (matrix.size() == 0)
            return v;

        int rbegin = 0, cbegin = 0;        
        int rlen = matrix.size();
        int clen = matrix[0].size();
        int direction = -1;

        while (clen != 0 && rlen != 0) {
            switch (direction) {
                case -1:    // right
                    for (int i = cbegin; i < clen; i++)
                        v.push_back(matrix[rbegin][i]);
                    clen -= 1;
                    cbegin += clen; rbegin += 1;
                    direction = 1;
                    break;
                
                case -2:    // left
                    for (int i = cbegin; i >= cbegin - clen; i--) 
                        v.push_back(matrix[rbegin][i]);
                    rlen -= 1;
                    cbegin -= clen; rbegin -= 1;
                    direction = 2;
                    break;
                
                case 1:     // down
                    for (int i = rbegin; i < rlen; i++)
                        v.push_back(matrix[i][cbegin]);
                    clen -= 1; rlen -= 1;
                    cbegin -= 1; rbegin += rlen - 1;
                    direction = -2;
                    break;
                
                case 2:     // up
                    for (int i = rbegin; i >= rbegin - rlen; i--) 
                        v.push_back(matrix[i][cbegin]);
                    rlen -= 1;
                    cbegin += 1; rbegin -= rlen;
                    direction = -1;
                    break;
                
                default:
                    break;
            }
        }

        return v;
    }
};