class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> hashMap1, hashMap2;
        stringstream ss1(s1), ss2(s2);
        string s;

        while (ss1 >> s) {
            ++hashMap1[s];
        }

        while (ss2 >> s) {
            ++hashMap2[s];
        }

        vector<string> ans;

        for (auto it : hashMap1) {
            if (it.second == 1 && hashMap2.find(it.first) == hashMap2.end()) {
                ans.push_back(it.first);
            }
        }

        for (auto it : hashMap2) {
            if (it.second == 1 && hashMap1.find(it.first) == hashMap1.end()) {
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};