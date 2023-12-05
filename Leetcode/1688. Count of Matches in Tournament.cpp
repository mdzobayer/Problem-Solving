class Solution {
public:
    int numberOfMatches(int n) {
        if (n < 2) return 0;

        int ans = 0;
        if (n & 1) {
            ans = n / 2;
            ans += numberOfMatches(ans + 1);
        }
        else {
            ans = n / 2;
            ans += numberOfMatches(ans);
        }

        return ans;
    }
};