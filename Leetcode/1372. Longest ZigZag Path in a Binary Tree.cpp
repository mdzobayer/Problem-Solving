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

    int longZigZag;
    int longestZigZag(TreeNode* root) {
        longZigZag = 0;

        findLongZigZag(root, -1, 0);
        findLongZigZag(root, 1, 0);

        if (longZigZag > 0) --longZigZag;

        return longZigZag;
    }

    void findLongZigZag(TreeNode * cursor, int direction, int count) {
        if (cursor == nullptr) return;

        ++count;
        longZigZag = max(longZigZag, count);

        if (direction == -1) {
            findLongZigZag(cursor->right, 1, count);
            findLongZigZag(cursor->left, -1, 1);
        }
        else if (direction == 1) {
            findLongZigZag(cursor->left, -1, count);
            findLongZigZag(cursor->right, 1, 1);
        }
        
    }
};