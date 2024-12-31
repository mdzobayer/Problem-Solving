class Solution {
    unordered_set<int> isTravelNeeded;
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int lastDay = days.back();
        vector<int> dp(lastDay + 1, -1);

        for (int day : days) {
            isTravelNeeded.insert(day);
        }

        return solve(dp, days, costs, 1);
    }

    int solve(vector<int>& dp, vector<int>& days, vector<int>& costs, int day) {
        if (day > days[days.size() - 1]) {
            return 0;
        }

        if (isTravelNeeded.find(day) == isTravelNeeded.end()) {
            return solve(dp, days, costs, day + 1);
        }

        if (dp[day] != -1) return dp[day];

        int oneDay = costs[0] + solve(dp, days, costs, day + 1);
        int sevenDay = costs[1] + solve(dp, days, costs, day + 7);
        int thirtyDay = costs[2] + solve(dp, days, costs, day + 30);

        return dp[day] = min(oneDay, min(sevenDay, thirtyDay));
    }
};