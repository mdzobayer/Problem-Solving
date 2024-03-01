class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int i, ones = 0, zeros = 0, n = s.size();

        for (i = 0; i < n; ++i) {
            if (s[i] == '1') ++ ones;
            else ++ zeros;
        }

        string ans = "";
        for (i = 1; i < ones; ++i) {
            ans += '1';
        }
        for (i = 0; i < zeros; ++i) {
            ans += '0';
        }

        ans += '1';

        return ans;
    }
};