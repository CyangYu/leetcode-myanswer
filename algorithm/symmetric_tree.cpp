#include "node.h"
#include "common.h"

class Solution {
public:
    bool symmetric(TreeNode *left, TreeNode *right) {
        if (left == nullptr && right == nullptr)
            return true;

        if (left == nullptr || right == nullptr)
            return false;

        return (left->val == right->val) && 
                symmetric(left->left, right->right) && 
                symmetric(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {
        return symmetric(root, root);
    }
};