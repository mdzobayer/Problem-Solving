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
    int sum;
    int low, high;
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        sum = 0;
        this->low = low;
        this->high = high;

        solve(root);
        return sum;
    }

    void solve(TreeNode * root) {
        if (root == nullptr) return;

        if (root->val >= low && root->val <= high) {
            sum += root->val;
        }

        solve(root->left);
        solve(root->right);
    }
};