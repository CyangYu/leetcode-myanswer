#include "common.h"

USESTD

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> m;
        vector<int> indices;

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (m.find(complement) != m.end()) {
                indices.push_back(m[complement]);
                indices.push_back(i);
                return indices;
            }

            m.insert(make_pair(nums[i], i));
        }

        return indices;
    }
};
