class Solution {
    int charCounts[26];
public:
    int countCharacters(vector<string>& words, string chars) {
        memset(charCounts, 0, sizeof(charCounts));

        int i, len = 0;
        for (i = 0; i < chars.size(); ++i) {
            charCounts[chars[i] - 'a'] += 1;
        }

        for (i = 0; i < words.size(); ++i) {
            if (isPossible(words[i])) {
                len += words[i].size();
            }
        }

        return len;
    }

    bool isPossible(string & str) {
        bool ans = true;
        int i;
        vector<int> localCount(charCounts, charCounts + 26);

        for (i = 0; i < str.size(); ++i) {
            if (localCount[str[i] - 'a'] > 0) {
                localCount[str[i] - 'a'] -= 1;
            }
            else {
                ans = false;
                break;
            }
        }

        return ans;
    }

    void updateCount(string & str) {
        for (int i = 0; i < str.size(); ++i) {
            charCounts[str[i] - 'a'] -= 1;
        }
    }
};