class Solution {
    int dp[15][10000 + 5];
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        reverse(coins.begin(), coins.end());

        memset(dp, -1, sizeof(dp));

        if (solve(0, amount, coins) >= INT_MAX) return -1;

        return solve(0, amount, coins);
    }

    long long int solve(int index, int amount, vector<int>& coins) {
        if (amount == 0) return 0;
        if (amount < 0 || index >= coins.size()) return INT_MAX;

        if (dp[index][amount] != -1) return dp[index][amount];

        long long int ans = solve(index, amount - coins[index], coins) + 1;
        ans = min(ans, solve(index + 1, amount, coins));
        
        if (ans > INT_MAX) ans = INT_MAX;

        return dp[index][amount] = ans;
    }
};