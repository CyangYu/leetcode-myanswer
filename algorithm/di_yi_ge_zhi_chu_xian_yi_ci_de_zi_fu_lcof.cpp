#include "common.h"

USESTD 

class Solution {
public:
    char firstUniqChar(string s) {
        int size = s.size();
        if (size == 0) return ' ';

        char ch = ' ';
        uint16_t first = 0xFFFF, high = 0x0000;

        int arr[26] = {0};

        for (int i = 0; i < size; i++) {
            int idx = s[i] - 'a';
            if (arr[idx] == 0) arr[idx] = ((i << 16) & 0xFFFF0000) | 0x00000001;
            else arr[idx]++;
        }

        for (int i = 0; i < 26; i++) {
            high = (uint16_t)((arr[i] & 0xFFFF0000) >> 16);
            if (((arr[i] & 0x0000FFFF) == 1) && (high < first)) {
                first = high;
                ch = i + 'a';
            }
        }

        return ch;
    }
};

int main(int argc, char *argv[]) {
    string str = string(argv[1]);
    
    Solution solution;
    char ch = solution.firstUniqChar(str);
    cout << ch << endl;
    return 0;
}