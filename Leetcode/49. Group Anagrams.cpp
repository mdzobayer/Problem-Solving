class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;

        map<string, vector<int>> indexes;

        for (int i = 0; i < strs.size(); ++i) {
            string str = strs[i];
            sort(str.begin(), str.end());

            if (indexes.find(str) != indexes.end()) {
                indexes[str].push_back(i);
            }
            else {
                vector<int> groupIndex{i};
                indexes[str] = groupIndex;
            }
        }

        for (auto it = indexes.begin(); it != indexes.end(); ++it) {
            vector<int> groupIndex = it->second;
            vector<string> group;

            for (int i = 0; i < groupIndex.size(); ++i) {
                group.push_back(strs[groupIndex[i]]);
            }

            ans.push_back(group);
        }

        return ans;
    }
};