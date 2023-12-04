class Solution {
    unordered_map <string, int> wordCount;
    int m, n;
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int i, j;
        m = words.size();
        n = words[0].size();

        int subStrLen = m * n;
        vector<int> ans;

        if (subStrLen > s.size()) return ans;

        for (i = 0; i < m; ++i) {
            wordCount[words[i]] += 1;
        }

        for (i = 0; i <= s.size() - subStrLen; ++i) {
            if (check(s.substr(i, subStrLen))) {
                ans.push_back(i);
            }
        }

        return ans;
    }

    bool check(string str) {
        unordered_map <string, int> localWordCount = wordCount;
        bool ans = true;

        int wordUsed = 0;
        string newStr;
        for (int i = 0; i < str.size(); i += n) {
            newStr = str.substr(i, n);
            if (localWordCount.find(newStr) != localWordCount.end()) {
                if (-- localWordCount[newStr] == -1) {
                    break;
                }
                else {
                    ++wordUsed;
                }
            }
            else {
                break;
            }
        }

        return m == wordUsed;
    }
};