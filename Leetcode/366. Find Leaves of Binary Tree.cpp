/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    vector< vector<int> > leafNodes;
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<int> nodes;
        int level = 0;
        leafNodes.push_back(nodes);

        while(!isLeaf(root, level)) {
            ++ level;
            leafNodes.push_back(nodes);
        }

        leafNodes[level].push_back(root->val);
        //delete root;
        root = nullptr;

        return leafNodes;
    }

    bool isLeaf(TreeNode * root, const int level) {
        if (root == nullptr) true;

        bool leaf = true;

        if (root->left != nullptr) {
            leaf = false;
            if (isLeaf(root->left, level)) {
                leafNodes[level].push_back(root->left->val);
                //delete root->left;
                root->left = nullptr;
            }
        }

        if (root->right != nullptr) {
            leaf = false;
            if (isLeaf(root->right, level)) {
                leafNodes[level].push_back(root->right->val);
                //delete root->right;
                root->right = nullptr;
            }
        }

        return leaf;
    }
};