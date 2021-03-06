#include "common.h"

USESTD;

class Solution {
public: 
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        
        for (int i = 0; i < nums2.size(); i++) {
            auto iter = search_n(nums1.begin(), nums1.end(), 1, nums2[i]);
            if (iter != nums1.end()) {
                nums1.erase(iter);
                v.push_back(nums2[i]);
            }   
        }

        return v;
    }
};