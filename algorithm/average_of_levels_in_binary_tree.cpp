#include "node.h"
#include "common.h"

USESTD

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;

        if (root == nullptr)
            return result;
        
        int lastCount = 0, count = 0;
        queue<TreeNode *> q;
        
        q.push(root);
        lastCount = 1;
        while (!q.empty()) {
            double sum = 0.0f;
            for (int i = 0; i < lastCount; i++) {
                root = q.front();
                q.pop();

                if (root->left != nullptr) {
                    q.push(root->left);
                    count++;
                } 

                if (root->right != nullptr) {
                    q.push(root->right);
                    count++;
                }

                sum += root->val;
            }

            result.push_back(sum / lastCount);
            lastCount = count;
            count = 0;
        }

        return result;
    }
};