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
    vector<TreeNode*> ans;
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        
        unordered_set<int> toDelete(to_delete.begin(), to_delete.end());
        if (root != nullptr && toDelete.find(root->val) == toDelete.end()) {
            ans.push_back(root);
        }
        solve(root, toDelete);

        return ans;
    }

    TreeNode * solve(TreeNode * root, unordered_set<int> & toDelete) {
        if (root == nullptr) return nullptr;

        root->left = solve(root->left, toDelete);
        root->right = solve(root->right, toDelete);

        if (toDelete.find(root->val) != toDelete.end()) {
            if (root->left != nullptr)
                ans.push_back(root->left);

            if (root->right != nullptr)
                ans.push_back(root->right);
            
            return nullptr;
        }

        return root;
    }
};