#include <stdio.h>
#include <stack>
#include <algorithm>

using namespace std;

typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int depth(TreeNode *root)
    {
        int size = 0;
        if (root != nullptr) {
            size = 1;
            size += max(depth(root->left), depth(root->right));
        }
        
        return size;
    }
    
    int maxDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        return depth(root);
    }
};