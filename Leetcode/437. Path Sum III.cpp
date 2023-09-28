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
    int pathSum(TreeNode* root, int targetSum) {
        vector<int> q;
        return solve(root, q, 0, targetSum);
    }

    int solve(TreeNode * cursor, vector<int> q, int totalSum, int targetSum) {
        if (cursor == nullptr) return (0);

        int ans = 0, i;
        long long sum = 0;
        q.push_back(cursor->val);

        for (i = q.size() - 1; i >= 0; --i) {
            sum += q[i];
            if (sum == targetSum) {
                ans += 1;
            }
        }    

        return (ans + 
        solve(cursor->left, q, totalSum, targetSum) + 
        solve(cursor->right, q, totalSum, targetSum));
    }
};