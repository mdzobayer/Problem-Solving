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
    int maxLen = 1;
public:
    int longestConsecutive(TreeNode* root) {
        solve(root);

        return maxLen;
    }

    // return pair <inc, dec> count
    pair<int,int> solve(TreeNode * root) {
        if (root == nullptr) return make_pair(0, 0);

        pair<int,int> left, right;
        int inc = 1, dec = 1;

        if (root->left != nullptr) {
            left = solve(root->left);
            if (root->val == root->left->val + 1) {
                dec = left.second + 1;
            }
            if (root->val == root->left->val - 1) {
                inc = left.first + 1;
            }
        }

        if (root->right != nullptr) {
            right = solve(root->right);
            if (root->val == root->right->val + 1) {
                dec = max(dec, right.second + 1);
            }
            if (root->val == root->right->val - 1) {
                inc = max(inc, right.first + 1);
            }
        }

        maxLen = max(maxLen, inc + dec - 1);

        return make_pair(inc, dec);
    }
};