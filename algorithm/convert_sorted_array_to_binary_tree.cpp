#include "common.h"
#include "node.h"

USESTD

class Solution {
public:
    TreeNode *buildTree(vector<int> nums, int low, int high, TreeNode *root) {
        if (low > high)
            return nullptr;
        
        if (low == high)
            return new TreeNode(nums[low]);
            
        int mid = low + (high - low) / 2;
        TreeNode *node = new TreeNode(nums[mid]);
        node->left = buildTree(nums, low, mid - 1, node);
        node->right = buildTree(nums, mid + 1, high, node);
        return node;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        auto size = nums.size();

        if (size == 0)
            return nullptr;
        
        int mid = (size - 1) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = buildTree(nums, 0, mid - 1, root);
        root->right = buildTree(nums, mid + 1, size - 1, root);
        return root;
    }
};

void inorderTravesTree(TreeNode *root, function<void(TreeNode *)> func)
{
    if (root == nullptr)
        return;
    inorderTravesTree(root->left, func);
    func(root);
    inorderTravesTree(root->right, func);
}

int main(int argc, char *argv[])
{
    vector<int> nums = { -10, -3, 0, 5, 9 };

    Solution solution;
    TreeNode *root = solution.sortedArrayToBST(nums);

    vector<TreeNode *> v;
    inorderTravesTree(root, [&](TreeNode *node) -> void {
        cout << node->val << ' ';
        v.push_back(node);
    });

    for (auto &n : v) {
        delete n;
        n = nullptr;
    }

    return 0;
}