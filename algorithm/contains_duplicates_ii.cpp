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