#include "common.h"

USESTD

class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        vector<int> result;

        for (int i = 0; i < S.size(); i++) {
            if (S[i] == C) {
                result.push_back(0);
            } else {
                int len0 = -1, len1 = -1;
                for (int j = i + 1; j < S.size(); j++) {
                    if (S[j] == C) {
                        len0 = j - i;
                        break;
                    }
                } 

                for (int j = i - 1; j >= 0; j--) {
                    if (S[j] == C) {
                        len1 = i - j;
                        break;
                    }
                } 

                if (len0 != -1 && len1 != -1) 
                    result.push_back(len0 > len1 ? len1 : len0);
                else if (len0 == -1) 
                    result.push_back(len1);
                else if (len1 == -1)
                    result.push_back(len0);
            }
        }

        return result;     
    }
};