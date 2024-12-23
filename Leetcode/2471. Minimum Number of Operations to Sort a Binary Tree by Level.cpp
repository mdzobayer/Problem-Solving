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
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> queue;
        queue.push(root);
        int i, totalSwaps = 0;

        while(!queue.empty()) {
            int levelSize = queue.size();
            vector<int> levelValues(levelSize);

            for (i = 0; i < levelSize; ++i) {
                TreeNode * node = queue.front();
                queue.pop();
                levelValues[i] = node->val;

                if (node->left != nullptr) queue.push(node->left);
                if (node->right != nullptr) queue.push(node->right);
            }

            totalSwaps += getMinSwaps(levelValues);
        }

        return totalSwaps;
    }

    int getMinSwaps(vector<int>& original) {
        int i, swaps = 0;
        vector<int> target(original.begin(), original.end());
        sort(target.begin(), target.end());

        unordered_map<int, int> hashMap;
        for (i = 0; i < original.size(); ++i) {
            hashMap[original[i]] = i;
        }

        for (i = 0; i < original.size(); ++i) {
            if (original[i] != target[i]) {
                ++swaps;

                int curPos = hashMap[target[i]];
                hashMap[original[i]] = curPos;
                swap(original[curPos], original[i]);
            }
        }

        return swaps;
    }
};