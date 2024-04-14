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
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        if (root1 == nullptr || root2 == nullptr) return false;

        if(findTarget(root2, target - root1->val)) return true;

        if (twoSumBSTs(root1->left, root2, target)) return true;

        return twoSumBSTs(root1->right, root2, target);
    }

    bool findTarget(TreeNode * root, int target) {
        if (root == nullptr) return false;

        if (root->val == target) return true;
        else if (root->val > target) return findTarget(root->left, target);
        
        return findTarget(root->right, target);
    }
};