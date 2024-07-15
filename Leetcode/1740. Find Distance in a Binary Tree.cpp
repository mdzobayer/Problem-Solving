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
    int findDistance(TreeNode* root, int p, int q) {
        unordered_map<int, int> distance;
        int ans = INT_MAX;

        travelCost(root, distance, p);
        findTarget(root, distance, ans, q);

        return ans;
    }

    pair<bool, int> findTarget(TreeNode* root, unordered_map<int, int> & distance, int & ans, int target) {
        if (root == nullptr) return make_pair(false, 0);

        if (root->val == target) {
            if (distance.find(root->val) != distance.end()) {
                ans = min(ans, distance[root->val]);
            }
            return make_pair(true, 0);
        }

        if (root->left != nullptr) {
            pair<bool, int> childInfo = findTarget (root->left, distance, ans, target);
            if (childInfo.first) {
                childInfo.second += 1;
                if (distance.find(root->val) != distance.end()) {
                    ans = min(ans, distance[root->val] + childInfo.second);
                }
                return childInfo;
            }
        }

        if (root->right != nullptr) {
            pair<bool, int> childInfo = findTarget (root->right, distance, ans, target);
            if (childInfo.first) {
                childInfo.second += 1;
                if (distance.find(root->val) != distance.end()) {
                    ans = min(ans, distance[root->val] + childInfo.second);
                }
                return childInfo;
            }
        }

        return make_pair(false, 0);
    }

    pair<bool, int> travelCost(TreeNode* root, unordered_map<int, int> & distance, int target) {
        if (root == nullptr) return make_pair(false, 0);

        if (root->val == target) {
            distance[target] = 0;
            return make_pair(true, 0);
        }

        if (root->left != nullptr) {
            pair<bool, int> childInfo = travelCost (root->left, distance, target);
            if (childInfo.first) {
                childInfo.second += 1;
                distance[root->val] = childInfo.second;
                return childInfo;
            }
        }

        if (root->right != nullptr) {
            pair<bool, int> childInfo = travelCost (root->right, distance, target);
            if (childInfo.first) {
                childInfo.second += 1;
                distance[root->val] = childInfo.second;
                return childInfo;
            }
        }

        return make_pair(false, 0);
    }
};