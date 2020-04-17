#include "common.h"

USESTD

class Solution {
public:
    inline bool isvowel(char ch) {
        ch = tolower(ch);
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            return true;
        return false;
    }
    
    string reverseVowels(string s) {
        int low = 0, high = s.size() - 1;        
        
        while (low < high) {
            if (isvowel(s[low])) {
                while (high > low) {
                    if (isvowel(s[high])) {
                        swap(s[low], s[high--]);
                        break;
                    }
                    high--;
                }
            }
            low++;
        }
        return s;
    }
};

int main(int argc, char *argv[])
{
    Solution solution;
    string s = solution.reverseVowels(string(argv[1]));
    cout << s << endl;
    return 0;
}