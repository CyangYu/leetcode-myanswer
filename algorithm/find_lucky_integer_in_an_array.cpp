#include "common.h"
#include "node.h"

USESTD 

class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<int,int> m;
        for (int i = 0, size = arr.size(); i < size; i++) {
            if (m.find(arr[i]) == m.end()) {
                m.insert(make_pair(arr[i], 1));
            } else {
                m[arr[i]]++;
            }
        }

        int max = INT_MIN;
        bool hasLucky = false;

        for (auto iter = m.begin(); iter != m.end(); iter++) {
            if (iter->first == iter->second) {
                hasLucky = true;
                if (iter->first > max) {
                    max = iter->first;
                }
            }
        }

        return hasLucky ? max : -1;
    }
};