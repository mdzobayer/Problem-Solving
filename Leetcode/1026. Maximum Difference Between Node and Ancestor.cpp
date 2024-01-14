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
    int ans;
public:
    int maxAncestorDiff(TreeNode* root) {
        ans = 0;

        findMaxMin(root);

        return ans;
    }

    pair<int, int> findMaxMin(TreeNode * root) {
        //if (root == nullptr) return make_pair(0, 100000);

        pair<int, int> value, leftTree, rightTree;
        value.first = root->val;
        value.second = root->val;

        if (root->left != nullptr) {
            leftTree = findMaxMin(root->left);
            value.first = max(value.first, leftTree.first);
            value.second = min(value.second, leftTree.second);

            ans = max(ans, abs(root->val - leftTree.first));
            ans = max(ans, abs(root->val - leftTree.second));
        }
        
        if (root->right != nullptr) {
            rightTree = findMaxMin(root->right);
            value.first = max(value.first, rightTree.first);
            value.second = min(value.second, rightTree.second);

            ans = max(ans, abs(root->val - rightTree.first));
            ans = max(ans, abs(root->val - rightTree.second));
        }

        return value;
    }
};