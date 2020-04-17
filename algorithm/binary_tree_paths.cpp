#include "common.h"
#include "node.h"

USESTD 

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> collector;
        if (root == nullptr) {
            return collector;
        }

        string path = "";
        appendNodePath(root, path, collector);
        return collector;
    }

    void appendNodePath(TreeNode *node, string &path, vector<string> &collector) {
        if (node == nullptr) {
            return;
        }

        if (node->left == nullptr && node->right == nullptr) {
            collector.push_back(path.append(to_string(node->val)));
            return;
        }

        path.append(to_string(node->val)).append("->");

        appendNodePath(node->left, path, collector);
        appendNodePath(node->right, path, collector);
    }
};