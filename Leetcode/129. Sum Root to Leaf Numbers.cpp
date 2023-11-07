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
    int sumNumbers(TreeNode* root) {
        int sum = 0;

        prepareSum(root, 0, sum);

        return sum;
    }

    void prepareSum(TreeNode * root, int path, int & sum) {
        if (root == nullptr) {
            return;
        }

        path *= 10;
        path += root->val;

        if (root->left == nullptr && root->right == nullptr) {
            sum += path;
            return;
        }

        prepareSum(root->left, path, sum);
        prepareSum(root->right, path, sum);
    }
};