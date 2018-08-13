#include "common.h"

USESTD

class Solution {
public:
    string reverseString(string s) {
        int low = 0, high = s.size() - 1;
        while (low < high) {
            swap(s[low++], s[high--]);
        }

        return s;
    }
};

int main(void)
{
    string input;
    Solution solution;

    getline(cin, input);
    cout << solution.reverseString(input) << endl;
    return 0;
}