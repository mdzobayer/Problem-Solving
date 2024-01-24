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
    int ans;

    bool palindromePossible(vector<int>& counts) {
        int i, oddCount = 0;
        for (i = 0; i < 10; ++i) {
            if (counts[i] & 1) ++oddCount;
        }

        if (oddCount > 1) return false;
        return true;
    }

    void solve(TreeNode* root, vector<int>& counts) {
        counts[root->val] += 1;

        if (root->left == nullptr && root->right == nullptr) {
            if (palindromePossible(counts)) ++ ans;

            counts[root->val] -= 1;
            return;
        }

        if (root->left != nullptr) {
            solve(root->left, counts);
        }

        if (root->right != nullptr) {
            solve(root->right, counts);
        }

        counts[root->val] -= 1;
    }

    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> counts(10, 0);
        ans = 0;

        if (root != nullptr) {
            solve(root, counts);
        }
        
        return ans;
    }

    
};