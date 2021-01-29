#include "common.h"
#include "node.h"

USESTD 

class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        int sum = 0;
        vector<int> temp;

        traverse(root, sum, temp);
        for (int i = 0; i < temp.size(); i++) {
            sum += temp[i];
        }
        return sum;
    }

    void traverse(TreeNode *node, int sum, vector<int> &temp) {
        if (node == nullptr) return;
        
        sum = (sum << 1) | node->val;
        if (node->left == nullptr && node->right == nullptr) {
           temp.push_back(sum);
           return;
        }

        traverse(node->left, sum, temp);
        traverse(node->right, sum, temp);
    }
};