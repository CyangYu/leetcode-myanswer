#include "common.h"

USESTD 

class Solution {
public:
    bool isUnique(string astr) {
        set<char> s;

        for (int i = 0; i < astr.size(); i++) {
            // if (astr.rfind(astr[i]) != i) {
            //    return false;
            //}
            if (s.find(astr[i]) != s.end()) {
                return false;
            } else {
                s.insert(astr[i]);
            }
        }    

        return true;  
    }
};