#include "common.h"
#include "node.h"

USESTD 

class Solution {
public:
    TreeNode* convertBiNode(TreeNode* root) {
        TreeNode head(0);
        traverse(&head, root);
        return head.right;
    }

    void traverse(TreeNode *prev, TreeNode *node) {
        if (node == nullptr) {
            return;
        }

        traverse(prev, node->left);
        prev->left = nullptr;
        prev->right = node;
        prev = node;
        traverse(prev, node->right);
    }
};

int main(int argc, char *argv[])
{
    TreeNode *root = new TreeNode(4);
    TreeNode *child0 = new TreeNode(2);
    TreeNode *child1 = new TreeNode(5);
    TreeNode *child2 = new TreeNode(1);
    TreeNode *child3 = new TreeNode(3);
    TreeNode *child4 = new TreeNode(6);
    TreeNode *child5 = new TreeNode(0);

    root->left = child0;
    root->right = child1;
    child0->left = child2;
    child0->right = child3;
    child1->left = nullptr;
    child1->right = child4;
    child2->left = child5;
    child2->right = nullptr;
    child3->left = nullptr;
    child3->right = nullptr;
    child4->left = nullptr;
    child4->right = nullptr;
    child5->left = nullptr;
    child5->right = nullptr;

    Solution solution;
    TreeNode *head = solution.convertBiNode(root);
    TreeNode *node = head;

    while (node != nullptr) {
        cout << node->val;
        node = node->right;
    }

    delete root;
    delete child0;
    delete child1;
    delete child2;
    delete child3;
    delete child4;
    delete child5;

    return 0;
}