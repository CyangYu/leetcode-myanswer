#include "node.h"
#include "common.h"

USESTD

class Solution {
public:
    int minDepth(TreeNode* root) {   
        return depth(root);   
    }

    int depth(TreeNode *node) {
        if (node == nullptr) return 0;
        int left = depth(node->left);
        int right = depth(node->right);
        
        if (left < right) {
            return left != 0 ? left + 1 : right + 1;
        } else {
            return right != 0 ? right + 1 : left + 1;
        }
    }
};