class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        vector<int> interval(2, 0);

        int i, lastStart, lastEnd, n = intervals.size();
        vector<pair<int,int>> intervalPairs;
        for (i = 0; i < n; ++i) {
            intervalPairs.push_back(make_pair(intervals[i][0], intervals[i][1]));
        }

        sort(intervalPairs.begin(), intervalPairs.end());

        lastStart = intervalPairs[0].first;
        lastEnd = intervalPairs[0].second;

        for (i = 1; i < n; ++i) {
            if (intervalPairs[i].first > lastEnd) {

                interval[0] = lastStart;
                interval[1] = lastEnd;

                ans.push_back(interval);

                lastStart = intervalPairs[i].first;
                lastEnd = intervalPairs[i].second;
            }
            else {
                lastEnd = max(lastEnd, intervalPairs[i].second);
            }
        }

        interval[0] = lastStart;
        interval[1] = lastEnd;

        ans.push_back(interval);

        return ans;
    }
};