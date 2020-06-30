#include "common.h"

USESTD

class Solution {
public:
    int compress(vector<char>& chars) {
        size_t idx = 0;
        stack<char> cstack;
        int begin = 0, count = 0;
        
        while (idx < chars.size()) {
            char ch = chars[idx];
            for (int j = idx; j < chars.size() && chars[j] == ch; j++)
                count++;

            chars[begin++] = ch;

            int tempCount = count;

            if (tempCount > 1) {
                while (tempCount > 0) {
                    cstack.push('0' + (tempCount % 10));
                    tempCount /= 10;
                }

                while (!cstack.empty()) {
                    chars[begin++] = cstack.top();
                    cstack.pop();
                }
            }

            idx += count;
            count = 0;
        }

        return begin;
    }
};