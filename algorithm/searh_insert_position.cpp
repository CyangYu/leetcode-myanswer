#include "common.h"

USESTD;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        size_t low = 0, high = nums.size();

        while (low < high) {
            size_t mid = (low + high) / 2;
            if (nums[mid] < target) low = mid + 1;
            else if (nums[mid] > target) high = mid;
            else return mid;
        }

        int i;

        for (i = 0; i < nums.size(); i++) {
            if (nums[i] > target) {
                auto iter = nums.begin() + i;
                nums.insert(iter, 1, target);
                break;
            }
        }

        return i;
    }
};