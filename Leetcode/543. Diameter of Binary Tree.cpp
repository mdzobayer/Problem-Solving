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
public:
    int ans = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        ans = 0;
        solve(root);

        return ans;
    }

    int solve(TreeNode* root) {
        if (root == nullptr) return (0);

        int maximum1 = solve(root->left);
        int maximum2 = solve(root->right);

        ans = max(ans, maximum1 + maximum2);

        return max(maximum1, maximum2) + 1;
    }
};