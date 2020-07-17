#include "common.h"

USESTD 

class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        vector<int> temp;
        int idxA = 0, idxB = 0;

        while (idxA < m && idxB < n) {
            if (A[idxA] < B[idxB]) {
                temp.push_back(A[idxA++]);
            } else {
                temp.push_back(B[idxB++]);
            }
        }

        for (; idxA < m; idxA++) {
            temp.push_back(A[idxA]);
        } 
        
        for (; idxB < n; idxB++) {
            temp.push_back(B[idxB]);
        }

        for (int i = 0, size = temp.size(); i < size; i++) {
            A[i] = temp[i];
        }
    }
};