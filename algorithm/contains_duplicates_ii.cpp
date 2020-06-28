#include "common.h"

USESTD

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (nums.size() == 0)
            return false;
        
        map<int, int> duplicate;
        for (int i = 0; i < nums.size(); i++) {
            auto iter = duplicate.find(nums[i]);
            if (iter != duplicate.end() && i - iter->second <= k) {
                return true;
            } else {
                duplicate.insert(make_pair(nums[i], i));
            }
        }

        return false;  
    }
};