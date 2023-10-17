class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {

        vector<bool> visited(n, false);
        vector<int> parents(n, -1);
        bool ans = true;

        //set<int> st;

        // Search parent node
        for (int i = 0; i < n; ++i) {
            if (leftChild[i] > -1) {
                if(parents[leftChild[i]] > -1)
                    return false;

                parents[leftChild[i]] = i;
            }
            if (rightChild[i] > -1) {
                if (parents[rightChild[i]] > -1)
                    return false;
                
                parents[rightChild[i]] = i;
            }
            
        }

        // search root
        int root = findRoot(parents, 0);
        if (root > -1) {
            ans = dfs(root, leftChild, rightChild, visited);
        }
        else {
            ans = false;
        }

        for (int i = 1; i < n && ans; ++i) {
            if (!visited[i]) {
                ans = false;
                break;
            }
        }

        return ans;
    }

    int findRoot(vector<int> & parents, int node) {
        vector<bool> visitedParent(parents.size(), false);
        //visitedParent[node] = true;

        while (parents[node] != -1) {
            visitedParent[node] = true;
            
            node = parents[node];
            if (visitedParent[node]) return -1;
        }

        return node;
    }

    bool dfs(int node, vector<int>& leftChild, vector<int>& rightChild, vector<bool>& visited) {
        visited[node] = true;

        bool isValid = true;

        if (leftChild[node] > -1) {
            if (visited[leftChild[node]]) {
                isValid = false;
            }
            else {
                isValid = dfs(leftChild[node], leftChild, rightChild, visited);
            }
        }

        if (!isValid) return isValid;

        if (rightChild[node] > -1) {
            if (visited[rightChild[node]]) {
                isValid =  false;
            }
            else {
                isValid = dfs(rightChild[node], leftChild, rightChild, visited);
            }
        }

        return isValid;
    }
};