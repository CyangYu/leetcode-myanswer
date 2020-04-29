#include "common.h"
#include "node.h"

USESTD 

class Solution {
public:
    string reformat(string s) {
        vector<char> digits;
        vector<char> letters;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                digits.push_back(s[i]);
            } else if (s[i] >= 'a' && s [i] <= 'z') {
                letters.push_back(s[i]);
            }
        }

        string result = "";
        if (digits.size() > letters.size() + 1 || letters.size() > digits.size() + 1) {
            return result;
        }

        if (digits.size() > letters.size()) {
            for (int i = 0; i < letters.size(); i++) {
                result.append(1, digits[i]);
                result.append(1, letters[i]);
            }

            result.append(1, digits[digits.size() - 1]);
        } else if (letters.size() > digits.size()) {
            for (int i = 0; i < digits.size(); i++) {
                result.append(1, letters[i]);
                result.append(1, digits[i]);
            }

            result.append(1, letters[letters.size() - 1]);
        } else {
            for (int i = 0; i < digits.size(); i++) {
                result.append(1, letters[i]);
                result.append(1, digits[i]);
            }
        }

        return result;
     }
};