#include "common.h"

USESTD

class Solution {    
public:
    int sum = 0;

    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        calc_left_leaves_sum(root);
        return sum;
    }

    void calc_left_leaves_sum(TreeNode *node) {
        if (node == nullptr) {
            return;
        }

        if (node->left != nullptr && 
            node->left->left == nullptr &&
            node->left->right == nullptr) {
            sum += node->left->val;        
        }

        calc_left_leaves_sum(node->left);
        calc_left_leaves_sum(node->right);
    }
};