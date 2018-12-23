#include "node.h"
#include "common.h"

USESTD

class Solution {
public:
    string tree2str(TreeNode* t) {
        string result;

        if (t == nullptr)
            return result;

        preorder(t, result);
        return result;
    }

    void preorder(TreeNode *node, string &result) {
        if (node != nullptr) {
            result.append(1, '(');
            result.append(to_string(node->val));

            if (node->left == nullptr && node->right != nullptr) {
                result.append("()");
            }

            preorder(node->left, result);
            preorder(node->right, result);
            result.append(1, ')');
        }
    }
};