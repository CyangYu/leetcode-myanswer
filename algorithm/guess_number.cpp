#include "common.h"

USESTD;

int g = 0;

int guess(int num)
{
    if (num > g) return 1;
    else if (num < g) return -1;
    else return 0;
}

class Solution {
public:
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
};

int main(int argc, char *argv[])
{
    g = atoi(argv[1]);
    Solution solution;
    int ans = solution.guessNumber(atoi(argv[2]));
    cout << ans << endl;
    return 0;
}