class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int left = 0, right, cost = 0, maxLen = 0;

        for (right = 0; right < s.size(); ++right) {
            cost += abs(s[right] - t[right]);

            while (cost > maxCost) {
                cost -= abs(s[left] - t[left]);
                ++left;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};