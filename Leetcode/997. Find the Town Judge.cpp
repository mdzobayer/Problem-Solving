class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int ans, i;
        vector<bool> haveTrust(10001, false);
        vector<int> trustCount(10001, 0);

        for (i = 0; i < trust.size(); ++i) {
            trustCount[trust[i][1]] += 1;
            haveTrust[trust[i][0]] = true;
        }

        ans = -1;

        for (i = 1; i <= n; ++i) {
            if (trustCount[i] == n - 1 && !haveTrust[i]) {
                ans = i;
                break;
            }
        }

        return ans;
    }
};