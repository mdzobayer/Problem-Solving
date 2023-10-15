class Solution {
    long long int dp[505][505];
public:

    int paintWalls(vector<int>& cost, vector<int>& time) {
        memset(dp, -1, sizeof(dp));
        return solve(0, cost.size(), cost, time);
    }

    long long int solve(int index, int remain, vector<int>& cost, vector<int>& time) {
        if (remain <= 0) {
            return (0);
        }

        if (index >= cost.size()) return INT_MAX;

        if (dp[index][remain] != -1) return dp[index][remain];

        long long int ans = solve(index + 1, remain - time[index] - 1, cost, time) + cost[index];
        ans = min(ans, solve(index + 1, remain, cost, time));

        return dp[index][remain] = ans;
    }
};

