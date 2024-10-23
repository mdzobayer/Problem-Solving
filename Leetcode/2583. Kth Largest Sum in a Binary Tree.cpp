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
    vector<long long> levelSum;
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        traverse(root, 0);

        if (levelSum.size() < k) return -1;

        sort(levelSum.begin(), levelSum.end(), greater<long long>());
        return levelSum[k - 1];
    }

    void traverse(TreeNode * root, int level) {
        if (root == nullptr) return;

        if (levelSum.size() <= level) {
            levelSum.push_back(0);
        }

        levelSum[level] += root->val;

        traverse(root->left, level + 1);
        traverse(root->right, level + 1);
    }
};