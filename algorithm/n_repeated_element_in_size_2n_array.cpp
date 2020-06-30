#include "common.h"
#include "node.h"

USESTD

class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        map<int, int> m;
        auto size = A.size();

        for (int i = 0; i < size; i++) {
            if (m.find(A[i]) != m.end()) {
                return A[i];
            } else {
                m[A[i]] = i;
            }
        }
    }
};