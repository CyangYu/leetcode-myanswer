#include "node.h"
#include "common.h"

USESTD

class Solution {
public:
    TreeNode *merge(TreeNode *left, TreeNode *right) {
        if (left == nullptr && right == nullptr) 
            return nullptr;
        else if (left != nullptr && right == nullptr) 
            return left;
        else if (left == nullptr && right != nullptr)
            return right;
        else {
            left->val += right->val;
            left->left = merge(left->left, right->left);
            left->right = merge(left->right, right->right);
            return left;
        }
    }

    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        return merge(t1, t2);
    }
};