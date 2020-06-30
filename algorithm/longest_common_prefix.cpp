#include "common.h"

USESTD

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string prefix = "";

         if (strs.size() == 0)
            return prefix;
            
        for (int i = 0; i < strs[0].length(); i++) {
            for (int j = 1; j < strs.size(); j++) {
                if (strs[j].length() < i)
                    return prefix;
                if (strs[j][i] != strs[0][i])
                    return prefix;
            }

            prefix.append(1, strs[0][i]);
        }

        return prefix;
    }
};