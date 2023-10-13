class Solution {
    int dp[1000+5];
public:
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp, -1, sizeof(dp));

        return min(solve(0, cost), solve(1, cost));
    }

    int solve(int index, vector<int>& cost) {
        if (index >= cost.size()) return (0);

        if(dp[index] != -1) return dp[index];

        int ans = min(solve(index + 1, cost), solve(index + 2, cost));

        ans += cost[index];

        return dp[index] = ans;
    }
};