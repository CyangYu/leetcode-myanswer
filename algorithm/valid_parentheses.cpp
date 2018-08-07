#include <stack>
#include <string>
#include <iostream>

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

int main(int argc, char *argv[])
{
    Solution solution;
    std::string str;

    std::getline(std::cin, str);
    if (solution.isValid(str))
        std::cout << "Valid" << std::endl;
    else
        std::cout << "Invalid" << std::endl;

    return 0;
}