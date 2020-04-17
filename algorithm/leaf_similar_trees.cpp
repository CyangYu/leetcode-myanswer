#include "common.h"
#include "node.h"

USESTD

class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr || root2 == nullptr) {
            return false;
        }

        vector<int> left, right;
        traverse(root1, left);
        traverse(root2, right);

        if (left.size() != right.size()) {
            return false;
        }

        auto size = left.size();
        for (int i = 0; i < size; i++) {
            if (left[i] != right[i]) {
                return false;
            }
        }

        return true;
    }

    void traverse(TreeNode *node, vector<int> &collector) {
        if (node == nullptr) {
            return;
        }

        if (node->left == nullptr && node->right == nullptr) {
            collector.push_back(node->val);
            return;
        }

        traverse(node->left, collector);
        traverse(node->right, collector);
    }
};