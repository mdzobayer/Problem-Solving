class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        vector<pair<int,int>> balloonsEnd;

        for (int i = 0; i < points.size(); ++i) {
            balloonsEnd.push_back(make_pair(points[i][1], points[i][0]));
        }

        sort(balloonsEnd.begin(), balloonsEnd.end());

        int lastArrows = balloonsEnd[0].first;
        int totalArrow = 1;

        for (int i = 1; i < balloonsEnd.size(); ++i) {
            if (lastArrows < balloonsEnd[i].second) {
                lastArrows = balloonsEnd[i].first;
                ++totalArrow;
            }
        }

        return totalArrow;
    }
};