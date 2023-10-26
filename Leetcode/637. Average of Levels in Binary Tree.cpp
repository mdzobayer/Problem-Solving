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
    vector<long long int> levelSum, levelCount; 
public:
    vector<double> averageOfLevels(TreeNode* root) {

        solve(root, 0);

        vector<double> ans;
        for (int i = 0; i < levelCount.size(); ++i) {
            ans.push_back((double)levelSum[i]/levelCount[i]);
        }

        return ans;
    }

    void solve(TreeNode * root, int level) {
        if (root == nullptr) return;

        if (levelSum.size() <= level) {
            levelSum.push_back(root->val);
            levelCount.push_back(1);
        }
        else {
            levelSum[level] += root->val;
            levelCount[level] += 1;
        }

        solve(root->left, level + 1);
        solve(root->right, level + 1);
    }
};