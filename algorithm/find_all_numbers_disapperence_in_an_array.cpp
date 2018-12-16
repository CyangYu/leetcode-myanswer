#include "common.h"

USESTD

class Solution {
public:
    vector<int> findDisappearedNumbers(int nums[], int size) {
        vector<int> result;
        
        int val = 0;
        for (int i = 0; i < size; i++) {
            val = nums[i] & 0x0000FFFF;
            nums[val - 1] = val << 16 | nums[val - 1];
        }

        for (int i = 0; i < size; i++) {
            nums[i] = (nums[i] & 0xFFFF0000) >> 16;
        }

        for (int i = 0; i < size; i++) {
            if (nums[i] != i + 1) 
                result.push_back(i + 1);
        }
        
        return result; 
    }
};

int main(int argc, char *argv[])
{
    Solution solution;
    int v[] = { 4, 3, 2, 7, 8, 2, 3, 1 };

    vector<int> result = solution.findDisappearedNumbers(v, 8);
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << endl;
    return 0;
}