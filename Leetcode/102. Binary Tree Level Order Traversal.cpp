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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> row;

        if (root == nullptr) return ans;

        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 0));

        TreeNode* cursor;
        pair<TreeNode*, int> aPair;

        while(!q.empty()) {
            aPair = q.front();
            q.pop();

            if (ans.size() <= aPair.second) {
                ans.push_back(row);
            }

            cursor = aPair.first;
            ans[aPair.second].push_back(cursor->val);

            if (cursor->left != nullptr) {
                q.push(make_pair(cursor->left, aPair.second + 1));
            }

            if (cursor->right != nullptr) {
                q.push(make_pair(cursor->right, aPair.second + 1));
            }
        }

        return ans;
    }
};