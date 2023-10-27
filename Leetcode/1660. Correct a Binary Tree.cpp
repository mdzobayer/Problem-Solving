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
    map<TreeNode *, TreeNode *> parent;
public:
    TreeNode* correctBinaryTree(TreeNode* root) {

        // if (root->left != nullptr) {
        //     parent[root->left] = root;
        // }

        // if (root->right != nullptr) {
        //     parent[root->right] = root;
        // }

        TreeNode * invalidNode = findInvalidNode(root);

        TreeNode * newRoot = MakeCopy(root, invalidNode);

        return newRoot;
    }

    TreeNode * MakeCopy(TreeNode * root, TreeNode * invalid) {
        if (root == nullptr) return nullptr;

        TreeNode * cursor = new TreeNode(root->val);

        if (root->left != invalid)
            cursor->left = MakeCopy(root->left, invalid);
        if (root->right != invalid)
            cursor->right = MakeCopy(root->right, invalid);

        return cursor;
    }


    TreeNode * findInvalidNode(TreeNode * root) {
        if (root == nullptr) return root;

        if (root->left != nullptr) {
            if (parent.find(root->left) != parent.end()) {
                return parent[root->left];
            }

            parent[root->left] = root;
        }

        TreeNode * cursor = findInvalidNode(root->left);
        if (cursor != nullptr) return cursor;


        if (root->right != nullptr) {
            if (parent.find(root->right) != parent.end()) {
                return parent[root->right];
            }

            parent[root->right] = root;
        }

        return findInvalidNode(root->right);
    }

};