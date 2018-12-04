#include "common.h"

USESTD 

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        auto size = A.size();
        vector<int> result = vector<int>(size);

        auto begin = 0;
        auto end = size - 1;

        for (int i = 0; i < size; i++) {
            if (A[i] % 2 == 0) {
                result[begin++] = A[i]; 
            } else {
                result[end--] = A[i];
            }
        }
    }
};