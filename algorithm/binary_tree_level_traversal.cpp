#include "node.h"
#include "common.h"

USESTD

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;

        if (root == nullptr)
            return result;

        TreeNode *node = root;
        list<TreeNode *> nodelist;
        queue<TreeNode *> nodequeue;

        nodequeue.push(root);

        while (!nodequeue.empty()) {
            node = nodequeue.front();
            nodelist.push_back(node);
            nodequeue.pop();

            if (node != nullptr) {
                nodequeue.push(node->left);
                nodequeue.push(node->right);
            }
        }

        int sum = 0, count = 1;
        auto size = nodelist.size();
        auto iter = nodelist.begin();

        while (sum <= size) {
            vector<int> level;

            for (int i = 0; i < count; i++) {
                if (iter != nodelist.end()) {
                    if (*iter != nullptr) {
                        level.push_back((*iter)->val);
                    }
                    
                    iter++;
                }
            }
            
            if (level.size() != 0) 
                result.push_back(level);
            
            sum += count;
            count *= 2;
        }

        return result;
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