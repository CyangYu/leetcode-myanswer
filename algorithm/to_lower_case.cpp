#include <string>
#include <cctype>

using namespace std;

class Solution {
public:
    string toLowerCase(string str) {
        string lower(str);

        for (int i = 0; i < str.size(); i++) {
            if (isupper(str[i])) {
                lower[i] = tolower(str[i]);
            }
        }

        return lower;
    }
};