class Solution {
    int ringLen;
    vector< vector<int> > dp;
public:
    int findRotateSteps(string ring, string key) {
        ringLen = ring.size();

        dp.resize(ringLen, vector<int>(key.size(), -1));

        return solve(0, 0, ring, key);
    }

    int countSteps(int curr, int next) {
        int stepsBetween = abs(curr - next);
        int stepsAround = ringLen - stepsBetween;
        return min(stepsBetween, stepsAround);
    }

    int solve(int ringIndex, int keyIndex, string & ring, string & key) {
        if (keyIndex == key.size()) return (0);

        if (dp[ringIndex][keyIndex] != -1) return dp[ringIndex][keyIndex];

        int i, ans = INT_MAX;

        for (i = 0; i < ringLen; ++i) {
            if (ring[i] == key[keyIndex]) {
                ans = min(ans, countSteps(ringIndex, i) + 1 + solve(i, keyIndex + 1, ring, key));
            }
        }

        return dp[ringIndex][keyIndex] = ans;
    }
};