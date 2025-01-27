class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (auto& edge : edges) {
            dp[edge[0]][edge[1]] = true;
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for(int k = 0; k < n; ++k) {
                    dp[j][k] = dp[j][k] || (dp[j][i] && dp[i][k]);
                }
            }
        }

        vector<bool> ans;
        for (auto q : queries) {
            ans.push_back(dp[q[0]][q[1]]);
        }

        return ans;
    }
};