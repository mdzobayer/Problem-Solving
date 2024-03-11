class Solution {
public:
    string customSortString(string order, string s) {
        int i, j, n = s.size();
        string ans = "";
        vector<int> taken(26, 0);

        for (i = 0; i < n; ++i) {
            ++ taken[s[i] - 'a'];
        }

        for (i = 0; i < order.size(); ++i) {
            while(taken[order[i] - 'a'] > 0) {
                ans += order[i];
                -- taken[order[i] - 'a'];
            }
        }

        for (i = 0; i < 26; ++i) {
            while(taken[i] > 0) {
                ans += (char)('a' + i);
                -- taken[i];
            }
        }

        return ans;
    }
};