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
    vector<int> prefix;
    int totalSum;
public:
    TreeNode* bstToGst(TreeNode* root) {
        totalSum = 0;
        prefix.resize(101, 0);

        traverse(root, false);

        for (int i = 1; i < 101; ++i) {
            prefix[i] += prefix[i - 1];
        }

        traverse(root, true);

        return root;
    }

    void traverse(TreeNode* root, bool assignSum) {
        if (root == nullptr) return;

        if (!assignSum) {
            totalSum += root->val;
            prefix[root->val] = root->val;
        }
        else {
            root->val = totalSum - prefix[root->val] + root->val;
        }

        traverse(root->left, assignSum);
        traverse(root->right, assignSum);
    }
};