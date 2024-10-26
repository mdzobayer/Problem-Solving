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
    vector<int> maxHeightAfterRemoval;
    int currentMaxHeight = 0;
public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        maxHeightAfterRemoval.resize(100001);

        traverseLeftToRight(root, 0);
        currentMaxHeight = 0;
        traverseRightToLeft(root, 0);

        int i = 0;
        vector<int> ans(queries.size());
        for (int query : queries) {
            ans[i++] = maxHeightAfterRemoval[query];
        }

        return ans;
    }

    void traverseLeftToRight(TreeNode * node, int currentHeight) {
        if (node == nullptr) {
            return;
        }

        maxHeightAfterRemoval[node->val] = currentMaxHeight;

        currentMaxHeight = max(currentMaxHeight, currentHeight);

        traverseLeftToRight(node->left, currentHeight + 1);
        traverseLeftToRight(node->right, currentHeight + 1);
    }

    void traverseRightToLeft(TreeNode * node, int currentHeight) {
        if (node == nullptr) {
            return;
        }

        maxHeightAfterRemoval[node->val] = max(maxHeightAfterRemoval[node->val], currentMaxHeight);

        currentMaxHeight = max(currentMaxHeight, currentHeight);

        traverseRightToLeft(node->right, currentHeight + 1);
        traverseRightToLeft(node->left, currentHeight + 1);
    }
};