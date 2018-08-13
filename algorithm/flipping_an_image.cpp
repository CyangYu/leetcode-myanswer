#include "common.h"

USESTD

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int rows = A.size();
        int cols = A[0].size();

        for (int r = 0; r < rows; r++) {
            int low = 0, high = cols - 1;
            while (low <= high) {
                swap(A[r][low++], A[r][high--]);
            }

            for (int c = 0; c < cols; c++) 
                A[r][c] = A[r][c] == 0 ? 1 : 0;
        }

        return A;     
    }
};

int main(int argc, char *argv[])
{
    vector<vector<int>> A = {
        { 1, 1, 0, 0 }, 
        { 1, 0, 0, 1 }, 
        { 0, 1, 1, 1 }, 
        { 1, 0, 1, 0 } 
    };

    Solution solution;
    A = solution.flipAndInvertImage(A);
    for (int r = 0; r < A.size(); r++) {
        for (int c = 0; c < A[0].size(); c++)
            cout << A[r][c] << ' ';
        cout << '\n';
    }

    return 0;
}