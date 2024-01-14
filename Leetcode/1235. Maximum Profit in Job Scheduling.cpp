class Solution {
    int dp[50001];
    int n;
    vector< vector<int> > schedules;
    vector<int> start;
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int i, j;
        n = startTime.size();

        memset(dp, -1, sizeof(dp));

        for (i = 0; i < n; ++i) {
            schedules.push_back({startTime[i], endTime[i], profit[i]});
        }
        
        sort(schedules.begin(), schedules.end());

        // binary search will be used in startTime so store it as separate list
        for (int i = 0; i < n; i++) {
            start.push_back(schedules[i][0]);
        }


        return solve(0);
    }

    int solve(int pos) {
        if (pos == n) return (0);

        if (dp[pos] != -1) return dp[pos];

        int nextIndex = lower_bound(start.begin(), start.end(), schedules[pos][1]) - start.begin();

        return dp[pos] = max(solve(pos + 1), 
                        schedules[pos][2] + solve(nextIndex));
    }
};