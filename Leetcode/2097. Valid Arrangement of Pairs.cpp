class Solution {
    unordered_map<int, deque<int>> adjacencyMatrix;
    unordered_map<int, int> inDegree, outDegree;
    vector<int> result;
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        
        int start, end;

        for (const vector<int>& pair : pairs) {
            start = pair[0]; end = pair[1];
            adjacencyMatrix[start].push_back(end);
            ++outDegree[start];
            ++inDegree[end];
        }

        int startNode = -1;
        for (const auto& entry : outDegree) {
            int node = entry.first;
            if (outDegree[node] == inDegree[node] + 1) {
                startNode = node;
                break;
            }
        }

        if (startNode == -1) {
            startNode = pairs[0][0];
        }

        function<void(int)> visit = [&](int node) {
            while (!adjacencyMatrix[node].empty()) {
                int nextNode = adjacencyMatrix[node].front();
                adjacencyMatrix[node].pop_front();
                visit(nextNode);
            }
            result.push_back(node);
        };

        visit(startNode);
        reverse(result.begin(), result.end());

        vector< vector<int> > pairedResult;
        for (int i = 1; i < result.size(); ++i) {
            pairedResult.push_back({result[i - 1], result[i]});
        }

        return pairedResult;
    }
    

    void visit(int node) {
        while(!adjacencyMatrix[node].empty()) {
            int nextNode = adjacencyMatrix[node].front();
            adjacencyMatrix[node].pop_front();
            visit(nextNode);
        }
        result.push_back(node);
    }
};