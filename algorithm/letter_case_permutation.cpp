#include "common.h"

USESTD

class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> vecstr;
        vector<int> indices;
        int count = 1;

        for (int i = 0; i < S.size(); i++) {
            if (isalpha(S[i])) {
                count *= 2;
                indices.push_back(i);
            }    
        }   

        for (int i = 0; i < count; i++)
            vecstr.push_back(S);
        
        fill(indices, 0, vecstr, 0, count);
        return vecstr;
    }

    void fill(vector<int> &p, int idx, vector<string> &vec, size_t low, size_t high) {
        if (idx == p.size())
            return;

        size_t mid = (low + high) / 2;

        for (int i = mid; i < high; i++) {
            char &ch = vec[i][p[idx]];
            ch = toupper(ch);
        }

        fill(p, idx + 1, vec, low, mid);
        fill(p, idx + 1, vec, mid, high);
    }
};