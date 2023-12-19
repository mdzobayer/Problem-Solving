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
    int target;
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return root;

        target = targetSum;

        return solve(root, 0);
    }

    bool solve(TreeNode * root, int sum) {
        if (root == nullptr) return false;

        sum += root->val;

        if (root->left == nullptr && root->right == nullptr && sum == target) return true;

        return solve(root->left, sum) || solve(root->right, sum);
    }
};