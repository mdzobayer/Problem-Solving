class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> sCount(26, 0), tCount(26, 0);
        int i, ans = 0, len = s.size();

        for (i = 0; i < len; ++i) {
            sCount[s[i] - 'a'] += 1;
            tCount[t[i] - 'a'] += 1;
        }

        for (i = 0; i < 26; ++i) {
            if (sCount[i] < tCount[i]) 
                ans += tCount[i] - sCount[i];
        }

        return ans;
    }
};