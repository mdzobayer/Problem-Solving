class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int i, ans = INT_MAX, n = timePoints.size();
        vector< int > points;

        for (const string & str : timePoints) {
            points.push_back((stoi(str.substr(0, 2)) * 60) + stoi(str.substr(3)));
        }

        sort(points.begin(), points.end());

        for (i = 1; i < n; ++i) {
            if (points[i] - points[i - 1] < ans) {
                ans = points[i] - points[i - 1];
            }
        }
        int backCalculation = points.front() + (1440 - points.back());
        ans = min(ans, backCalculation);

        return ans;
    }
};