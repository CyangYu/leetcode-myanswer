#include <cstdlib>
#include <iostream>

class Solution {
public:
    bool isUgly(int num) {
        int prime = 2;

        if (num < 1)
            return false;
            
        while (num > 1) {
            if (num % prime == 0)
                num /= prime;
            else
                prime++;
        }

        return (prime < 7);
    }
};

int main(int argc, char *argv[])
{
    Solution solution;
    if (solution.isUgly(std::atoi(argv[1])) == true)
        std::cout << "Yes" << std::endl;
    else
        std::cout << "No" << std::endl;

    return 0;
}