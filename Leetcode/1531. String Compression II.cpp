class Solution {
    int length, dp[101][101], consicutiveLen[101];
    string s;
public:
    int getLengthOfOptimalCompression(string s, int k) {
        this->s = s;
        length = s.size();

        memset(dp, -1, sizeof(dp));

        for (int i = 0; i < 101; ++i) {
            if (i == 0) consicutiveLen[i] = 0;
            else if (i == 1) consicutiveLen[i] = 1;
            else if (i < 10) consicutiveLen[i] = 2;
            else if (i < 100) consicutiveLen[i] = 3;
            else consicutiveLen[i] = 4;
        }

        return solve(0, k);
    }

    int solve(int index, int k) {
        if (index >= length) return (0);

        if ((length - index + 1) < k) return (0);

        if (dp[index][k] != -1) return dp[index][k];

        int i, ch, remainK, len, result = 100000000;
        for (ch = 'a'; ch <= 'z'; ++ch) {
            remainK = k;
            len = 0;
            for (i = index; i < length; ++i) {
                if (s[i] == ch) {
                    ++ len;
                    result = min(result, solve(i + 1, remainK) + consicutiveLen[len]);
                }
                else {
                    --remainK;
                    if (remainK < 0) break; // invalid

                    result = min(result, solve(i + 1, remainK) + consicutiveLen[len]);
                }
            }
        }
        
        return dp[index][k] = result;
    }
};