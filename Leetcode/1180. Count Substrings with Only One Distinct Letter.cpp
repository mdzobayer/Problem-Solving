class Solution {
public:
    int countLetters(string s) {
        int i, cnt = 1, ans = 0, n = s.size();

        for (i = 1; i < n; ++i) {
            if (s[i] != s[i - 1]) {
                ans += numberOfSubsets(cnt);
                cnt = 1;
            }
            else {
                ++ cnt;
            }
        }

        ans += numberOfSubsets(cnt);

        return ans;
    }

    int numberOfSubsets(int n) {
        return ((n * n) + n) / 2;
    }
};