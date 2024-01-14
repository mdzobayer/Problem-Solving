class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int i, len1 = word1.size(), len2 = word2.size();

        if (len1 != len2) return false;

        vector<int> word1Count(26, 0), word2Count(26, 0);

        for (i = 0; i < len1; ++i) {
            word1Count[word1[i] - 'a'] += 1;
            word2Count[word2[i] - 'a'] += 1;
        }

        for (i = 0; i < 26; ++i) {
            if (word1Count[i] > 0 && word2Count[i] == 0) return false;
            if (word2Count[i] > 0 && word1Count[i] == 0) return false;
        }

        sort(word1Count.begin(), word1Count.end());
        sort(word2Count.begin(), word2Count.end());

        for (i = 0; i < 26; ++i) {
            if (word1Count[i] != word2Count[i]) return false;
        }

        return true;
    }
};