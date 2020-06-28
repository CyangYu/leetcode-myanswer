#include "common.h"

USESTD 

class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0, n = 0;
        string result = "";
        
        int i = a.size() - 1, j = b.size() - 1;
        
        while (i >= 0 && j >= 0) {
            n = a[i] - '0' + b[j] - '0' + carry;
            carry = n >= 2 ? n / 2 : 0;
            result.insert(0, 1, (n % 2) + '0');
            i--; j--;
        }
        
        
        while (i >= 0) {
            n = a[i] - '0' + carry;
            carry = n >= 2 ? n / 2 : 0;
            result.insert(0, 1, (n % 2) + '0');
            i--;
        }
        
         while (j >= 0) {
            n = b[j] - '0' + carry;
            carry = n >= 2 ? n / 2 : 0;
            result.insert(0, 1, (n % 2) + '0');
            j--;
        }
        
        if (carry) 
            result.insert(0, 1, '1');
        
        return result;
    }
};