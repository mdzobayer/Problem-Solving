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
    int sum = 0;
public:
    int sumOfLeftLeaves(TreeNode* root) {
        solve(root, false);

        return sum;
    }

    void solve(TreeNode * root, bool isLeft) {
        if (root == nullptr) return;

        if (isLeft && root->left == nullptr && root->right == nullptr) {
            sum += root->val;
            return;
        }

        solve(root->left, true);
        solve(root->right, false);
    }
};