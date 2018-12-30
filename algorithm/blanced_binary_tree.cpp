#include "node.h"
#include "common.h"

USESTD

class Solution {
public:
    int dfs(TreeNode *root, bool &ret) {
        if (root == nullptr)
            return 0;
        
        int left = dfs(root->left, ret) + 1;
        int right = dfs(root->right, ret) + 1;

        if (abs(left - right) > 1)
            ret = false;
        
        return max(left, right);
    }

    bool isBalanced(TreeNode* root) {
        bool ret = true;
        dfs(root, ret);
        return ret;
    }
};