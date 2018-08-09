#include "common.h"

USESTD

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (nums.size() == 0)
            return false;
        
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 1; j <= k && i + j < nums.size(); j++) {
                if (nums[i] == nums[i + j]) {
                    return true;
                }
            }
        }

        return false;  
    }
};

int main(int arg, char *argv[])
{
    vector<int> v = { 1,2,3,4,5,6,7,8,9,9 };
    Solution solution;
    bool ret = solution.containsNearbyDuplicate(v, 3);
    if (ret == true) 
        cout << "Yes" << endl;
    else 
        cout << "No" << endl;
    return 0;
}