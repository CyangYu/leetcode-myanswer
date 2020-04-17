#include "common.h"

USESTD 

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int>> result;

        if (S.size() < 3)
            return result;

        int begin = 0;
        int count = 1;
        char lastCh = S[0];
        auto size = S.size();

        for (int i = 1; i < size; i++) {
            if (S[i] == lastCh) {
                count++;
                if (count >= 3 && (i == size - 1 || S[i + 1] != lastCh)) {
                    vector<int> res = {begin, i};
                    result.push_back(res);
                }
            } else {
                begin = i;
                lastCh = S[i];
                count = 1;
            }
        }

        return result;
    }
};

int main(int argc, char *argv[])
{
    Solution solution;
    vector<vector<int>> result = solution.largeGroupPositions(string(argv[1]));
    for (auto res : result) {
        for (auto num : res) {
            cout << num << ' ';
        }
        cout << endl;
    }

    return 0;
}