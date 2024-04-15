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
    vector<int> lonleyNodes;
public:
    vector<int> getLonelyNodes(TreeNode* root) {
        solve(root);
        return lonleyNodes;
    }

    void solve(TreeNode* root) {
        if (root == nullptr) return;

        solve(root->left);
        solve(root->right);
        
        if (root->left != nullptr && root->right == nullptr) {
            lonleyNodes.push_back(root->left->val);
        }

        if (root->right != nullptr && root->left == nullptr) {
            lonleyNodes.push_back(root->right->val);
        }
    }
};