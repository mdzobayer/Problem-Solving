class Solution {
public:
    int maxUniqueSplit(string s) {
        unordered_set<string> hashSet;

        return backtrack(s, 0, hashSet);
    }

    int backtrack(const string & s, int start, unordered_set<string> & hashSet) {
        if (start == s.size()) return 0;

        int maxCount = 0;

        for (int end = start + 1; end <= s.size(); ++end) {
            string substr = s.substr(start, end - start);

            if (hashSet.find(substr) == hashSet.end()) {
                hashSet.insert(substr);
                maxCount = max(maxCount, 1 + backtrack(s, end, hashSet));
                hashSet.erase(substr);
            }
        }

        return maxCount;
    }
};