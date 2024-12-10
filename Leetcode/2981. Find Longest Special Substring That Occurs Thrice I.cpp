class Solution {
public:
    int maximumLength(string s) {
        map< pair<char, int>, int> count;
        int start, end, substringLen = 0;

        for (start = 0; start < s.size(); ++start) {
            char ch = s[start];
            substringLen = 0;

            for (end = start; end < s.size(); ++end) {
                if (ch == s[end]) {
                    ++ substringLen;
                    ++ count[{ch, substringLen}];
                }
                else {
                    break;
                }
            }
        }

        int ans = 0;
        for (auto item : count) {
            int len = item.first.second;
            if (item.second >= 3 && len > ans) ans = len;
        }

        if (ans == 0) return -1;

        return ans;
    }
};