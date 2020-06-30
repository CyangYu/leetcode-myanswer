#include "common.h"

USESTD

class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int size = nums.size();
        vector<int> dp(size);

        int sum = 0, maxSum = 0;

        for (int i = 0; i < size; i++) 
            dp[i] = max(nums[i], nums[i] + dp[i - 1]);

        maxSum = dp[0];
        for (int j = 0; j < size; j++)
            if (dp[j] > maxSum)
                maxSum = dp[j];

        return maxSum;
    }
};