#include "node.h"
#include "common.h"

USESTD

class Solution {
public:
    int depth(TreeNode *root)
    {
        int size = 0;
        if (root != nullptr) {
            size = 1;
            size += max(depth(root->left), depth(root->right));
        }
        
        return size;
    }
    
    int maxDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        return depth(root);
    }
};