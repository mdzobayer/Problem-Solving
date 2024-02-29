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
    vector< vector<int> > levelNodes;
    vector<int> emptyRow;
public:
    bool isEvenOddTree(TreeNode* root) {
        storeNode(root, 0);

        int i, j;
        bool even;
        for (i = 0; i < levelNodes.size(); ++i) {
            even = (i % 2) == 0 ? true : false;
            if (levelNodes[i].size() == 1) {
                if (even && levelNodes[i][0] % 2 == 0) return false;
                if (!even && levelNodes[i][0] % 2 != 0) return false;
            }
            for (j = 1; j < levelNodes[i].size(); ++j) {
                if (even) {
                    if (levelNodes[i][j] <= levelNodes[i][j - 1] || levelNodes[i][j] % 2 == 0 || levelNodes[i][j - 1] % 2 == 0) return false;
                }
                else {
                    if (levelNodes[i][j] >= levelNodes[i][j - 1] || levelNodes[i][j] % 2 != 0 || levelNodes[i][j - 1] % 2 != 0) return false;
                }
            }
        }

        return true;
    }

    void storeNode(TreeNode * root, int level) {
        if (root == nullptr) return;

        if (level >= levelNodes.size()) {
            levelNodes.push_back(emptyRow);
        }

        levelNodes[level].push_back(root->val);

        storeNode(root->left, level + 1);
        storeNode(root->right, level + 1);
    }
};