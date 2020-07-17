#include "common.h"
#include "node.h"

USESTD 

class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }

        vector<TreeNode *> v;
        traverse(root, v);

        for (int i = v.size() - 1; i >= 1; i--) {
            v[i - 1]->val += ‘v[i]->val;
        }

        return root;
    }

    void traverse(TreeNode *node, vector<TreeNode *> &v) {
        stack<TreeNode *> s;

        s.push(node);
        while (node != nullptr && !s.empty()) {
            while (node != nullptr) {
                s.push(node);
                node = node->left;
            }

            if (s.empty()) {
                return;
            }

            node = s.top();
            v.push_back(node);
            node = node->right;
            s.pop();
        }
    }
};
