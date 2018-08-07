#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int> &nums) {
        auto size = nums.size();
        auto sum = 0;

        for (int i = 0; i < size; i++) 
            sum += nums[i];            
        
        return (1  + size) * size / 2 - sum;
    }
};
