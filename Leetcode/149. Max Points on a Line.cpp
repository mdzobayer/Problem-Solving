class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int i, j, ans, n = points.size();
        if (n == 1) {
           ans = 1; 
           return ans;
        }

        ans = 2;

        for (i = 0; i < n; ++i) {
            unordered_map<double, int> counts;
            for (j = 0; j < n; ++j) {
                if (i == j) continue;

                ++ counts[atan2(points[j][1] - points[i][1], points[j][0] - points[i][0])];
            }

            for (auto [key, cnt] : counts) {
                ans = max(ans, cnt + 1);
            }
        }

        return ans;
    }
};