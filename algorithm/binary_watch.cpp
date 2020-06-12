#include "common.h"

USESTD 

class Solution {
public:
    int hour[5] = {0, 1, 2, 4, 8};
    int minute[7] = {0, 1, 2, 4, 8, 16, 32};

    vector<string> readBinaryWatch(int num) {
        vector<string> result;
        check(result, num);
        return result;
    }

    void check(vector<string> &result, int num) {
        if (num == 0) {
            return;
        }

        for (int i = 0; i < num; i++) {

        }
    }
};
