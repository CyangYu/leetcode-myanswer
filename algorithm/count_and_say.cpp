#include "common.h"

USESTD;

class Solution {
public:
    string next(string current) {
        string result;
        int i = 0, count = 1;
        
        while (i < current.size()) {
            char ch = current[i];
            for (int j = i + 1; j < current.size(); j++) {
                if (current[j] == ch)
                    count++;
                else
                    break;
            }

            i += count;

            result.append(1, '0' + count);
            result.append(1, ch);
            count = 1;
        }

        return result;
    }
    
    string countAndSay(int n) {
        string current = "1";

        if (n == 1)
            return current;
        
        for (int i = 2; i <= n; i++)
            current = next(current);
        
        return current;
    }
};
