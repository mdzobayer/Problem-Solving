class Solution {
    map<int, vector<int>> validFollower;
    int mod = 1e9 + 7;
    int dp[20000+5][28];
public:
    int countVowelPermutation(int n) {
        setFollower();
        memset(dp, -1, sizeof(dp));

        int ans = 0;
        for (auto it = validFollower.begin(); it != validFollower.end(); ++it) {
            ans += solve(n - 1, it->first);
            ans %= mod;
        }

        return ans;
    }

    int solve(int n, int last) {
        if (n == 0) return 1;

        if (dp[n][last - 'a'] != -1) return dp[n][last - 'a'];

        int ans = 0;
        vector<int> followers = validFollower[last];
        for (int i = 0; i < followers.size(); ++i) {
            ans += solve(n - 1, followers[i]);
            ans %= mod;
        }

        return dp[n][last - 'a'] = ans;
    }

    void setFollower() {
        vector<int> followerA{(int)'e'};
        validFollower['a'] = followerA;

        vector<int> followerE{(int)'a', (int)'i'};
        validFollower['e'] = followerE;

        vector<int> followerI{(int)'a', (int)'e', (int)'o', (int)'u'};
        validFollower['i'] = followerI;

        vector<int> followerO{(int)'i', (int)'u'};
        validFollower['o'] = followerO;

        vector<int> followerU{(int)'a'};
        validFollower['u'] = followerU;
    }
};