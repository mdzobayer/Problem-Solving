class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans;

        unordered_set<int> hashSet;
        for (int space : spaces) {
            hashSet.insert(space);
        }

        for (int i = 0; i < s.size(); ++i) {
            if (hashSet.find(i) != hashSet.end()) {
                ans += ' ';
            }
            ans += s[i];
        }

        return ans;
    }
};