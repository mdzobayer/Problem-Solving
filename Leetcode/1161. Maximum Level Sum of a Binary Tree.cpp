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
    int maxLevelSum(TreeNode* root) {
        return prepareMaxLevelSum(root);
    }

    int prepareMaxLevelSum(TreeNode* root) {

        queue<pair<int, TreeNode*>> q;
        pair<int, TreeNode*> queueItem = make_pair(0, root);
        q.push(queueItem);

        int level;
        vector<int> sumOfLevels;

        TreeNode * cursor;

        while(!q.empty()) {
            queueItem = q.front();
            q.pop();

            level = queueItem.first;
            cursor = queueItem.second;

            if (level >= sumOfLevels.size()) {
                sumOfLevels.push_back(0);
            }

            sumOfLevels[level] += cursor->val;

            if (cursor->left != nullptr) {
                q.push(make_pair(level + 1, cursor->left));
            }

            if (cursor->right != nullptr) {
                q.push(make_pair(level + 1, cursor->right));
            }
        }

        int maxSum = sumOfLevels[0];
        int index = 0;
        for (int i = 1; i < sumOfLevels.size(); ++i) {
            if (maxSum < sumOfLevels[i]) {
                maxSum = sumOfLevels[i];
                index = i;
            }
        }

        return index + 1;
    }
};