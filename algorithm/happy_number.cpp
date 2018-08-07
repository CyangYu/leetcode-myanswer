#include <cstdlib>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        int mod, result;

        while (n != 1 && n != 4) {
            result = 0;
            while (n > 0) {
                mod = n % 10;
                n /= 10;
                result += mod * mod; 
            }
            n = result;
        }

        return (n == 1);
    }
};

int main(int argc, char *argv[])
{
    Solution solution;

    if (solution.isHappy(std::atoi(argv[1])) == true)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}
