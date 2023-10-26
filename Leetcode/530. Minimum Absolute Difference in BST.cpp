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
    vector<int> vt;
public:
    int getMinimumDifference(TreeNode* root) {
        solve(root);

        int ans = INT_MAX;
        sort(vt.begin(), vt.end());
        for (int i = 1; i < vt.size(); ++i) {
            ans = min(ans, abs(vt[i] - vt[i - 1]));
        }

        return ans;
    }

    void solve(TreeNode * root) {
        if (root == nullptr) return;

        vt.push_back(root->val);

        solve(root->left);
        solve(root->right);
    }
};