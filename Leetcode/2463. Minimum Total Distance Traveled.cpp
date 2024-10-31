class Solution {
    vector< vector<long long> > dp;
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        int i, j, ans = 0;

        vector<int> factoryPositions;
        for (auto& f : factory) {
            for (i = 0; i < f[1]; ++i) {
                factoryPositions.push_back(f[0]);
            }
        }

        int robotCount = robot.size(), factoryCount = factoryPositions.size();
        dp.resize(robotCount, vector<long long>(factoryCount, -1));

        return solve(0, 0, robot, factoryPositions);
    }

    long long solve(int robotIdx, int factoryIdx, vector<int>& robot, vector<int>& factoryPositions) {
        if (robotIdx == robot.size()) return 0;

        if (factoryIdx == factoryPositions.size()) return 1e12;

        if (dp[robotIdx][factoryIdx] != -1) return dp[robotIdx][factoryIdx];

        long long assign = abs(robot[robotIdx] - factoryPositions[factoryIdx]) + solve(robotIdx + 1, factoryIdx + 1, robot, factoryPositions);

        long long skip = solve(robotIdx, factoryIdx + 1, robot, factoryPositions);

        return dp[robotIdx][factoryIdx] = min(assign, skip);
    }
};