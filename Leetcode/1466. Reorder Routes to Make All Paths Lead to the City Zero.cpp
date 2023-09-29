class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        // declartion
        vector<bool> isVisited;
        vector<vector<int>> matrix;
        vector<vector<int>> directedEdges;
        vector<int> vt;
        int i, j, minCost = 0, a, b;

        // reset memory
        for(i = 0; i < n; ++i) {
            matrix.push_back(vt);
            directedEdges.push_back(vt);
            isVisited.push_back(0);
            // for (j = 0; j < n; ++j) 
            //     matrix[i].push_back(0);
        }

        // prepare adjacency matrix
        for (i = 0; i < connections.size(); ++i) {
            a = connections[i][0];
            b = connections[i][1];

            matrix[a].push_back(b);
            matrix[b].push_back(a);

            directedEdges[a].push_back(b);
        }
        int totalReOrder = 0;

        totalReOrder = reOrder(0, isVisited, matrix, directedEdges);

        return totalReOrder;
    }

    int reOrder(int node, vector<bool>& isVisited, vector<vector<int>>& matrix, vector<vector<int>>& directedEdges) {
        isVisited[node] = true;
        int totalReOrder = 0;

        for (int i = 0; i < matrix[node].size(); ++i) {

            if (!isVisited[matrix[node][i]]) {
                totalReOrder += reOrder(matrix[node][i], isVisited, matrix, directedEdges);

                for (int j = 0; j < directedEdges[node].size(); ++j) {
                    if (directedEdges[node][j] == matrix[node][i]) {
                        ++ totalReOrder;
                        break;
                    }
                }
            }
        }

        return totalReOrder;
    }
};