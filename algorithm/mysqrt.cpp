#include <stdio.h>

class Solution {
public:
    int mySqrt(int x) {
        long g = x;
        
        while(g*g>x) {
            g = (g+x/g)>>1;
        }
        return g;
    }
};

int main(void)
{
    Solution solution;
    int x = solution.mySqrt(4);
    float _x = 1.0f / x;
    printf("%d\n", x);
    return 0;
}