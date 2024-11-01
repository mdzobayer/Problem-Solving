class Solution {
public:
    string makeFancyString(string s) {
        string ans = "";
        int i, count = 1;

        ans.push_back(s.front());

        for (i = 1; i < s.size(); ++i) {
            if (s[i] == s[i - 1]) {
                ++ count;
            }
            else count = 1;

            if (count < 3) {
                ans.push_back(s[i]);
            }
        }

        return ans;
    }
};