class Solution {
    int maxScore = 0;
    vector<int> freq;
    vector<int> subsetLetters;
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int w = words.size();
        freq.resize(26, 0);
        subsetLetters.resize(26, 0);

        for (char c : letters) {
            ++ freq[c - 'a'];
        }

        solve(w - 1, words, score, 0);

        return maxScore;
    }

    bool isValidWord() {
        for (int c = 0; c < 26; ++ c) {
            if (freq[c] < subsetLetters[c]) {
                return false;
            }
        }

        return true;
    }

    void solve(int w, vector<string>& words, vector<int>& score, int totalScore) {
        if (w == -1) {
            maxScore = max(maxScore, totalScore);
            return;
        }

        solve(w - 1, words, score, totalScore);

        int i, len = words[w].size();
        for (i = 0; i < len; ++i) {
            int c = words[w][i] - 'a';
            ++ subsetLetters[c];
            totalScore += score[c];
        }

        if (isValidWord()) {
            solve(w - 1, words, score, totalScore);
        }

        for (i = 0; i < len; ++i) {
            int c = words[w][i] - 'a';
            -- subsetLetters[c];
            totalScore -= score[c];
        }
    }
};