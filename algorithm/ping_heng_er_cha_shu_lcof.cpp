#include "common.h"
#include "node.h"

USESTD 

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true;
        if (!isBalanced(root->left) || !isBalanced(root->right)) return false;
        if (abs(depth(root->left) - depth(root->right)) > 1) return false;
        return true;
    }
    
    int depth(TreeNode *node) {
        if (node == nullptr) return 0;
        return 1 + max(depth(node->left), depth(node->right));
    }
};