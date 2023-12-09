class Solution {
    string s1, s2, s3;
    int dp[101][101][202];
public:
    bool isInterleave(string s1, string s2, string s3) {
        this->s1 = s1;
        this->s2 = s2;
        this->s3 = s3;

        if (s1.size() + s2.size() != s3.size()) return false;

        memset(dp, -1, sizeof(dp));

        return isInterLeave((int)s1.size() - 1, (int)s2.size() - 1, (int)s3.size() - 1);
    }

    bool isInterLeave(int x, int y, int z) {
        if (x < 0 && y < 0 && z < 0) return true;
        if (x < 0 && y < 0) return false;

        if (dp[x + 1][y + 1][z + 1] != -1) return dp[x + 1][y + 1][z + 1];

        bool ans = false;
        if (x >= 0) {
            if (s1[x] == s3[z]) {
                ans = isInterLeave(x - 1, y, z - 1);
            }
        }

        if (y >= 0 && !ans) {
            if (s2[y] == s3[z]) {
                ans = isInterLeave(x, y - 1, z - 1);
            }
        }

        return dp[x + 1][y + 1][z + 1] = ans;
    }
};