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
    map<TreeNode*, vector<int>> subTreeInfo;
public:
    int averageOfSubtree(TreeNode* root) {
        int count = 0;

        countSubTree(root);
        sumOfSubTree(root);

        map<TreeNode*, vector<int>>::iterator it;
        for (it = subTreeInfo.begin(); it != subTreeInfo.end(); ++it) {
            vector<int> nodeInfo = it->second;
            if (nodeInfo[0] == floor((double) nodeInfo[2] / nodeInfo[1])) {
                ++ count;
            }
        }

        return count;
    }

    int sumOfSubTree(TreeNode* root) {
        if (root == nullptr) return (0);

        int ans = sumOfSubTree(root->left) + sumOfSubTree(root->right) + root->val;
        subTreeInfo[root][2] = ans;

        return ans;
    }

    int countSubTree(TreeNode* root) {
        if (root == nullptr) return (0);

        vector<int> info(3, 0);

        info[0] = root->val;
        info[1] = countSubTree(root->left) + countSubTree(root->right) + 1;
        subTreeInfo[root] = info;

        return info[1];
    }
};