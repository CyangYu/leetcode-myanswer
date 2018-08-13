#include "common.h"

USESTD

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int left   = max(rec1[0], rec2[0]);
        int top    = max(rec1[1], rec2[1]);
        int right  = min(rec1[2], rec2[2]);
        int bottom = min(rec1[3], rec2[3]);
        
        return right > left && bottom > top;
    } 
};