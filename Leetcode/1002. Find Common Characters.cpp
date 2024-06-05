class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int i, j, m = words.size();
        vector<string> ans;
        vector< vector<int> > freq(m, vector<int>(26, 0));

        for (i = 0; i < words.size(); ++i) {
            for (j = 0; j < words[i].size(); ++j) {
                char ch = words[i][j];
                ++ freq[i][ch - 'a'];
            }
        }

        for (i = 0; i < 26; ++i) {
            int minValue = freq[0][i];
            for (j = 1; j < m; ++j) {
                minValue = min(minValue, freq[j][i]);
                if (minValue == 0) break;
            }

            for (j = 0; j < minValue; ++j) {
                string s = "";
                s += 'a' + i;
                ans.push_back(s);
            }
        }

        return ans;
    }
};