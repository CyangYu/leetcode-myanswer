#include "common.h"

USESTD 

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> result;

        int size = nums.size();
        if (size == 0) return result;

        int arr[101] = {0};
        for (int i = 0; i < size; i++) {
            arr[nums[i]]++;
        }

        return result;
    }
};