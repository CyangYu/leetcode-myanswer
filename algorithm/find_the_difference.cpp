#include "common.h"

USESTD

class Solution {
public:
    char findTheDifference(string s, string t) {
        int ssum = 0;
        int tsum = 0;

        for (int i = 0; i < s.size(); i++)
            ssum += s[i] - 'a';
        
        for (int j = 0; j < t.size(); j++)
            tsum += t[j] - 'a';
        
        return (tsum - ssum) + 'a';
    }
};