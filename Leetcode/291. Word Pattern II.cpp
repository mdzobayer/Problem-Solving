class Solution {
    unordered_map<char, string> symbolMap;
    unordered_set<string> wordSet;
public:
    bool wordPatternMatch(string pattern, string s) {
        return isMatch(s, pattern, 0, 0);
    }

    bool isMatch(string & s, string & pattern, int sIndex, int pIndex) {
        if (pIndex == pattern.length()) {
            return sIndex == s.length();
        }

        char symbol = pattern[pIndex];

        if (symbolMap.find(symbol) != symbolMap.end()) {
            string word = symbolMap[symbol];

            // If not match
            if (s.compare(sIndex, word.length(), word)) {
                return false;
            }

            return isMatch(s, pattern, sIndex + word.length(), pIndex + 1);
        }

        for (int k = sIndex + 1; k <= s.length(); ++k) {
            string newWord = s.substr(sIndex, k - sIndex);
            if (wordSet.find(newWord) != wordSet.end()) {
                continue;
            }

            symbolMap[symbol] = newWord;
            wordSet.insert(newWord);

            if (isMatch(s, pattern, k, pIndex + 1)) {
                return true;
            }

            // backtrack
            symbolMap.erase(symbol);
            wordSet.erase(newWord);
        }

        return false;
    }
};