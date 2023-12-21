class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        int i, n = points.size();

        vector<int> items(n);
        for (i = 0; i < n; ++i) {
            items[i] = points[i][0];
        }

        sort(items.begin(), items.end());
        int ans = 0;
        for (i = 1; i < n; ++i) {
            ans = max(ans, items[i] - items[i - 1]);
        }

        return ans;
    }
};