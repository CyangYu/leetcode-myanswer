#include "common.h"
#include "node.h"

USESTD 

class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        if (root == nullptr) return false;

        int x_depth = depth(root, x);
        int y_depth = depth(root, y);
        return x_depth == y_depth;
    }

    int depth(TreeNode *node, int num, int &depth) {
        if (node == nullptr) return 0;
        if (node->val == num) return depth;
        return 1 + max(depth(node->left, num), depth(node->right, num));
    }
};
