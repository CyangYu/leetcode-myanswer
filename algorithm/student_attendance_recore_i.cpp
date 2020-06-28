#include "common.h"

USESTD

class Solution {
public:
    bool checkRecord(string s) {
        int acount, lcount, pcount;
        size_t idx = 0;

        acount = lcount = pcount = 0;

        while (idx < s.length()) {
            switch (s[idx]) {
            case 'A': 
                idx++;
                acount++;
                break;
            case 'L':
                {
                    for (int j = idx; j < s.length() && s[j] == 'L'; j++)
                        lcount++;
                
                    idx += lcount;
                    if (lcount > 2)
                        return false;

                    lcount = 0;
                }
                break;
            case 'P':
                idx++;
                pcount++;
                break;
            default:
                break;
            }
        }

        return acount <= 1;     
    }
};