class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        unordered_map<int, int> hashMap;

        int i, j, ans = INT_MAX, m = mat.size(), n = mat[0].size();
        for (i = 0; i < m; ++i) {
            for (j = 0; j < n; ++j) {
                ++ hashMap[mat[i][j]];
            }
        }

        for (auto it = hashMap.begin(); it != hashMap.end(); ++it) {
            if (it->second == m) {
                ans = min(ans, it->first);
            }
        }

        return ans != INT_MAX ? ans : -1;
    }
};