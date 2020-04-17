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
            swap(node->left, node->right);

            if (node->left != nullptr)
                q.push(node->left);
            
            if (node->right != nullptr)
                q.push(node->right);
            
            q.pop();
        }

        return root;    
    }
};