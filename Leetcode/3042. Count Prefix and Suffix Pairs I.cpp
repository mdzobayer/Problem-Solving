class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int i, j, ans = 0;
        
        for (i = 0; i < words.size(); ++i) {
            for (j = i + 1; j < words.size(); ++j) {
                if (isPrefixAndSuffix(words[i], words[j])) {
                    ++ ans;
                }
            }
        }

        return ans;
    }

    bool isPrefixAndSuffix(const string& s1, const string& s2) {
        if (s1.size() > s2.size()) return false;

        int len = s1.size();
        if (s2.substr(0, len) != s1) return false;
        if (s2.substr(s2.size() - len) != s1) return false;
        return true; 
    }
};