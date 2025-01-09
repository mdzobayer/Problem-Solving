class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans = 0, len = pref.size();

        for (string& word : words) {
            if (word.size() < len) continue;

            if (word.substr(0, len) == pref) {
                ++ ans;
            }
        }

        return ans;
    }
};