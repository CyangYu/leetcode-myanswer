#include "node.h"
#include "common.h"

USESTD

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode *> q;
        TreeNode *node = root;

        if (root != nullptr)
            q.push(node);
        
        while (!q.empty()) {
            node = q.front();
            
            TreeNode *temp = node->left;
            node->left = node->right;
            node->right = temp;
            
            if (node->left != nullptr)
                q.push(node->left);
            
            if (node->right != nullptr)
                q.push(node->right);
            
            q.pop();
        }

        return root;    
    }
};