#include "common.h"

USESTD 

class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        auto size = A.size();
        if (size < 3) {
            return false;
        }
        
        int max = INT_MIN;
        int max_id = 0;

        for (int i = 0; i < size; i++) {
            if (A[i] > max) {
                max = A[i];
                max_id = i;
            }
        }

        for (int i = 0; i < max_id; i++) {
            if (A[i] >= A[i + 1]) {
                return false;
            }
        }

        for (int j = max_id; j < size - 1; j++) {
            if (A[j] <= A[j + 1]) {
                return false;
            }
        }

        return true;
    }
};
