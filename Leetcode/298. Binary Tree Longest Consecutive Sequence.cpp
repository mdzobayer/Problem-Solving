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
    int maxLen = 0;
public:
    int longestConsecutive(TreeNode* root) {
        solve(root, 0);

        return maxLen;
    }

    void solve(TreeNode * root, int lastLen) {
        if (root == nullptr) return;

        ++ lastLen;

        if (root->left != nullptr) {
            if (root->val + 1 == root->left->val) {
                solve(root->left, lastLen);
            }
            else solve(root->left, 0);
        }

        if (root->right != nullptr) {
            if (root->val + 1 == root->right->val) {
                solve(root->right, lastLen);
            }
            else solve(root->right, 0);
        }

        maxLen = max(maxLen, lastLen);
    }
};