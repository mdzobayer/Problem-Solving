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
    TreeNode* deleteNode(TreeNode* root, int key) {

        if (root == nullptr) return root;

        if (root->val > key) {
            root->left = deleteNode(root->left, key);
            return root;
        }
        else if (root->val < key) {
            root->right = deleteNode(root->right, key);
            return root;
        }
        
        TreeNode * cursor;

        // If any of the tree is null then return other
        if (root->left == nullptr) {
            cursor = root->right;
            delete root; 
            return cursor;
        }
        else if (root->right == nullptr) {
            cursor = root->left;
            delete root; 
            return cursor;
        }

        TreeNode * successorParent, * successor;

        successorParent = root;
        successor = successorParent->right;

        while(successor->left != nullptr) {
            successorParent = successor;
            successor = successor->left;
        }

        if (successorParent != root) {
            successorParent->left = successor->right;
        }
        else {
            successorParent->right = successor->right;
        }

        root->val = successor->val;

        delete successor;

        return root;
    }
};