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
    int maxPossible = -10000;
public:
    int maxPathSum(TreeNode* root) {

        solve(root);

        return maxPossible;
    }

    int solve(TreeNode * root) {
        if (root == nullptr) return -10000;

        int leftSum, rightSum, childMax;
        leftSum = solve(root->left);
        rightSum = solve(root->right);

        // Path with root only
        maxPossible = max(maxPossible, root->val);
    
        // Path with left and right subtree
        maxPossible = max(maxPossible, (leftSum + rightSum + root->val));

        // Part of a path
        childMax = max(leftSum, rightSum);

        // Path last element
        if (childMax + root->val < root->val)
            return root->val;

        // Not path's leaf element
        maxPossible = max(maxPossible, childMax + root->val);

        return childMax + root->val;
    }
};