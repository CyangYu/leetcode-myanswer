#include "common.h"

USESTD

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        auto size = nums.size();
        vector<long long> v;
        
        for (int i = 0; i < size; i++)
            v.push_back(nums[i]);
        
        int max = v[0];
        int first = 0;
        for (int i = 1; i < size; i++) 
            if (v[i] > max)
                max = v[i];
        
        first = max;

        for (int i = 0; i < size; i++)
            if (v[i] == max)
                v[i] = LLONG_MIN;
        
        max = v[0];
        for (int i = 1; i < size; i++) 
            if (v[i] > max)
                max = v[i];
        
        for (int i = 0; i < size; i++)
            if (v[i] == max)
                v[i] = LLONG_MIN;

        max = v[0];        
        for (int i = 1; i < size; i++) 
            if (v[i] > max)
                max = v[i];
        
        return max == LLONG_MIN ? first : max;
    }
};
