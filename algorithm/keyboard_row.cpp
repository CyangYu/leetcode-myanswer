#include "common.h"

USESTD

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        set<char> row0 {'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P'};
        set<char> row1 {'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L'};
        set<char> row2 {'Z', 'X', 'C', 'V', 'B', 'N', 'M'};

        vector<set<char>> vset;
        vector<string> result;

        vset.push_back(row0);
        vset.push_back(row1);
        vset.push_back(row2);

        bool in_row = true;

        for (string &s : words) {
            for (int i = 0; i < 3; i++) {
                in_row = true;
                for (int j = 0, len = s.size(); j < len; j++) {
                    if (vset[i].find(toupper(s[j])) == vset[i].end()) {
                        in_row = false;
                        break;
                    }
                }

                if (in_row == true) {
                    break;
                }
            }
            
            if (in_row == true) {
                result.push_back(s);
            }
        }

        return result;
    }
};