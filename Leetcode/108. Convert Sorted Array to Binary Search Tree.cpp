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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        TreeNode * root = addNode(0, n - 1, nums);

        return root;
    }

    TreeNode * addNode(int left, int right, vector<int>& nums) {
        
        if (left > right) return nullptr;
        
        int mid = (left + right) >> 1; 
        TreeNode * subRoot = new TreeNode(nums[mid]);
        
        subRoot->left = addNode(left, mid - 1, nums);
        subRoot->right = addNode(mid + 1, right, nums);

        return subRoot;
    }
};