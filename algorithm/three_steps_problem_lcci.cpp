#include "common.h"
#include "node.h"

class Solution {
public:
    int waysToStep(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        if (n == 2) return 2;
        if (n == 3) return 4;

        int steps[n + 1];
        steps[1] = 1;
        steps[2] = 2;
        steps[3] = 4;

        for (int i = 4; i <= n; i++) {
            steps[i] = steps[i - 1] + 1 +
                       steps[i - 2] + 2 +
                       steps[i - 3] + 4;
        }

        return steps[n];
    }
};