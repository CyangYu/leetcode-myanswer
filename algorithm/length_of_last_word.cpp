#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        size_t end = 0, index = 0;

        index = s.size() - 1;

        while (index >= 0) {
            if (s[index] != ' ')
                break;
            index--;
        }

        end = index;

        if (index < 0)
            return 0;
        
        while (index >= 0) {
            if (s[index] == ' ')
                break;
            index--;
        }

        return end - index;
    }
};

int main(int argc, char *argv[])
{
    Solution solution;
    string str;
    getline(cin, str);
    auto length = solution.lengthOfLastWord(str);
    cout << length << endl;
    return 0;
}