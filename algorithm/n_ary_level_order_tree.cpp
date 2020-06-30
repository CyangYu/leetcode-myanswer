#include "common.h"

USESTD

struct Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;

        if (root == nullptr)
            return result;

        int lastCount = 0, count = 0;
        Node *node = root;
        queue<Node *> q;
        
        q.push(node);
        lastCount = 1;

        while (!q.empty()) {
            vector<int> level;

            for (int i = 0; i < lastCount; i++) {
                node = q.front();
                level.push_back(node->val);

                for (int j = 0; j < node->children.size(); j++) {
                    if (node->children[j] == nullptr)
                        continue;
                    q.push(node->children[j]);
                    count++;
                }
                q.pop();
            }
        }

        return result;
    }
};
