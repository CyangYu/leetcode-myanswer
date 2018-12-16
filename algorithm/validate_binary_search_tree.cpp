#include "node.h"
#include "common.h"

USESTD;

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        
    }
};

int main(int argc, char *argv[])
{
    TreeNode root(10);
    TreeNode node1(5), node2(15), node3(6), node4(20);

    root.left = &node1;
    root.right = &node2;
    node2.left = &node3;
    node2.right = &node4;

    Solution solution;
    bool ret = solution.isValidBST(&root);
    
    if (ret)
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}