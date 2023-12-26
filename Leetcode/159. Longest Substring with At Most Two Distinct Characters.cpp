class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int i, j, ans = 0, n = s.size();
        vector<int> counts(130, 0);

        for (i = 0, j = 0; i < n; ++i) {
            counts[s[i]] += 1;
            while(!checkValidity(counts)) {
                counts[s[j++]] -= 1;
            }
            ans = max(ans, i - j + 1);
        }

        return ans;
    }

    bool checkValidity(vector<int>& counts) {
        int cnt = 0;

        for (int i = 'A'; i <= 'z'; ++i) {
            if (counts[i] > 0) {
                ++ cnt;
            }

            if (cnt > 2) return false;
        }

        return true;
    }
};