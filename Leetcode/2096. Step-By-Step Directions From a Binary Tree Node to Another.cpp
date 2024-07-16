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
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string startPath, destPath, destinationPath = "";

        findPath(root, startValue, startPath);
        findPath(root, destValue, destPath);

        int i, commonPath = 0;
        while (commonPath < startPath.size() && commonPath < destPath.size()) {
            if (startPath[commonPath] == destPath[commonPath]) {
                ++ commonPath;
            }
            else break;
        }

        for (i = 0; i < startPath.size() - commonPath; ++i) {
            destinationPath += "U";
        }

        for (i = commonPath; i < destPath.size(); ++i) {
            destinationPath += destPath[i];
        }

        return destinationPath;
    }

    bool findPath(TreeNode * root, int target, string & path) {
        if (root == nullptr) return false;

        if (root->val == target) return true;
        // try left
        path += "L";
        if (findPath(root->left, target, path)) {
            return true;
        }
        path.pop_back();

        // try right
        path += "R";
        if (findPath(root->right, target, path)) {
            return true;
        }
        path.pop_back();

        return false;
    }
};