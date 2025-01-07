class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        int i, j;

        for (i = 0; i < words.size(); ++i) {
            for (j = 0; j < words.size(); ++j) {
                if (i == j) continue;

                size_t found = words[j].find(words[i]);
                if (found != string::npos) {
                    ans.push_back(words[i]);
                    break;
                }
            }
        }
        
        return ans;
    }
};