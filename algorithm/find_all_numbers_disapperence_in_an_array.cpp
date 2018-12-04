#include "common.h"

USESTD

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> result;
        
        
        return result;
    }
};

int main(int argc, char *argv[])
{
    Solution solution;
    vector<int> v = { 4, 3, 2, 7, 8, 2, 3, 1 };

    vector<int> result = solution.findDisappearedNumbers(v);
    for (auto num : result) 
        cout << num << endl;
    return 0;
}