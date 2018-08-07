#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        auto size = nums.size();
        k = (k < size) ? k : k % size;
        
        int step = size - k;
        for (int i = size - k; i < size; i++) {
            for (int j = 0; j < step; j++) {
                int temp = nums[i- j];
                nums[i - j] = nums[i - j - 1];
                nums[i - j - 1] = temp;
            }
        }
    }
};

int main()
{
    Solution solution;
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7};
    solution.rotate(vec, 3);
    for (int i = 0; i < vec.size(); i++) {
        printf("%d\n", vec[i]);
    }

    return 0;
}