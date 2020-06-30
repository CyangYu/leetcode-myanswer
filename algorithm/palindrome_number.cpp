#include "common.h"

USESTD 

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