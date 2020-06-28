#include "common.h"

USESTD 

class Solution {
public:
    int romanToInt(std::string &s) {
        auto len = s.size();
        int base = 0, priority = 0, prevPriority = 0, number = 0;

        for (int i = len - 1; i >= 0; i--) {
            switch (s[i]) {
                case 'I':
                    base = 1;
                    priority = 0;
                    break;
                case 'V':
                    base = 5;
                    priority = 1;
                    break;
                case 'X':
                    base = 10;
                    priority = 2;
                    break;
                case 'L':
                    base = 50;
                    priority = 3;
                    break;
                case 'C':
                    base = 100;
                    priority = 4;
                    break;
                case 'D':
                    base = 500;
                    priority = 5;
                    break;
                case 'M':
                    base = 1000;
                    priority = 6;
                    break;
                default:
                    break;
            }
            if (i == len - 1)
                prevPriority = priority;

            if (prevPriority > priority)
                base = -base;
            number += base;
            prevPriority = priority;
        }

        return number;
    }
};