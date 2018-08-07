class Solution {
public:
    int binaryGap(int N) {
        int last = -1, len = 0; 
        for (int i = 0; i < 0x20; i++) {
            if (((N >> i) & 0x1) > 0) {
                if (last >= 0) {
                    len = len > i - last ? len : i - last;
                }

                last = i;
            }
        }

        return len;      
    }
};