#include "common.h"
#include "node.h"

USESTD 

class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        return find(root, root->val);
    }

    int find(TreeNode *root, int val) {
        if (root == nullptr) return -1;
        if (root->val > val) return root->val;

        int left = find(root->left, val);
        int right = find(root->right, val);

        if (left < 0) return right;
        if (right < 0) return left;
        return min(left, right);
    }
};