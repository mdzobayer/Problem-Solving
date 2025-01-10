class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        unordered_set<string> hashMap;
        vector<int> bCounts(26, 0);
        vector<string> ans;
        int i;

        for(string& word : words2) {
            vector<int> indiviCounts(26, 0);
            for(char ch : word) {
                ++ indiviCounts[ch - 'a'];
            }

            for (i = 0; i < 26; ++i) {
                bCounts[i] = max(bCounts[i], indiviCounts[i]);
            }
        }

        for (string& word : words1) {
            vector<int> aCounts(26, 0);
            for(char ch : word) {
                ++ aCounts[ch - 'a'];
            }

            bool valid = true;
            for (i = 0; i < 26; ++i) {
                if (bCounts[i] > aCounts[i]) {
                    valid = false;
                    break;
                }
            }

            if (valid) ans.push_back(word);
        }

        return ans;
    }
};