#include "node.h"
#include "common.h"

USESTD

class Solution {
public:
    inline vector<TreeNode *> nodeList(TreeNode *root) {
        queue<TreeNode *> q;
        vector<TreeNode *> v;
        TreeNode *node = root;
        
        q.push(node);
        while (!q.empty()) {
            node = q.front();
            v.push_back(node);
            
            q.pop();
            if (node != nullptr) {
                q.push(node->left);
                q.push(node->right);
            }
        }
        
        return v;       
    }
                         
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<TreeNode *> vp = nodeList(p);
        vector<TreeNode *> vq = nodeList(q);

        if (vp.size() != vq.size())
            return false;
        
        for (int i = 0; i < vp.size(); i++) {
            if ((vp[i] == nullptr && vq[i] != nullptr) || 
                (vp[i] != nullptr && vq[i] == nullptr) ||
                (vp[i]->val != vq[i]->val)) 
                return false;
        }

        return true;
    }
};