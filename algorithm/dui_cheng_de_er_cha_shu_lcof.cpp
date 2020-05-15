#include "common.h"
#include "node.h"

USESTD 

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }

        return symmetric(root->left, root->right);
    }

    bool symmetric(TreeNode *left, TreeNode *right) {
        if (left == nullptr && right == nullptr) {
            return true;
        } 

        if (left == nullptr && right != nullptr ||
            left != nullptr && right == nullptr ||
            left->val != right->val) {
            return false;
        }        

        return symmetric(left->left, right->right) && symmetric(left->right, right->right);
    }
};