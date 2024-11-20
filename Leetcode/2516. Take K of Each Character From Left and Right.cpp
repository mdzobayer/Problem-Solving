class Solution {
public:
    int takeCharacters(string s, int k) {
        vector<int> counts(3, 0), window(3, 0);
        int i, left, right, maxWindow, n = s.size();

        for (char c : s) {
            ++ counts[c - 'a'];
        }

        for (i = 0; i < 3; ++i) {
            if (counts[i] < k) {
                return -1;
            }
        }
        left = 0;
        maxWindow = 0;

        for (right = 0; right < n; ++right) {
            ++ window[s[right] - 'a'];

            while(left <= right && (counts[0] - window[0] < k || counts[1] - window[1] < k || counts[2] - window[2] < k)) {
                -- window[s[left] - 'a'];
                ++left;
            }

            maxWindow = max(maxWindow, right - left + 1);
        }

        return n - maxWindow;
    }
};