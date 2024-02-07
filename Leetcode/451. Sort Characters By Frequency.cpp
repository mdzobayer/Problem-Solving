class Solution {
public:
    string frequencySort(string s) {

        unordered_map<char, int> frequencyCount;
        vector<pair<int, char>> frequencyList;
        int n = s.size(), i, j;
        string ans = "";

        for (i = 0; i < n; ++i) {
            ++frequencyCount[s[i]];
        }

        for (auto it = frequencyCount.begin(); it != frequencyCount.end(); ++it) {
            frequencyList.push_back(make_pair(it->second, it->first));
        }

        sort(frequencyList.begin(), frequencyList.end(), greater<pair<int, char>>());

        for (i = 0; i < frequencyList.size(); ++i) {
            for (j = 0; j < frequencyList[i].first; ++j) {
                ans += frequencyList[i].second;
            }
        }

        return ans;
    }
};