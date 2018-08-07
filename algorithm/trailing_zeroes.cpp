#include "common.h"

USESTD;

class Solution {
public:
    int trailingZeroes(int n) {
        unsigned long long num;

        for (int i = 1; i <= n; i++) {
            int mod = i % 10;
            if (mod == 2) n2++;
            else if (mod == 4) n4++;
            else if (mod == 5) n5++;
            else if (mod == 8) n8++;
            else if (mod == 0) n10++;
        }

        if ()
    }
};

int main(int argc, char *argv[])
{
    Solution solution;
    int count = solution.trailingZeroes(atoi(argv[1]));
    cout << count << endl;
    return 0;
}