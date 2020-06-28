#include "common.h"

USESTD

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> valid_emails;

        for (int i = 0; i < emails.size(); i++) {
            string valid;
            vector<int> dotIdx;
            size_t plus = 0;

            auto size = emails[i].size();
            auto idx = emails[i].find_first_of('@');

            dotIdx.push_back(-1);

            for (int j = 0; j < idx; j++) {
                if (emails[i][j] == '+') {
                    plus = j;
                    break;
                } 
                
                if (emails[i][j] == '.') {
                    dotIdx.push_back(j);
                }
            }

            dotIdx.push_back(plus);
            for (int k = 0; k < dotIdx.size() - 1; k++) {
                size_t len = dotIdx[k + 1] - dotIdx[k] - 1;
                valid.append(emails[i].substr(dotIdx[k] + 1, len));
            }
            valid.append(emails[i].substr(idx, size - idx - 1));
            if (valid_emails.find(valid) == valid_emails.end())
                valid_emails.insert(valid);
        }          

        return valid_emails.size();
    }
};