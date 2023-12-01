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
    int preorderIndex;
    map<int, int> inorderIndex;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        for (int i = 0; i < inorder.size(); ++i) {
            inorderIndex[inorder[i]] = i;
        }
        preorderIndex = 0;

        return buildSubTree(preorder, 0, preorder.size() - 1);
    }

    TreeNode* buildSubTree(vector<int>& preorder, int left, int right) {
        if (left > right) return nullptr;

        int rootVal = preorder[preorderIndex ++];
        TreeNode* root = new TreeNode(rootVal);

        root->left = buildSubTree(preorder, left, inorderIndex[rootVal] - 1);
        root->right = buildSubTree(preorder, inorderIndex[rootVal] + 1, right);

        return root;
    }
};