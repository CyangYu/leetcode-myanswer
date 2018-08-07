#include "Node.h"

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        queue<TreeNode *> q;
        TreeNode *node = root;
        
        if (node)
            q.push(node);
        
        while (!q.empty()) {
            node = q.front();
            q.pop();
            
            if (node->left) {
                if (node->left->val >= node->val)
                    return false;
                q.push(node->left);
            }
            
            if (node->right) {
                if (node->right->val <= node->val)
                    return false;
                q.push(node->right);
            }
        }
        
        return true;
    }
};