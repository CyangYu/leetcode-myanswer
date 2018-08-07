#include <vector>
#include <stdio.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int rows = nums.size();
        int cols = nums[0].size();
        
        if (r * c != rows * cols) 
            return nums;

        vector<vector<int>> matrix;
        
        for (int i = 0; i < r; i++) {
            vector<int> row;
            for (int j = 0; j < c; j++) {
                int idx = i * c + j;
                row.push_back(nums[idx / cols][idx % cols]);
            }
            matrix.push_back(row);
        }

        return matrix;
    }
};

int main()
{
    int array[1][4] = { {1, 2, 3, 4} };
    int array2[2][2] = { 0 };

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            array2[i][j] = array[(i + j) / 4][(i + j) % 4];
        }
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d\n", array2[i][j]);
        }
    }

    return 0;
}