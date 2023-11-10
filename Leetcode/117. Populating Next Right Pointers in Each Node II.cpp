/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        Node* cursor,* previous;
        vector<vector<Node*>> ajlist;

        travers(root, 0, ajlist);

        for (int i = 0; i < ajlist.size(); ++i) {
            for (int j = 1; j < ajlist[i].size(); ++j) {
                previous = ajlist[i][j - 1];
                cursor = ajlist[i][j];
                previous->next =  cursor;
            }
            cursor = nullptr;
        }

        return root;
    }

    void travers(Node* root, int level, vector<vector<Node*>>& ajlist) {
        if (root == nullptr) return;

        if (level >= ajlist.size()) {
            vector<Node*> listRow;
            ajlist.push_back(listRow);
        }

        ajlist[level].push_back(root);

        travers(root->left, level + 1, ajlist);
        travers(root->right, level + 1, ajlist);
    }
};