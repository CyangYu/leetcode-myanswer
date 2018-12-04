#include "common.h"

USESTD

class Solution {
public:
    int findComplement(int num) {
        int comp = 0;

        for (int i = 0; i < 31; i++) {
            int bit = num & 0x01;
            num >>= 1;
            comp |= (~bit) << i;
        } 
        return comp;
    }
};

int main(int argc, char *argv[])
{
    Solution solution;
    cout << solution.findComplement(atoi(argv[1]));
    return 0;
}