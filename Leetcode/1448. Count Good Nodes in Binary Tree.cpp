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
    int goodNodes(TreeNode* root) {
        return solve(root, root->val);
    }

    int solve(TreeNode * cursor, int maxValue) {
        if (cursor == nullptr) return 0;

        int result = 0;
        if (cursor->val >= maxValue) {
            result = 1;
            maxValue = cursor->val;
        }

        return result + solve(cursor->left, maxValue) + solve(cursor->right, maxValue);
    }
};