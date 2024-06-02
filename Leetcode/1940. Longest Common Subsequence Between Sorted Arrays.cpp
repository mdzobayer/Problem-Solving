class Solution {
public:
    vector<int> longestCommonSubsequence(vector<vector<int>>& arrays) {
        int m = arrays.size(), n, i, j, cnt, minLen = arrays[0].size(), minLenRow = 0;

        unordered_map<int, int> hashMap[m];
        for (i = 0; i < m; ++i) {

            if (minLen > (int)arrays[i].size()) {
                minLenRow = i;
                minLen = arrays[i].size();
            }

            for (j = 0; j < arrays[i].size(); ++j) {
                ++hashMap[i][arrays[i][j]];
            }
        }

        vector<int> ans;
        for (i = 0; i < arrays[minLenRow].size(); ++i) {
            bool willTake = true;
            for (j = 0; j < m; ++j) {
                if (hashMap[j].find(arrays[minLenRow][i]) == hashMap[j].end()) {
                    willTake = false;
                    break;
                }
                else {
                    cnt = --hashMap[j][arrays[minLenRow][i]];
                    if (cnt == 0) {
                        hashMap[j].erase(arrays[minLenRow][i]);
                    }
                }
            }

            if (willTake) {
                ans.push_back(arrays[minLenRow][i]);
            }
        }

        return ans;
    }
};