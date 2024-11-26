class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        if (n == 1) return 0;

        vector<int> inDegree(n, 0);
        int i;

        for (auto & edge : edges) {
            int y = edge[1];
            ++ inDegree[y];
        }

        vector< pair<int, int> > inDegreePairs;

        for (i = 0; i < n; ++i) {
            inDegreePairs.push_back(make_pair(inDegree[i], i));
        }

        sort(inDegreePairs.begin(), inDegreePairs.end());

        if (inDegreePairs[0].first == inDegreePairs[1].first) {
            return -1;
        }

        return inDegreePairs[0].second;
    }
};