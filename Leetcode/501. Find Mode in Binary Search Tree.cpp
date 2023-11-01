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
    map<int, int> counts;
    int frequent = 0;
public:
    vector<int> findMode(TreeNode* root) {
        find(root);

        map<int, int>::iterator it;
        vector<int> ans;

        for (it = counts.begin(); it != counts.end(); ++it) {
            if (frequent == it->second) {
                ans.push_back(it->first);
            }
        }

        return ans;
    }

    void find(TreeNode * root) {
        if (root == nullptr) return;

        counts[root->val] += 1;
        frequent = max(frequent, counts[root->val]);

        find(root->left);
        find(root->right);
    }
};