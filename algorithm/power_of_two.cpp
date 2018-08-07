#include <iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return (n > 0) && !(n & (n - 1));
    }
};

int main(int argc, char *argv[])
{
    Solution solution;

    if (solution.isPowerOfTwo(atoi(argv[1])) == true)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}