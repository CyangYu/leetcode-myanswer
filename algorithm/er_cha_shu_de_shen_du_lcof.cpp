#include "common.h"
#include "node.h"

USESTD 

class Solution {
public:
    int maxDepth(TreeNode* root) {
        return depth(root);
    }

    int depth(TreeNode *node) {
        if (node == nullptr) return 0;
        return 1 + max(depth(node->left), depth(node->right));
    }
};