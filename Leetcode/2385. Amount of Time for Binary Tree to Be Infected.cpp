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
    vector<int> ajList[100001];

public:

    int bfs(int start) {

        vector<bool> visited(100001, false);

        queue<pair<int,int>> q;
        q.push(make_pair(start, 0));
        visited[start] = true;

        int nextNode, ans = 0;

        while(!q.empty()) {
            pair<int, int> node = q.front();
            q.pop();

            ans = max(ans, node.second);

            for (int i = 0; i < ajList[node.first].size(); ++i) {
                nextNode = ajList[node.first][i];
                if (!visited[nextNode]) {
                    q.push(make_pair(nextNode, node.second + 1));
                    visited[nextNode] = true;
                }
            }
        }

        return ans;
    }

    void prepareAjList(TreeNode * root) {
        if (root == nullptr) return;

        if (root->left != nullptr) {
            ajList[root->val].push_back(root->left->val);
            ajList[root->left->val].push_back(root->val);
            prepareAjList(root->left);
        }

        if (root->right != nullptr) {
            ajList[root->val].push_back(root->right->val);
            ajList[root->right->val].push_back(root->val);
            prepareAjList(root->right);
        }
    }

    int amountOfTime(TreeNode* root, int start) {
        
        prepareAjList(root);

        return bfs(start);
    }

};