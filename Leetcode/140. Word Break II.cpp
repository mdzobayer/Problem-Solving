class Solution {
    unordered_set<string> wordSet;
    vector<string> result;
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        this->wordSet = wordSet;
        string currentSentence = string("");
        backtrack(s, currentSentence, 0);
        return result;
    }

    void backtrack(string & s, string & currentSentence, int startIndex) {
        if (startIndex >= s.length()) {
            result.push_back(currentSentence);
            return;
        }

        for (int endIndex = startIndex + 1; endIndex <= s.length(); ++ endIndex) {
            string word = s.substr(startIndex, endIndex - startIndex);

            if (wordSet.find(word) != wordSet.end()) {
                string originalSentence = currentSentence;
                if (!currentSentence.empty()) {
                    currentSentence += " ";
                }

                currentSentence += word;

                backtrack(s, currentSentence, endIndex);
                currentSentence = originalSentence;
            }
        }
    }
};