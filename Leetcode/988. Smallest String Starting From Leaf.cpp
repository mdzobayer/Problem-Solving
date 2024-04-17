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
    set<string> st;
public:
    string smallestFromLeaf(TreeNode* root) {
        string s = "";
        traverse(root, s);

        return *st.begin();
    }

    void traverse(TreeNode * root, string & s) {
        s.push_back(root->val + 'a');

        if (root->left == nullptr && root->right == nullptr) {

            reverse(s.begin(), s.end());
            st.insert(s);
            reverse(s.begin(), s.end());

            s.pop_back();
            return;
        }

        
        if (root->left != nullptr)
            traverse(root->left, s);
        
        if (root->right != nullptr)
            traverse(root->right, s);
        
        s.pop_back();
    }
};