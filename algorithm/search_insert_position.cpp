#include <vector>
#include <cstdlib>
#include <iostream>

class Solution {
public:
    int searchInsert(std::vector<int> &nums, int target) {
        int length = nums.size();

        for (int i = 0; i < length; i++) {
            if (target <= nums[i]) {
                return i;
            }
        }

        return nums.size();
    }
};

int main(int argc, char *argv[])
{
    Solution solution;
    int array[] = {1, 3, 5, 6};
    std::vector<int> nums(array, array + 4);
    int pos = solution.searchInsert(nums, atoi(argv[1]));
    
    std::cout << pos << std::endl;
    return 0;
}