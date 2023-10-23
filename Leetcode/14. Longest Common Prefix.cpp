class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int i, j, minLen = strs[0].size(), rows = strs.size();
        string ans = "";

        for (i = 1; i < rows; ++i) {
            minLen = min(minLen, (int)strs[i].size());
        }

        for (i = 0; i < minLen; ++i) {
            bool isSame = true;
            for (j = 1; j < rows; ++j) {
                if (strs[j - 1][i] != strs[j][i]) {
                    isSame = false;
                    break;
                }
            }

            if (!isSame) {
                break;
            }
            ans += strs[0][i];
        }

        return ans;
    }
};