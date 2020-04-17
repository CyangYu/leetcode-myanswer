#include "node.h"
#include "common.h"

USESTD

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == nullptr)
            return nullptr;

        while (root != nullptr) {
            if (root->val > val) {
                root = root->left;
            } else if (root-> val < val) {
                root = root->right;
            } else {
                return root;
            }
        }

        return nullptr;
    }
};