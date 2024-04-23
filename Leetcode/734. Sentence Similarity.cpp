class Solution {
public:
    bool areSentencesSimilar(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        if (sentence1.size() != sentence2.size()) return false;

        if (sentence1 == sentence2) return true;

        unordered_map<string, unordered_set<string>> hashMap;
        for (auto similarPair : similarPairs) {
            hashMap[similarPair[0]].insert(similarPair[1]);
            hashMap[similarPair[1]].insert(similarPair[0]);
        }

        for (int i = 0; i < sentence1.size(); ++i) {
            if (sentence1[i] == sentence2[i]) continue;
            if (hashMap[sentence1[i]].count(sentence2[i]) == 0) {
                return false;
            }
        }

        return true;
    }
};