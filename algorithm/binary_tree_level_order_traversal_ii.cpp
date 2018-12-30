#include "node.h"
#include "common.h"

USESTD

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
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

        reverse(vv.begin(), vv.end());
        return vv;
    }
};

int main(int argc, char *argv[])
{
    TreeNode root(3);
    TreeNode node1(9), node2(20), node3(15), node4(7);

   /* root.left = &node1;
    root.right = &node2;
    node2.left = &node3;
    node2.right = &node4;*/

    Solution solution;
    vector<vector<int>> v = solution.levelOrder(&root);

    for (auto level : v) {
        for (auto n : level) {
            cout << n << ' ';
        }

        cout << endl;
    }

    return 0;
}