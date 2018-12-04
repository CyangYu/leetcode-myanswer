#include "common.h"

USESTD 

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int idx = 0;
        auto size = bits.size();

        while (idx < size) {
            if (bits[idx] == 1) {
                idx += 2;

                if (idx == size)
                    return false;  
            } else { 
                if (idx == size - 1)
                    return true;
                idx++;
            }
        }
    }
};