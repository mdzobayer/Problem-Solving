/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {

        if (node == nullptr) return node;
        
        map<int, vector<int> > connectedNodes;
        vector<bool> visited(105, false);
        int i;

        Node* cursor, * nextCursor;
        queue<Node*> q;
        q.push(node);
        visited[node->val] = true;

        while(!q.empty()) {
            cursor = q.front();
            q.pop();
            
            vector<int> neighborsVal;

            vector<Node*> neighbors = cursor->neighbors;

            for (i = 0; i < neighbors.size(); ++i) {
                nextCursor = neighbors[i];
                if (!visited[nextCursor->val]) {
                    visited[nextCursor->val] = true;
                    q.push(nextCursor);
                }

                neighborsVal.push_back(nextCursor->val);
            }

            connectedNodes.insert({cursor->val, neighborsVal});
        }

        map<int, Node *> newGraphNodes;
        for (auto it = connectedNodes.begin(); it != connectedNodes.end(); ++it) {
            cursor = new Node(it->first);
            newGraphNodes.insert({it->first, cursor});
        }

        for (auto it = connectedNodes.begin(); it != connectedNodes.end(); ++it) {
            int key = it->first;
            vector<int> connected = it->second;
            
            cursor = newGraphNodes[key];
            for (i = 0; i < connected.size(); ++i) {
                cursor->neighbors.push_back(newGraphNodes[connected[i]]);
            }
        }

        return newGraphNodes[node->val];
    }
};