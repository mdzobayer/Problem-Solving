class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {

        if (intervals.size() < 2) return true;
        sort(intervals.begin(), intervals.end());

        int lastEnd = intervals[0][1];
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] < lastEnd) return false;

            lastEnd = intervals[i][1];
        }

        return true;
    }
};