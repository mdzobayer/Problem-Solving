class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end());

        unordered_set<string> hashSet;
        string longestWord;

        for (string & word : words) {
            if (word.size() == 1 || (hashSet.find(word.substr(0, word.size() - 1)) != hashSet.end())) {
                hashSet.insert(word);

                if (longestWord.size() < word.size()) {
                    longestWord = word;
                }
            }
        }

        return longestWord;
    }
};