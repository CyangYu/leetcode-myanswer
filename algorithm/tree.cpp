#include "common.h"
#include "node.h"

USESTD 

using Visit = function<void(TreeNode *)>;

class Tree
{
public:

    Tree();
    ~Tree();

    void insert(int v);
    void bfs(Visit visit);
    void dfs(Visit visit);

protected:
    void preorder_iter(TreeNode *root, Visit visit);
    void inorder_iter(TreeNode *root, Visit visit);
    void postorder_iter(TreeNode *root, Visit visit);

    void preorder_recur(TreeNode *root, Visit visit);
    void inorder_recur(TreeNode *root, Visit visit);
    void postorder_recur(TreeNode *root, Visit visit);

    void destroy();

private:
    TreeNode *_root;
};

Tree::Tree()
    : _root(nullptr)
{
}

Tree::~Tree()
{
    destroy();
}

void Tree::insert(int v)
{
    if (_root == nullptr) {
        _root = new TreeNode(v);
        return;
    }

    TreeNode *curr = _root, *parent = _root;
    while (true) {
        parent = curr;
        if (v < curr->val) {
            curr = curr->left;
            if (curr == nullptr) {
                parent->left = new TreeNode(v);
                break;
            }
        } else if (v > curr->val) {
            curr = curr->right;
            if (curr == nullptr) {
                parent->right = new TreeNode(v);
                break;
            }
        } else
            break;
    }
}

void Tree::bfs(Visit visit)
{
    queue<TreeNode *> q;
    TreeNode *node = _root;

    q.push(node);
    while (!q.empty()) {
        node = q.front();
        visit(node);
        q.pop();

        if (node->left)
            q.push(node->left);
        
        if (node->right)
            q.push(node->right);
    }
}

void Tree::dfs(Visit visit)
{
    printf("preorder iterate\n");
    preorder_iter(_root, visit);
    putchar('\n');

    printf("inorder iterate\n");
    inorder_iter(_root, visit);
    putchar('\n');

    printf("postorder iterate\n");
    postorder_iter(_root, visit);
    putchar('\n');

    printf("preorder recursive\n");
    preorder_recur(_root, visit);
    putchar('\n');

    printf("inorder recursive\n");
    inorder_recur(_root, visit);
    putchar('\n');

    printf("postorder recursive\n");
    postorder_recur(_root, visit);
    putchar('\n');
}

void Tree::preorder_iter(TreeNode *root, Visit visit)
{
    stack<TreeNode *> s;
    TreeNode *node = root;

    while (node != nullptr || !s.empty()) {
        while (node != nullptr) {
            visit(node);
            s.push(node);
            node = node->left;
        }

        if (s.empty())
            return;
        
        node = s.top();
        s.pop();
        node = node->right;
    }
}

void Tree::inorder_iter(TreeNode *root, Visit visit)
{
    stack<TreeNode *> s;
    TreeNode *node = root;

    while (node != nullptr || !s.empty()) {
        while (node != nullptr) {
            s.push(node);
            node = node->left;
        }

        if (s.empty())
            return;

        node = s.top();
        visit(node);
        s.pop();
        node = node->right;
    }
}

void Tree::postorder_iter(TreeNode *root, Visit visit)
{
    stack<TreeNode *> s;
    TreeNode *node = root, *parent = nullptr;

    if (node != nullptr)
        s.push(node);

    while (!s.empty()) {
        parent = s.top();
        if (parent->left != node && parent->right != node) {
            while ((node = s.top()) != nullptr) {
                if (node->left != nullptr) {
                    if (node->right != nullptr) {
                        s.push(node->right);
                    }
                    s.push(node->left);
                } else {
                    s.push(node->right);
                }
            }
            s.pop();
        }

        node = s.top();
        visit(node);
        s.pop();
    }
}

void Tree::preorder_recur(TreeNode *root, Visit visit)
{
    if (root != nullptr) {
        visit(root);
        preorder_recur(root->left, visit);
        preorder_recur(root->right, visit);
    }
}

void Tree::inorder_recur(TreeNode *root, Visit visit)
{
    if (root != nullptr) {
        inorder_recur(root->left, visit);
        visit(root);
        inorder_recur(root->right, visit);
    }
}

void Tree::postorder_recur(TreeNode *root, Visit visit)
{
    if (root != nullptr) {
        postorder_recur(root->left, visit);
        postorder_recur(root->right, visit);
        visit(root);
    }
}

void Tree::destroy()
{
    vector<TreeNode *> nodelist;
    Visit visit = [&](TreeNode *node) -> void {
        nodelist.push_back(node);
    };

    inorder_iter(_root, visit);

    if (!nodelist.empty()) {
        for (auto &node : nodelist) {
            node->left = nullptr;
            node->right = nullptr;
            delete node;
            node = nullptr;
        }   

        _root = nullptr;
    }

    nodelist.clear();
}

int main(int argc, char *argv[])
{
    Tree tree;

    srand(time(nullptr));
    for (int i = 0; i < 10; i++) {
        tree.insert(rand() % 50);
    }
    
    function<void(TreeNode*)> visit = [](TreeNode *node) -> void {
        printf("Address: %p Left: %p Right: %p Val: %d \n", node, node->left, node->right, node->val);
    };

    tree.dfs(visit); 
    printf("Breadth First Search\n");
    tree.bfs(visit); 
    putchar('\n');

    return 0;
}