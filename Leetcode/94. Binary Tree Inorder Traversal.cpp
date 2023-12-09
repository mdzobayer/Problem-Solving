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
    vector<int> list;
public:
    vector<int> inorderTraversal(TreeNode* root) {
        inorderTravers(root);
        return list;
    }

    void inorderTravers(TreeNode * root) {
        if (root == nullptr) return;

        inorderTravers(root->left);
        list.push_back(root->val);
        inorderTravers(root->right);
    }
};