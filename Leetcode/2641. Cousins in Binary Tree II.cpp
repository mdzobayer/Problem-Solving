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
    vector<long long> levelSum;
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        levelSum.resize(100001, 0);

        traverse(root, 0);
        replaceValue(root, 0, 0);

        return root;
    }

    void replaceValue(TreeNode * root, int siblingSum, int level) {
        if (root == nullptr) return;

        int leftChild = root->left == nullptr ? 0 : root->left->val;
        int rightChild = root->right == nullptr ? 0 : root->right->val;

        if (level == 0 || level == 1) {
            root->val = 0;
        }
        else {
            root->val = levelSum[level] - root->val - siblingSum;
        }

        replaceValue(root->left, rightChild, level + 1);
        replaceValue(root->right, leftChild, level + 1);
    }

    void traverse(TreeNode* root, int level) {
        levelSum[level] += root->val;

        if (root->left != nullptr) {
            traverse(root->left, level + 1);
        }

        if (root->right != nullptr) {
            traverse(root->right, level + 1);
        }
    }
};