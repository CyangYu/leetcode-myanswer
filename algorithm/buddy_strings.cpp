#include "common.h"

USESTD

class Solution {
public:
    bool buddyStrings(string A, string B) {
        if (A.size() != B.size())
            return false;
        
        if (A == B) {
            int count[26] = {0};
            for (int i = 0; i < A.size(); i++) 
                count[A[i] - 'a']++;
            
            for (int j = 0; j < 26; j++)
                if (count[j] > 1)
                    return true;
            return false;
        } else {
            int first = -1, second = -1;
            for (int i = 0; i < A.size(); i++) {
                if (A[i] != B[i]) {
                    if (first == -1)
                        first = i;
                    else if (second == -1)
                        second = i;
                    else 
                        return false;
                }
            }

            return (second != -1 && A[first] == B[second] && A[second] == B[first]);
        }
    }
};