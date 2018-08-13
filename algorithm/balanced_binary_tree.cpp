#include "node.h"
#include "common.h"

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        
    }

    int height(TreeNode *root) {
        if (root != nullptr) {
            return height(root->left);
        }
    }
};