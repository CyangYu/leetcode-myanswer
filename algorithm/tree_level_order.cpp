#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> vv;
        queue<TreeNode *> q; 
        TreeNode *parent = root;

        q.push(parent);
        while (!q.empty()) {
            std::vector<int> v;

            TreeNode *node = q.front();
            q.pop();

            if (node->left) {
                v.push_back(node->left->val);
                q.push(node->left);
            if (node->right) {
                v.push_back(node->left->val);
                q.push(node->right);
            
            vv.push_back(v);
        }

        return vv;
    }
};