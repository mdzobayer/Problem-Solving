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
    vector< stack<int> > levels;
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        travers(root, 0);
        replaceValue(root, 0);

        return root;
    }

    void replaceValue(TreeNode* root, int level) {
        if (root == nullptr) return;

        if (level % 2 == 1) {
            root->val = levels[level].top();
            levels[level].pop();
        }

        replaceValue(root->left, level + 1);
        replaceValue(root->right, level + 1);
    }

    void travers(TreeNode* root, int level) {
        if (root == nullptr) return;

        if (levels.size() <= level) {
            levels.push_back(stack<int>());
        }
        if (level % 2 == 1) {
            levels[level].push(root->val);
        }
        

        travers(root->left, level + 1);
        travers(root->right, level + 1);
    }
};