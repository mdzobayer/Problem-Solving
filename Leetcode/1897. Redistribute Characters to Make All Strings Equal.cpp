class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int i, j, len = words.size();
        vector<int> charCounts(26, 0);

        for (i = 0; i < len; ++i) {
            for (j = 0; j < words[i].size(); ++j) {
                charCounts[words[i][j] - 'a'] += 1;
            }
        }
        
        bool ans = true;
        for(i = 0; i < 26; ++i) {
            if (charCounts[i] > 0 && charCounts[i] % len > 0) {
                ans = false;
                break;
            }
        }

        return ans;
    }
};