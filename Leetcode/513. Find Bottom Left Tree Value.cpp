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
    int level, val;

    int findBottomLeftValue(TreeNode* root) {
        level = -1;

        solve(root, 0);

        return val;
    }

    void solve(TreeNode * root, int l) {
        if (root == nullptr) return;

        if (l > level) {
            level = l;
            val = root->val;
        }

        solve(root->left, l + 1);
        solve(root->right, l + 1);
    }
};