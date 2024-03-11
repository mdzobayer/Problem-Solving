class Solution {
public:
    string customSortString(string order, string s) {
        int i, j, n = s.size();
        string ans = "";
        vector<bool> taken(n, false);

        for (i = 0; i < order.size(); ++i) {
            for (j = 0; j < n; ++j) {
                if (s[j] == order[i]) {
                    ans += s[j];
                    taken[j] = true;
                }
            }
        }

        for (i = 0; i < n; ++i) {
            if (!taken[i]) {
                ans += s[i];
            }
        }

        return ans;
    }
};