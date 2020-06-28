#include "common.h"
#include "node.h"

USESTD 

class Solution {
public:
    TreeNode* convertBiNode(TreeNode* root) {
        TreeNode head(0);
        traverse(&head, root);
        return head.right;
    }

    void traverse(TreeNode *prev, TreeNode *node) {
        if (node == nullptr) {
            return;
        }

        traverse(prev, node->left);
        prev->left = nullptr;
        prev->right = node;
        prev = node;
        traverse(prev, node->right);
    }
};