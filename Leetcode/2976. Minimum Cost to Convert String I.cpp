// Floyd Warshall Algorithm / All Pair shortest path
class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector< vector<long long> > shortestPath(26, vector<long long>(26, INT_MAX));

        int i;
        char start, end;
        long long ans = 0;

        for (i = 0; i < original.size(); ++i) {
            start = original[i] - 'a';
            end = changed[i] - 'a';

            shortestPath[start][end] = min(shortestPath[start][end], (long long)cost[i]);
        }

        // find all pair shortest path
        floydWarshall(shortestPath);

        for (i = 0; i < source.size(); ++i) {
            if (source[i] == target[i]) continue;

            start = source[i] - 'a';
            end = target[i] - 'a';

            if (shortestPath[start][end] == INT_MAX) return -1;

            ans += shortestPath[start][end];
        }

        return ans;
    }

    void floydWarshall(vector< vector<long long> > & pathCost) {
        int i, j, k;

        for (i = 0; i < 26; ++i) {
            for (j = 0; j < 26; ++j) {
                for (k = 0; k < 26; ++k) {
                    pathCost[k][j] = min(pathCost[k][j], pathCost[k][i] + pathCost[i][j]);
                }
            }
        }
    }
};