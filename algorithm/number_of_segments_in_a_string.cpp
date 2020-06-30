#include "common.h"

USESTD

class Solution {
public:
    int countSegments(string s) {
        if (s.empty())
            return 0;
        
        int count = 0;
        
        for (int i = 0; i < s.length(); i++) {
            if (!isspace(s[i])) {
                for (int j = i; j < s.length(); j++) {
                    if (isspace(s[j]) || j == s.length() - 1) {
                        i = j;
                        count++;
                        break;
                    }
                }
            }
        }

        return count;
    }
};