#include "common.h"

USESTD;

class Solution {
public:
    Solution(vector<int> nums) {
        backup = vector<int>(nums.begin(), nums.end());
        u = uniform_int_distribution<int>(0, nums.size() - 1);
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return backup;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> result(backup.begin(), backup.end());
        
        for (int i = 0; i < result.size(); i++) { 
            int idx = u(e);
            swap(result[i], result[idx]);
        }

        return result;
    }

private:
    uniform_int_distribution<int> u;
    default_random_engine e;
    vector<int> backup;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */