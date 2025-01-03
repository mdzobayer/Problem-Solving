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
    bool evaluateTree(TreeNode* root) {
        if (root->val == 0) return false;
        else if (root->val == 1) return true;

        if (root->left != nullptr && root->right != nullptr) {
            if (root->val == 2) {
                return evaluateTree(root->left) || evaluateTree(root->right);
            }
            return evaluateTree(root->left) && evaluateTree(root->right);
        }
        if (root->left != nullptr) return evaluateTree(root->left);

        return evaluateTree(root->right);
    }
};