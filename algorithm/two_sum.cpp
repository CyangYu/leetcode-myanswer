/*Given an array of integers, return indices of the two numbers 
 *such that they add up to a specific target. You may assume that 
 *each input would have exactly one solution, and you may not use 
 *the same element twice.
 *
 *Example:
 *Given nums = [2, 7, 11, 15], target = 9,
 *Because nums[0] + nums[1] = 2 + 7 = 9,
 *return [0, 1].
 */
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> indices;
        auto length = nums.size();

        for (int i = 0; i < length; i++) {
            for (int j = 0; j < length; j++) {
                if (i == j)
                    continue;
                if (nums[i] + nums[j] == target) {
                    indices.push_back(i);
                    indices.push_back(j);
                    return indices;
                }
            }
        }
    }
};

int main()
{
    int nums[] = {3, 2, 4};
    vector<int> n(nums, nums + sizeof(nums) / sizeof(int));

    Solution solution;

    vector<int> index = solution.twoSum(n, 6);

    for (auto &iter : index)
        cout << iter << "\n";

    return 0;
}