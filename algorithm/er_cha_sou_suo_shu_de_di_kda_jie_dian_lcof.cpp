#include "common.h"
#include "node.h"

USESTD 

class Solution {
public:
    int kthLargest(TreeNode* root, int k) {
        vector<int> v;
        stack<TreeNode *> s;
        
        TreeNode *node = root;
        while (!s.empty() || node != nullptr) {
            while (node != nullptr) {
                s.push(node);
                node = node->left;
            }

            if (s.empty()) {
                break;
            }

            node = s.top();
            v.push_back(node->val);
            node = node->right;
            s.pop();
        }

        return v[v.size() - k];
    }
};