#include "common.h"
#include "node.h"

USESTD 

class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        stack<TreeNode *> s;
        TreeNode newRoot(0), *pNew = &newRoot;
        TreeNode *node = root;

        while (node != nullptr || !s.empty()) {
            while (node != nullptr) {
                s.push(node);
                node = node->left;
            }

            if (s.empty()) break;

            node = s.top();
            pNew->right = node;
            pNew = pNew->right;

            s.pop(); 
            node = node->right;
        }

        return newRoot.right;
    }
};