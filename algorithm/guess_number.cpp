#include "common.h"

USESTD;

class Solution {
public:
    int g = 0;

    int guessNumber(int n) {
        if (guess(n) == 0) return n;

        int low = 1, high = n;
        while (low < high) {
            int mid = (low + high) / 2;
            int ans = guess(mid);
            
            if (ans == -1) high = mid;
            else if (ans == 1) low = mid - 1;
            else if (ans == 0) return mid;
        }
        
        return -1;
    }

    int guess(int num)
    {
        if (num > g) return 1;
        else if (num < g) return -1;
        else return 0;
    }
};