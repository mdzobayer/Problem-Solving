/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1, path2;

        findNode(path1, root, p);
        findNode(path2, root, q);

        int minLength = min(path1.size(), path2.size());

        TreeNode * lcaNode = root;
        for (int i = 1; i < minLength; ++i) {
            if (path1[i] == path2[i]) {
                lcaNode = path1[i];
            }
            else break;
        }

        return lcaNode;
    }

    bool findNode(vector<TreeNode*> &path, TreeNode * root, TreeNode * target) {
        if (root == nullptr) return false;

        path.push_back(root);
        if (root->val == target->val) return true;

        
        bool ans = findNode(path, root->left, target) || findNode(path, root->right, target);
        if (!ans) path.pop_back();

        return ans;
    }
};