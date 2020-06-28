#include "common.h"

USESTD 

class Solution {
public:
    int titleToNumber(string s) {
        auto len = s.length();
        int result = 0;

        for (int i = 0; i < len; i++) 
            result += (s[i] - 'A' + 1) * (int)pow(26, len - 1 - i);

        return result;
    }
};
