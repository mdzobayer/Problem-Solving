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
public:
    void flatten(TreeNode* root) {
        list<TreeNode *> preOrderList;

        preOrderTraverse(root, preOrderList);

        if (preOrderList.size() == 0 || preOrderList.size() == 1) return;

        list<TreeNode *>::iterator it, preIt = preOrderList.begin();
        it = preIt;

        TreeNode* cursor;

        for (++it; it != preOrderList.end(); preIt = it, ++it) {
            cursor = *preIt;
            cursor->left = nullptr;
            cursor->right = *it;
        }

        return;
    }

    void preOrderTraverse(TreeNode * root, list<TreeNode *>& preOrderList) {
        if (root == nullptr) return;

        preOrderList.push_back(root);

        preOrderTraverse(root->left, preOrderList);
        preOrderTraverse(root->right, preOrderList);
    }
};