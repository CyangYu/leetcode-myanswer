#include <cctype>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        auto len = s.length();
        string temp;

        if (len == 0)
            return true;

        for (int i = 0; i < len; i++) {
            if (std::isalnum(s[i]) != 0) 
                temp.append(1, s[i]);
        }
    
        len = temp.length();
        for (int i = 0; i < len / 2; i++) {
            if (std::toupper(temp[i]) != std::toupper(temp[len - 1 - i]))
                return false;
        }
        return true;
    }
};

int main(int argc, char *argv[])
{
    Solution solution;
    if (solution.isPalindrome(string(argv[1])) == true)
        cout << argv[1] << " is palindrome string" << endl;
    else
        cout << argv[1] << " is not palindrome string" << endl;
    return 0;
}