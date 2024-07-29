class Solution {
    int n;
public:
    int numTeams(vector<int>& rating) {
        int i, ans = 0;
        n = rating.size();

        vector< vector<int> > increasingDp(n, vector<int>(4, -1)), decreasingDp(n, vector<int>(4, -1));

        for (i = 0; i < n; ++i) {
            ans += solve(i, 1, rating, increasingDp, true) + solve(i, 1, rating, decreasingDp, false);
        }

        return ans;
    }

    int solve(int index, int members, vector<int>& rating, vector< vector<int> > & dp, bool isIncreasing) {
        if (index == n) return 0;

        if (members == 3) return 1;

        // Increasing block
        if (isIncreasing) {
            if (dp[index][members] != -1) return dp[index][members];
            int i, ans = 0;
            for (int i = index + 1; i < n; ++i) {
                if (rating[i] > rating[index]) {
                    ans += solve(i, members + 1, rating, dp, isIncreasing);
                }
            }

            return dp[index][members] = ans;
        }

        // Decreasing block
        if (dp[index][members] != -1) return dp[index][members];
        int i, ans = 0;
        for (int i = index + 1; i < n; ++i) {
            if (rating[i] < rating[index]) {
                ans += solve(i, members + 1, rating, dp, isIncreasing);
            }
        }

        return dp[index][members] = ans;
    }
};