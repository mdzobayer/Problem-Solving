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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> rightSide;
        prepareRightSide(root, rightSide);

        return rightSide;
    }

    void prepareRightSide(TreeNode * root, vector<int> & rightSide) {
        if (root == nullptr) return;

        queue<pair<int, TreeNode*>> q;
        q.push(make_pair(0, root));

        pair<int, TreeNode*> queueItem;

        TreeNode * cursor;
        int level;
        
        vector<int> nodes;
        vector<vector<int>> levelsOfNode;

        while(!q.empty()){
            queueItem = q.front();
            q.pop();

            cursor = queueItem.second;
            level = queueItem.first;

            //if (cursor == nullptr) continue;

            if (level >= levelsOfNode.size()){
                levelsOfNode.push_back(nodes);
            }

            levelsOfNode[level].push_back(cursor->val);

            if(cursor->left != nullptr) {
                q.push(make_pair(level + 1, cursor->left));
            }

            if(cursor->right != nullptr) {
                q.push(make_pair(level + 1, cursor->right));
            }
        }

        for (int i = 0; i < levelsOfNode.size(); ++i) {
            rightSide.push_back(levelsOfNode[i].back());
        }
    }
};