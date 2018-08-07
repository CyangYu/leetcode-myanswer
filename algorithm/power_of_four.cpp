#include <math.h>
#include <iostream>

class Solution {
public:
    bool isPowerOfFour(int num) {
        return (fmod(log10(num) / log10(4), 1) == 0);
    }
};

int main(void)
{
    int number;
    Solution solution;

    std::cin >> number;
    if (solution.isPowerOfFour(number) == true)
        std::cout << "Yes" << std::endl;
    else
        std::cout << "No" << std::endl;
    
    std::cout << log10(number) / log10(4) << std::endl;
    std::cout << fmod(log10(number) / log10(4), 1) << std::endl;    
    return 0;
}