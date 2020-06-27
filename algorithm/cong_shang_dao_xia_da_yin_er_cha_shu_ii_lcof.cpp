#include "common.h"
#include "node.h"

USESTD 

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        int last = 0, curr = 0;
        queue<TreeNode *> q;
        vector<vector<int>> v;

        q.push(root);
        last = 1;

        while (!q.empty()) {
            vector<int> row;
            for (int i = 0; i < last; i++) {
                TreeNode *node = q.front();
                
                if (node->left != nullptr) {
                    q.push(node->left);
                    curr++;
                }

                if (node->right != nullptr) {
                    q.push(node->right);
                    curr++;
                }

                row.push_back(node->val);
            }

            if (!row.empty()) {
                v.push_back(row);
            }

            last = curr;
            curr = 0;
        }

        return v;
    }
};