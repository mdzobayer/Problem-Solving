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
    bool isValidBST(TreeNode* root) {
        return solve(root, LONG_MIN, LONG_MAX);
    }

    bool solve(TreeNode * root, long minimum, long maximum) {
        if (root == nullptr) return true;

        if (root->val <= minimum || root->val >= maximum)
            return false;

        bool ans = true;
        ans = solve(root->left, minimum, root->val);
        if (!ans) return ans;
        
        ans = solve(root->right, root->val, maximum);

        return ans;
    }
};