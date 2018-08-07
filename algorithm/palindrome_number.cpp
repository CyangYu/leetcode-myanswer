#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

const int BUFF_LEN = 16;

class Solution {
public:
    bool isPalindrome(int x) {
        char buffer[BUFF_LEN];
        size_t len = std::strlen(buffer);

        for (int i = 0; i < len / 2; i++) {
            if (buffer[i] != buffer[len - 1 - i])
                return false;
        }

        return (x >= 0) ? true : false;
    }
};

int main(int argc, char *argv[])
{
    Solution solution;
    int x = std::atoi(argv[1]);

    if (solution.isPalindrome(x) == true)
        std::cout << x << " is palindrome" << std::endl;
    else
        std::cout << x << " is not palindrome" << std::endl;

    return 0;
}