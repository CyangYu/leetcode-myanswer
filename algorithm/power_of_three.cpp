#include <math.h>
#include <iostream>

class Solution {
public:
    bool isPowerOfThree(int n) {
        return (fmod(log10(n) / log10(3), 1) == 0);
    }
};

int main(void)
{
    int number;
    Solution solution;

    std::cin >> number;
    if (solution.isPowerOfThree(number) == true)
        std::cout << "Yes" << std::endl;
    else
        std::cout << "No" << std::endl;
    
    std::cout << log10(number) / log10(3) << std::endl;
    std::cout << fmod(log10(number) / log10(3), 1) << std::endl;    
    return 0;
}