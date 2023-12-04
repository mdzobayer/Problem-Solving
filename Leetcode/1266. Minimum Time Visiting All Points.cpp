class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int i, xSquare, ySquare, time = 0;

        for (i = 1; i < points.size(); ++i) {
            xSquare = abs(points[i][0] - points[i - 1][0]);
            ySquare = abs(points[i][1] - points[i - 1][1]);

            time += max(xSquare, ySquare);
        }

        return time;
    }
};