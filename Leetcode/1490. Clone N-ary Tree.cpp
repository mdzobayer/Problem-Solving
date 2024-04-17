/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    Node* cloneTree(Node* root) {
        if (root == nullptr) return nullptr;

        int totalChild = root->children.size();
        Node * newRoot = new Node(root->val, vector<Node*>(totalChild, nullptr));

        for (int i = 0; i < totalChild; ++i) {
            newRoot->children[i] = cloneTree(root->children[i]);
        }

        return newRoot;
    }
};