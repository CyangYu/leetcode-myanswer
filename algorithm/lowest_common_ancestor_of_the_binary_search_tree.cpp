#include "node.h"
#include "common.h"

USESTD

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || p == nullptr || q == nullptr)
            return nullptr;

        while (root ) {
            if ((p->val <= root->val && q->val >= root->val) || 
                (p->val >= root->val && q->val <= root->val)) {
                    return root;
            } else if (p->val < root->val && q->val < root->val) {
                root = root->left;
            } else if (p->val > root->val && q->val > root->val) {
                root = root->right;
            }
        }

        return root;
    }
};