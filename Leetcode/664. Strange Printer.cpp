class Solution {
    int n;
    vector< vector<int> > dp;
public:
    int strangePrinter(string s) {
        s = removeConsicutiveDuplicates(s);
        n = s.size();

        dp.resize(n, vector<int>(n, -1));

        return solve(0, n - 1, s);
    }

    int solve(int start, int end, const string& s) {
        if (start > end) return 0;

        if (dp[start][end] != -1) return dp[start][end];

        int minTurns = 1 + solve(start + 1, end, s);

        for (int i = start + 1; i <= end; ++i) {
            if (s[i] == s[start]) {
                int turnWithMatch = solve(start, i - 1, s) + solve(i + 1, end, s);

                minTurns = min(minTurns, turnWithMatch);
            }
        }

        return dp[start][end] = minTurns;
    }

    string removeConsicutiveDuplicates(const string & str) {
        string uniqueChars;

        for(char ch : str) {
            if (uniqueChars.size() == 0 || uniqueChars.back() != ch) {
                uniqueChars.push_back(ch);
            }
        }

        return uniqueChars;
    }
};