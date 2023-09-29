class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int i, ans = 0, n = isConnected.size();

        bool isVisited[n + 5];
        memset(isVisited, false, sizeof(isVisited));

        for (i = 0; i < n; ++i) {
            if (isVisited[i] == false) {
                ++ ans;
                markProvince(n, i, isVisited, isConnected);
            }
        }

        return ans;
    }

    void markProvince(int n, int node, bool isVisited[], vector<vector<int>>& isConnected) {
        isVisited[node] = true;

        for (int i = 0; i < n; ++i) {
            if (isConnected[node][i] == 1 && isVisited[i] == false) {
                markProvince(n, i, isVisited, isConnected);
            }
        }
    }
};