#include "common.h"
#include "node.h"

USESTD 

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildBST(nums, 0, nums.size());
    }

    TreeNode *buildBST(vector<int> &nums, int left, int right) {
        if (left == right) return nullptr;

        int middle = left + (right - left) / 2;
        TreeNode *node = new TreeNode(nums[middle]);
        node->left = buildBST(nums, left, middle);
        node->right = buildBST(nums, middle + 1, right);
        return node;
    }
};