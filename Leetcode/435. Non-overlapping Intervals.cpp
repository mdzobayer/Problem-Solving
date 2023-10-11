class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        vector<pair<int,int>> endSorted;

        for (int i = 0; i < intervals.size(); ++i) {
            endSorted.push_back(make_pair(intervals[i][1], intervals[i][0]));
        }

        sort(endSorted.begin(), endSorted.end());

        int lastEnd = endSorted[0].first;
        int itemShouldRemove = 0;

        for (int i = 1; i < endSorted.size(); ++i) {
            if (endSorted[i].second < lastEnd) {
                ++itemShouldRemove;
            }
            else {
                lastEnd = endSorted[i].first;
            }
        }

        return itemShouldRemove;
    }
};