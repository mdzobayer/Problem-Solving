class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int i, n = words.size();
        vector<int> preSum(n, 0), ans;

        for (i = 0; i < n; ++i) {
            if (isVowel(words[i].front()) && isVowel(words[i].back())) {
                preSum[i] = 1;
            }
            if (i > 0)
                preSum[i] += preSum[i - 1];
        }

        for (auto& query : queries) {
            int l = query[0], r = query[1];

            int qa = preSum[r];
            if (l > 0) qa -= preSum[l - 1];
            ans.push_back(qa);
        }

        return ans;
    }

    bool isVowel(const char & ch) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            return true;
        return false;
    }
};