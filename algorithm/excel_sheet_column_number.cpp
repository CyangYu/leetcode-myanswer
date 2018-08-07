#include <cmath>
#include <iostream>

using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        auto len = s.length();
        int result = 0;

        for (int i = 0; i < len; i++) 
            result += (s[i] - 'A' + 1) * (int)pow(26, len - 1 - i);

        return result;
    }
};

int main(int argc, char *argv[])
{
    Solution solution;

    cout << solution.titleToNumber(argv[1]) << endl;
    return 0;    
}