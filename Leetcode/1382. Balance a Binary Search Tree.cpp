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
    vector<int> list;
public:
    TreeNode* balanceBST(TreeNode* root) {
        inorderTraverse(root);

        return createBST(0, list.size() - 1);
    }

    void inorderTraverse(TreeNode* root) {
        if (root == nullptr) return;

        inorderTraverse(root->left);
        list.push_back(root->val);
        inorderTraverse(root->right);
    }

    TreeNode * createBST(int start, int end) {
        if (start > end) return nullptr;

        int mid = (start + end) / 2;

        TreeNode * node = new TreeNode(list[mid]);
        node->left = createBST(start, mid - 1);
        node->right = createBST(mid + 1, end);

        return node;
    }
};