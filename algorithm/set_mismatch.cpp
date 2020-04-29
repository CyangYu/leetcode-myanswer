#include "common.h"

USESTD 

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        auto size = nums.size();
        int sum = 0;

        vector<int> result = {0, 0};
        int temp[size + 1];

        for (int i = 0; i < size + 1; i++) {
            temp[i] = 0;
        }

        for (int i = 0; i < size; i++) {
            if (temp[nums[i]] == 0) {
                temp[nums[i]] = nums[i];
            } else {
                result[0] = nums[i];
            }

            sum += nums[i];
        }

        int s = (1 + size) * size / 2;
        result[1] = s - sum + result[0];
        return result;
    }
};