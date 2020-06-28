#include "common.h"

USESTD

class Solution {
public:
    bool isValid(std::string str) {
        std::stack<char> parentheses;
        auto length = str.size();
        for (int i = 0; i < length; i++) {
            char ch = str[i];
            switch (ch) {
                case '[': case '(': case '{':
                    parentheses.push(ch);
                    break;

                case ']': 
                    if (parentheses.empty() || parentheses.top() != '[')
                        return false;
                    else
                        parentheses.pop();
                    break;

                case ')':
                    if (parentheses.empty() || parentheses.top() != '(')
                        return false;
                    else
                        parentheses.pop();
                    break;

                case '}':
                    if (parentheses.empty() || parentheses.top() != '{')
                        return false;
                    else
                        parentheses.pop();
                    break;

                default:
                    break;
            }
        }
        return parentheses.empty() ? true : false;
    }
};
