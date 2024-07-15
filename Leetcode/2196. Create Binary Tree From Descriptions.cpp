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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode *> locations;
        unordered_map<int, int> parents;
        int i, n = descriptions.size();

        TreeNode * newNode, * root = nullptr;

        // Prepare all node
        for (i = 0; i < n; ++i) {
            newNode = new TreeNode(descriptions[i][1]);
            locations[descriptions[i][1]] = newNode;
            parents[descriptions[i][1]] = descriptions[i][0];

            if (locations.find(descriptions[i][0]) == locations.end()) {
                newNode = new TreeNode(descriptions[i][0]);
                locations[descriptions[i][0]] = newNode;
                parents[descriptions[i][0]] = descriptions[i][0];
            }
        }

        // make relation with parent
        for (i = 0; i < n; ++i) {
            TreeNode * parent = locations[descriptions[i][0]];
            TreeNode * child = locations[descriptions[i][1]];

            if (descriptions[i][2] == 1) {
                parent->left = child;
            }
            else {
                parent->right = child;
            }
            
        }

        int parentValue = descriptions[0][0];
        while(parents[parentValue] != parentValue) {
            parentValue = parents[parentValue];
        }

        root = locations[parentValue];

        return root;
    }
};