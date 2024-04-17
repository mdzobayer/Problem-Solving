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
    vector< pair<double, int> > diffValues;
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> ans;
        int i;
        findValue(root, target);
        sort(diffValues.begin(), diffValues.end());

        for(i = 0; i < k; ++i) {
            ans.push_back(diffValues[i].second);
        }

        return ans;
    }

    double absD(double value) {
        if (value < 0) {
            value *= -1;
        }

        return value;
    }

    void findValue(TreeNode* root, double target) {
        if (root == nullptr) return;

        diffValues.push_back(make_pair(absD(target - root->val), root->val));
        findValue(root->left, target);
        findValue(root->right, target);
    }
};