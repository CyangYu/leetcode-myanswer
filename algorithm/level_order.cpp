#include "node.h"
#include "common.h"

USESTD;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> vv;

        if (root == nullptr)
            return vv;

        TreeNode *node = root;
        queue<TreeNode *> nodeq;

        nodeq.push(node);

        int count = 1;
        int nextcount = 0;

        while (!nodeq.empty()) {
            vector<int> v;
            for (int i = 0; i < count; i++) {
                node = nodeq.front();
                if (node->left != nullptr) {
                    nodeq.push(node->left);
                    nextcount++;
                } 

                if (node->right != nullptr) {
                    nodeq.push(node->right);
                    nextcount++;
                }

                nodeq.pop();
                v.push_back(node->val);
            }
            
            count = nextcount;
            nextcount = 0;
            vv.push_back(v);
        }

        return vv;
    }
};

