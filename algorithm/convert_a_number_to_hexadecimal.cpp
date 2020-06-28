#include "common.h"

USESTD

class Solution {
public:
    string toHex(int num) {
        unsigned int temp = num;
        
        stack<char> s;
        string hex;

        char ch = 0;

        while (temp > 0) {
            for (int j = 0; j < 4; j++) {
                ch |= (temp & 0x1) << j; 
                temp >>= 1;
            }

            if (ch >= 0 && ch <= 9) {
                s.push('0' + ch);
            } else if (ch >= 10 && ch <= 15) {
                s.push('a' + ch - 10);
            }

            ch = 0;
        }

        while (!s.empty()) {
            hex.append(1, s.top());
            s.pop();
        }

        return hex;
    }
};
