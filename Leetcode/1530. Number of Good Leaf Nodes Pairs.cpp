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
    int countPairs(TreeNode* root, int distance) {
        unordered_map<TreeNode *, vector<TreeNode *>> graph;
        unordered_set<TreeNode *> leafNodes;
        int ans = 0;

        traverseTree(root, nullptr, graph, leafNodes);

        for (TreeNode * leaf : leafNodes) {
            queue<pair<TreeNode *, int>> queue;
            unordered_set<TreeNode *> seen;
            queue.push({leaf, 0});
            seen.insert(leaf);

            while(!queue.empty()) {
                pair<TreeNode *, int> currPair = queue.front();
                queue.pop();

                TreeNode * currNode = currPair.first;

                if (currNode != leaf && leafNodes.count(currNode)) {
                    ++ ans;
                    
                }
                if (currPair.second >= distance) continue;

                for (TreeNode * connectedNode : graph[currNode]) {
                    if (seen.find(connectedNode) != seen.end()) continue;

                    queue.push({connectedNode, currPair.second + 1});
                    seen.insert(connectedNode);
                }
            }
        }

        return ans / 2;
    }

    void traverseTree(TreeNode * currNode, TreeNode * prevNode, unordered_map<TreeNode *, vector<TreeNode *>> & graph, unordered_set<TreeNode *> & leafNodes) {

        if (currNode == nullptr) return;

        if (prevNode != nullptr) {
            graph[currNode].push_back(prevNode);
            graph[prevNode].push_back(currNode);
        }

        if (currNode->left == nullptr && currNode->right == nullptr) {
            leafNodes.insert(currNode);
        }

        traverseTree(currNode->left, currNode, graph, leafNodes);
        traverseTree(currNode->right, currNode, graph, leafNodes);
    }
};