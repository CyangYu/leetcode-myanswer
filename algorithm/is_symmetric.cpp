#include "node.h"
#include "common.h"

USESTD

class Solution {
public:
    void symmetric(TreeNode *left, TreeNode *right, bool &ret) {
        if (left == nullptr || right == nullptr)
            return;

        

        symmetric(left->left, right->right, ret);
        symmetric(left->right, right->left, ret);
    }

    bool isSymmetric(TreeNode* root) {
        bool ret = true;

        if (root == nullptr)
            return ret;

        symmetric(root->left, root->right, ret);
        return ret;
    }
};