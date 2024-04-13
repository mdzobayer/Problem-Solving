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
    int subCount = 0;
public:
    int countUnivalSubtrees(TreeNode* root) {
        dfs(root);

        return subCount;
    }

    bool dfs(TreeNode * root) {
        if (root == nullptr) return true;

        bool leftTree = dfs(root->left);
        bool rightTree = dfs(root->right);

        if (!leftTree || !rightTree) return false;

        if (root->left != nullptr && root->left->val != root->val) return false;
        if (root->right != nullptr && root->right->val != root->val) return false;
        
        ++subCount;
        return true;
    }
};