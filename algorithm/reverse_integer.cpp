#include <cmath>
#include <cstdlib>
#include <iostream>

class Solution {
public:
    long long reverse(int x) {
        int n = 0;
        long long r = 0;
        int num = std::abs(x);

        while (num > 0) {
            n = num % 10;
            num /= 10;
            r = r * 10 + n;
        }
        if (sizeof(r) > sizeof(int))
            return 0;
        else
            return (x < 0) ? -r : r;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    int x = std::atoi(argv[1]);
    long long r = s.reverse(x);
    std::cout << r << std::endl;
    return 0;
}