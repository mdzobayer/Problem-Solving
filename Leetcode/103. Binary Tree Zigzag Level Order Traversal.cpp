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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> zigzag;

        traverse(root, 0, zigzag);

        for (int i = 0; i < zigzag.size(); ++i) {
            if (i % 2 != 0) {
                reverse(zigzag[i].begin(),zigzag[i].end());
            }
        }

        return zigzag;
    }

    void traverse(TreeNode * root, int level, vector<vector<int>> & zigzag) {
        if (root == nullptr) return;

        if (level >= zigzag.size()) {
            vector<int> aList;
            zigzag.push_back(aList);
        }

        zigzag[level].push_back(root->val);

        traverse(root->left, level + 1, zigzag);
        traverse(root->right, level + 1, zigzag);
    }
};