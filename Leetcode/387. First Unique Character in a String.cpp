class Solution {
public:
    int firstUniqChar(string s) {
        int i, ans = -1, n = s.size();
        vector<int> counts(26, 0);

        for (i = 0; i < n; ++i) {
            counts[s[i] - 'a'] += 1;
        }

        for (i = 0; i < n; ++i) {
            if (counts[s[i] - 'a'] == 1) {
                ans = i;
                break;
            } 
        }

        return ans;
    }
};