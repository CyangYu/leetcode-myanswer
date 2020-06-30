#include "common.h"

USESTD 

class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        int size = deck.size();
        if (size == 0) return false;

        int num = 0;
        map<int, int> m;

        for (int i = 0; i < size; i++) {
            num = deck[i];
            if (m.find(num) == m.end()) {
                m.insert(make_pair(num, 1));
            } else {
                m[num]++;
            }
        }
        
        int x = 0;
        int count = 0;

        for (auto iter = m.begin(); iter != m.end(); iter++) {
            count = iter->second;
            if (count > 0) {
                x = gcd(x, count);
                if (x == 1) return false;
            }
        }
        return x >= 2;
    }

    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
};