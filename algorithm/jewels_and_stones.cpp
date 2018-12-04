#include "common.h"

USESTD

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        set<char> jewels;
        int count = 0;

        for (auto jewel : J) 
            jewels.insert(jewel);
        
        for (auto stone : S) 
            if (jewels.find(stone) != jewels.end())
                count++;
                
        return count;
    }
};