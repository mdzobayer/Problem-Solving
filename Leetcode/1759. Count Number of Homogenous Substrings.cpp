class Solution {
    int mod = 1e9 + 7;
public:
    int countHomogenous(string s) {
        long long int ans = 0;
        int i, count = 1;

        for (i = 1; i < s.size(); ++i) {
            if (s[i] == s[i - 1]) {
                ++count;
            }
            else {
                ans += (numberOfSubStrings(count) % mod);
                ans %= mod;
                count = 1;
            }
        }

        ans += (numberOfSubStrings(count) % mod);
        ans %= mod;

        return ans;
    }

    long long int numberOfSubStrings(int x) {
        if (x == 1) return x;

        return ((long long int)x*x + x) / 2;
    }
};