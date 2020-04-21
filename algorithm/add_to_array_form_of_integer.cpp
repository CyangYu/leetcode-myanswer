#include "common.h"

USESTD 

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        int size = A.size();
        vector<int> v;

        bool carry = false;
        int idx = 0;

        for (int idx = size - 1; idx >= 0 && K > 0; idx--) {
            int n = (K % 10) + A[idx];
            n += carry ? 1 : 0;

            carry = n > 10;
            v.push_back(n % 10);

            K /= 10;
        }

        if (idx > 0) {
            while (idx >= 0) {
                if (carry) {
                    v.push_back(A[i] + 1);
                    carry = false;
                } else {
                    v.push_back(A[i]);
                }
            }
        }

        if (K > 0) {
            while (K > 0) {
                if (carry) {
                    v.push_back(K % 10 + 1);
                    carry = false;
                } else {
                    v.push_back(K % 10);
                }

                K /= 10;
            }
        }

        return v;
    }
};