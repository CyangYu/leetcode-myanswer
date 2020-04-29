#include "common.h"
#include "node.h"

 USESTD 

 class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        auto size1 = s1.size();
        auto size2 = s2.size();

        if (size1 != size2) {
            return false;
        }

        bool b1[26] = {false};
        bool b2[26] = {false};

        for (int i = 0; i < size1; i++) {
            b1[s1[i] - 'a'] = true;
            b2[s2[i] - 'a'] = true;
        }

        for (int j = 0; j < 26; j++) {
            if (b1[j] != b2[j]) {
                return false;
            }
        }

        return true;
        
    }
};