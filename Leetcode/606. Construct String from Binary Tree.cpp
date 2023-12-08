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
  string ans = "";
public:
    string tree2str(TreeNode* root) {
        preOrder(root);

        return ans;
    }

    void preOrder(TreeNode * root) {
      if (root == nullptr) return;

      ans += to_string(root->val);
    
      if (root->left != nullptr) {
        ans += '(';
        preOrder(root->left);
        ans += ')';
      }
      else if (root->right != nullptr) {
        ans += '(';
        ans += ')';
      }
      
      if (root->right != nullptr) {
        ans += '(';
        preOrder(root->right);
        ans += ')';
      }
    }
};