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
    double maximumAvg = 0;
public:
    double maximumAverageSubtree(TreeNode* root) {
        calculateSubTree(root);

        return maximumAvg;
    }

    pair<int, int> calculateSubTree(TreeNode * root) {
        if (root == nullptr) return make_pair(0, 0);

        int count = 1, sum = root->val;

        pair<int, int> child;

        child = calculateSubTree(root->left);
        count += child.first;
        sum += child.second;

        child = calculateSubTree(root->right);
        count += child.first;
        sum += child.second;

        maximumAvg = max(maximumAvg, (double) sum / count);

        return make_pair(count, sum);
    }
};