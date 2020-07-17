#include "common.h"

USESTD 

class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> result;

        int size = nums.size();
        if (size == 0) return result;

        int count, num;
        for (int i = 0; i < size - 1; i += 2) {
            count = nums[i];
            num = nums[i + 1];

            for (int j = 0; j < count; j++) {
                result.push_back(num);
            }
        }

        return result;
    }
};