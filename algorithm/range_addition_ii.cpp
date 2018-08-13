#include "common.h"

USESTD

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int minrows = m;
        int mincols = n;

        for (int i = 0; i < ops.size(); i++) {
            if (ops[i][0] < minrows)
                minrows = ops[i][0];
            if (ops[i][1] < mincols)
                mincols = ops[i][1];
        }

        return minrows * mincols;
    }
};