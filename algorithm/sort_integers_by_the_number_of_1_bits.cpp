#include "common.h"

USESTD 

bool compare(int a, int b) {
    int num_a = count_one(a);
    int num_b = count_one(b);
    return num_a != num_b ? num_a < num_b : a < b;
}

int count_one(int num) {
    int count = 0;
    while (num != 0) {
        count = num & 0x01 ? count + 1 : count;
        num >>= 1;
    }
    return count;
} 

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), compare);
    }
};
