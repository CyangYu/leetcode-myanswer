#include "common.h"

USESTD

class Solution {
public:
    int majorityElement(vector<int> &nums) {
        int count = 0;
        int majority = nums[0];
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == majority) {
                count++;
            } else {
                count--;
                if (count == 0) {
                    majority = nums[i + 1];
                }
            }
        }
        
        return majority;        
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