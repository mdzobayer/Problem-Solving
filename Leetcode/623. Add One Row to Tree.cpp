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
    int val, depth;
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        this->val = val;
        this->depth = depth;

        if (depth == 1) {
            TreeNode* cursor = new TreeNode(val, root, nullptr);
            return cursor;
        }

        solve(root, 1);

        return root;
    }

    void solve(TreeNode* root, int level) {
        if (root == nullptr) return;

        if (level == depth - 1) {
            TreeNode* cursor1 = new TreeNode(val, root->left, nullptr);
            TreeNode* cursor2 = new TreeNode(val, nullptr, root->right);

            root->left = cursor1;
            root->right = cursor2;
            return;
        }

        solve(root->left, level + 1);
        solve(root->right, level + 1);
    }
};