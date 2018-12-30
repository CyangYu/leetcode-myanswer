#include "common.h"

USESTD

class Solution {
public:
    inline int parse_number(string expr, size_t &idx) {
        int number = 0;
        bool neg = false;

        if (expr[idx] == '-') {
            neg = true;
            idx++;
        }
        
        for (int i = idx; i < expr.size(); i++) {
            if (isdigit(expr[i])) {
                number = number * 10 + expr[i] - '0';
                idx++;
            } else {
                break;
            }
        }

        return neg == true ? -1 * number : number;
    }

    string complexNumberMultiply(string a, string b) {
        size_t idx = 0;
        
        int a0 = parse_number(a,   idx);
        int b0 = parse_number(a, ++idx);

        idx = 0;
        int a1 = parse_number(b,   idx);
        int b1 = parse_number(b, ++idx);

        return to_string(a0 * a1 + -1 * b0 * b1) + "+" + to_string(a0 * b1 + a1 * b0) + "i"; 
    }
};