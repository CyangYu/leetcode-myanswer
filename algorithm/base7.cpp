#include "common.h"

USESTD

class Solution {
public:
    string convertToBase7(int num) {
        int n = num;
        
        string result;
        stack<char> s;
        
        if (num < 0) {
            n = -num;
            result.append(1, '-');
        }
    
        if (num == 0)
            return "0";
        
        while (n > 0) {
            s.push((n % 7) + '0');
            n /= 7;    
        }   
        
        while (!s.empty()) {
            result.append(1, s.top());
            s.pop();
        }

        return result;
    }
};