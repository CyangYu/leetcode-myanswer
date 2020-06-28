#include "common.h"

USESTD 

class Solution {
public:
    string convertToTitle(int n) {
        string res;
        stack<char> container;
        char alphabet[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G',
                           'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O',
                           'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W',
                           'X', 'Y', 'Z'};
        while (n > 0) {
            int mod = n % 26;
            if (mod == 0)
                mod = 26; 
            container.push(alphabet[mod - 1]);
            n -= mod;
            if ((n /= 26) < 26) {
                if (n == 0) {
                    break;
                }
                container.push(alphabet[n - 1]);
                break;
            }
        }       

        while (!container.empty()) {
            res.append(1, container.top());
            container.pop();
        }

        return res;
    }
};