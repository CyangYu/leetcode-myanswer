#include "common.h"

USESTD 

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        auto size = A.size();
        vector<int> result(A);

        int pos_idx = 0;

        for (int i = 0; i < size; i++) {
            if (A[i] >= 0) {
                pos_idx = i;
                break;
            }
        }

        for (int j = pos_idx; j < size; j++)
            
    }
};