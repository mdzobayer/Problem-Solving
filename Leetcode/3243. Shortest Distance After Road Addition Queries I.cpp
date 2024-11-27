class Solution {
public:
    int findMinimumDistance(vector<vector<int>>& adjList, int n, int currentNode, vector<int>& dp) {
        if (currentNode == n - 1) return 0;
        if (dp[currentNode] != -1) return dp[currentNode];

        int minDistance = n;

        for (int neighbor : adjList[currentNode]) {
            minDistance = min(minDistance, findMinimumDistance(adjList, n, neighbor, dp) + 1);
        }

        return dp[currentNode] = minDistance;
    }

    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> dp(n, -1);
        vector< vector<int> > adjList(n, vector<int>(0));
        int i, u, v;

        for (i = 0; i < n - 1; ++i) {
            adjList[i].push_back(i + 1);
        }

        vector<int> ans;

        for (auto & edge : queries) {
            u = edge[0];
            v = edge[1];

            adjList[u].push_back(v);
            ans.push_back(findMinimumDistance(adjList, n, 0, dp));

            dp.clear();
            dp.resize(n, -1);
        }

        return ans;
    }
};