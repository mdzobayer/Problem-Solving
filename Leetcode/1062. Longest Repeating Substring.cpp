class Solution {
public:
    int longestRepeatingSubstring(string s) {
        unordered_set<string> hashSet;

        int len, ans = 0, j, n = s.size();

        for (len = n; len > 0; --len) {
            for(j = n - len; j >= 0; --j) {
                string str = s.substr(j, len);
                if (hashSet.find(str) != hashSet.end()) {
                    return str.size();
                }
                hashSet.insert(str);
            }

            hashSet.clear();
        }

        return ans;
    }
};