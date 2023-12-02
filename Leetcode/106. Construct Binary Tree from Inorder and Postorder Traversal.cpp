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
    int postorderIndex;
    map<int, int> inorderIndex;
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); ++i) {
            inorderIndex[inorder[i]] = i;
        }
        postorderIndex = postorder.size() - 1;

        return buildSubTree(postorder, 0, postorderIndex);
    }

    TreeNode* buildSubTree(vector<int>& postorder, int left, int right) {
        if (left > right) return nullptr;

        int roolVal = postorder[postorderIndex];
        TreeNode * root = new TreeNode(roolVal);

        postorderIndex--;
        root->right = buildSubTree(postorder, inorderIndex[roolVal] + 1, right);
        root->left = buildSubTree(postorder, left, inorderIndex[roolVal] - 1);

        return root;
    }
};