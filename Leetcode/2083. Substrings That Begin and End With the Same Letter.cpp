class Solution {
public:
    long long numberOfSubstrings(string s) {
        vector<int> freq(26, 0);
        int i;
        long long ans = 0;

        for (i = 0; i < s.size(); ++i) {

            freq[s[i] - 'a'] += 1;
            ans += freq[s[i] - 'a'];
        }

        return ans;
    }
};