#include "common.h"

USESTD

class Solution {
public:
    int singleNumber(vector<int> &nums) {
        auto len = nums.size();

        sort(nums.begin(), nums.end());
        if (nums[0] != nums[1] || len == 1)
            return nums[0];

        for (int i = 1; i < len; i++) {
            if (nums[i] != nums[i - 1] && nums[i] != nums[i + 1])
                return nums[i];
        }
    }
};

int main(int argc, char *argv[])
{
    Solution solution;
    int array[] = {2, 3, 4, 5, 4, 3, 2};
    vector<int> nums(array, array + sizeof(array) / sizeof(int));

    int res = solution.singleNumber(nums);
    cout << res << endl;
    return 0;
}