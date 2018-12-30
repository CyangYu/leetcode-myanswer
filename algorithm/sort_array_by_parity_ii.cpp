#include "node.h"
#include "common.h"

USESTD

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        vector<int> B(A.size());
        size_t odd_idx = 0, even_idx = 1;

        for (int i = 0; i < A.size(); i++) {
            if (A[i] % 2 != 0) {
                B[odd_idx] = A[i];
                odd_idx += 2;        
            } else {
                B[even_idx] = A[i];
                even_idx += 2;
            }
        }

        return B;
    }
};