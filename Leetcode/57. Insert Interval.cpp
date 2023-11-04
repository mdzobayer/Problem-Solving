class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<pair<int, int>> allIntervals;
        int i;
        for (i = 0; i < intervals.size(); ++i) {
            allIntervals.push_back(make_pair(intervals[i][0], intervals[i][1]));
        }

        allIntervals.push_back(make_pair(newInterval[0], newInterval[1]));

        sort(allIntervals.begin(), allIntervals.end());

        vector<vector<int>> ans;
        vector<int> aInterval(2, 0);

        aInterval[0] = allIntervals[0].first;
        aInterval[1] = allIntervals[0].second;

        for (i = 1; i < allIntervals.size(); ++i) {
            if (aInterval[1] < allIntervals[i].first) {
                ans.push_back(aInterval);

                aInterval[0] = allIntervals[i].first;
                aInterval[1] = allIntervals[i].second;
            }
            else {
                aInterval[1] = max(aInterval[1], allIntervals[i].second);
            }
        }

        ans.push_back(aInterval);

        return ans;
    }
};