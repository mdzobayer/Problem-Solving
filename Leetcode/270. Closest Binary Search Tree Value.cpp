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
    int value = INT_MAX;
    double diff = INT_MAX;
public:
    int closestValue(TreeNode* root, double target) {
        findValue(root, target);

        return value;
    }

    double absD(double value) {
        if (value < 0) {
            value *= -1;
        }

        return value;
    }

    void findValue(TreeNode * root, double target) {
        if (root == nullptr) return;

        double cDiff = absD(target - root->val);
        if (cDiff < diff) {
            diff = cDiff;
            value = root->val;
        }
        else if (cDiff == diff) {
            diff = cDiff;
            value = min(root->val, value);
        }

        if (root->left != nullptr && target < root->val) {
            findValue(root->left, target);
        }

        if (root->right != nullptr && target > root->val) {
            findValue(root->right, target);
        }
    }
};