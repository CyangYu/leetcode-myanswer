#include "common.h"
#include "node.h"

USESTD 

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        auto size = nums.size();

        int dp[size];
        dp[0] = nums[0];

        int max_sum = nums[0];
        for (int i = 1; i < size; i++) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            max_sum = max(max_sum, dp[i]);
        }

        return max_sum;
    }
};