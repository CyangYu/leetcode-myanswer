#include "common.h"

USESTD 

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<string> result;
        char array[26] = {0};

        string &str = A[0];
        for (int i = 0, len = str.size(); i < len; i++) {
            array[str[i] - 'a']++;
        }

        for (string &str : A) {
            char temp[26] = {0};
            for (int i = 0, size = str.size(); i < size; i++) {
                temp[str[i] - 'a']++;
            }

            for (int j = 0; j < 26; j++) {
                array[j] = min(array[j], temp[j]);    
            }
        }

        for (int i = 0; i < 26; i++) {
            if (array[i] > 0) {
                int count = array[i];
                string str(1, 'a' + i);
                for (int j = 0; j < count; j++) {
                    result.push_back(str);
                }
            }
        }

        return result;
        
    }
};