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
    vector<int> list;
public:
    vector<int> postorder(Node* root) {
        solve(root);

        return list;
    }

    void solve(Node* root) {
        if (root == nullptr) return;

        for (Node* ptr : root->children) {
            solve(ptr);
        }

        list.push_back(root->val);
    }
};