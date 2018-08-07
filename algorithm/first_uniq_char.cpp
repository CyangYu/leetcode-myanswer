#include <limits.h>
#include <stdio.h>
#include <string>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        if (s.empty())
            return -1;
            
        int chars[26] = { 0 };
        int pos[26] = { 0 };
        
        for (int i = 0; i < 26; i++)
            pos[i] = -1;
    
        for (int i = 0; i < s.size(); i++) {
            int ch = s[i] - 'a';
            chars[ch]++;
            if (pos[ch] == -1)
                pos[ch] = i;
        }
        
        int min = INT_MAX;
        for (int i = 0; i < 26; i++) {
            if (chars[i] == 1) {
                if (min > pos[i])
                    min = pos[i];
            }
        }
        
        return min == INT_MAX ? -1 : min;
    }
};

int main(int argc, char *argv[])
{
    Solution solution;
    int i = solution.firstUniqChar(string(argv[1]));
    printf("%d\n", i);
    return 0;
}