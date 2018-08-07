#include "node.h"
#include "common.h"

USESTD;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> vv;
        queue<TreeNode *> q; 
        
        int levelCount = 1;
        TreeNode *node = root;
        
        q.push(node);
        while (!q.empty()) {
            vector<int> level;
            for (int i = 0; i < levelCount; i++) {
                node = q.front();
                q.pop();        
                if (node != nullptr) {
                    level.push_back(node->val);
                    q.push(node->left);
                    q.push(node->right);
                }
            }
            
            vv.push_back(level);
            levelCount *= 2;
        }

        return vv;
    }
};
