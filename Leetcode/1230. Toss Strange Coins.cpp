class Solution {
    vector< vector<double> > dp;
    int n;
public:
    double probabilityOfHeads(vector<double>& prob, int target) {
        n = prob.size();
        dp.resize(n, vector<double>(target + 1, -1));

        return solve(0, target, prob);
    }

    double solve(int index, int target, vector<double>& prob) {
        if (index == n) return target == 0 ? 1 : 0;

        if (target < 0) return 0;

        if (dp[index][target] != -1) return dp[index][target];

        dp[index][target] = (solve(index + 1, target - 1, prob) * prob[index]) + (solve(index + 1, target, prob) * (1 - prob[index]));

        return dp[index][target];
    }
};