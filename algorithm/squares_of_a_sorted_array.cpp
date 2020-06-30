#include "common.h"

USESTD 

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        auto size = A.size();
        vector<int> v(size);

        int index = size - 1;
        int left = 0, right = size - 1;

        while (left < right && A[left] < 0 && A[right] >= 0) {
            int left_sqr = A[left] * A[left];
            int right_sqr = A[right] * A[right];

            if (left_sqr > right_sqr) {
                v[index--] = left_sqr;
                left++;
            } else {
                v[index--] = right_sqr;
                right--;
            }
        } 
        
       while (A[left] < 0 && left < size) {
            v[index--] = A[left] * A[left];

            if (++left == size) {
                break;
            }
        }

        while (A[right] >= 0 && right >= 1) {
            v[index--] = A[right] * A[right];

            if (--right == -1) {
                break;
            }
        }

        return v;     
    }
};