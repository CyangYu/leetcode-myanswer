#include "common.h"

USESTD

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {        
        size_t idx = 0;
        int count = 0, maxCount = 0;

        while (idx < nums.size()) {
            if (nums[idx] == 1) {
                for (int j = idx; j < nums.size() && nums[j] == 1; j++)
                    count++;

                idx += count;
                if (count > maxCount) {
                    maxCount = count;
                    count = 0;
                }
            } 

            idx++;
            count = 0;
        }

        return maxCount;
    }
};

int main(int argc, char *argv[])
{
    vector<int> arr = { 1, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0 };
    Solution solution;
    cout << solution.findMaxConsecutiveOnes(arr) << endl;
    return 0;
}