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
    vector<int> leaf1, leaf2;
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        
        findLeafNodes(root1, true);
        findLeafNodes(root2, false);

        bool found = true;
        if (leaf1.size() != leaf2.size()) return false;

        for (int i = 0; i < leaf1.size(); ++i) {
            if (leaf1[i] != leaf2[i]) {
                found = false;
                break;
            }
        }

        return found;
    }

    void findLeafNodes(TreeNode* cursor, bool one){ 
        if (cursor == nullptr) return;

        if (cursor->left != nullptr) {
            findLeafNodes(cursor->left, one);
        }
        
        if (cursor->right != nullptr) {
            findLeafNodes(cursor->right, one);
        }

        if (cursor->left == nullptr && cursor->right == nullptr) {
            if (one) {
                leaf1.push_back(cursor->val);
            }
            else {
                leaf2.push_back(cursor->val);
            }
        }
    }
};