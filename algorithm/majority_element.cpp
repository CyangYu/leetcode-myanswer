#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int> &nums) {
        auto size = nums.size();
    
        sort(nums.begin(), nums.end());
        return nums[size / 2];
    }
};

int main(int argc, char *argv[])
{
    Solution solution;
    int array[11] = {5, 1, 5, 3, 5, 4, 2, 5, 6, 5, 5};
    vector<int> nums(array, array + 11);
    cout << solution.majorityElement(nums) << endl;
    return 0;
}