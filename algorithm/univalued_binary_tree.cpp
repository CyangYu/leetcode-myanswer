#include "node.h"
#include "common.h"

USESTD

class Solution {
public:
    void unique(TreeNode *root, bool &ret) {
        if (root == nullptr || ret == false)
            return;
        
        if (root->left != nullptr && root->right == nullptr) {
            ret = root->val == root->left->val;
            if (ret == true)
                unique(root->left, ret);
            else
                return;
        }

        if (root->left == nullptr && root->right != nullptr) {
            ret = root->val == root->right->val;
            if (ret == true)
                unique(root->right, ret);
            else
                return;
        }

        if (root->left != nullptr && root->right != nullptr) {
            ret = root->val == root->left->val && 
                  root->val == root->right->val;
             
            if (ret == true) {
                unique(root->left, ret);
                unique(root->right, ret);
            }
            else
                return;
        }
    }

    bool isUnivalTree(TreeNode* root) {
        bool ret = true;
        unique(root, ret);
        return ret;  
    }
};
