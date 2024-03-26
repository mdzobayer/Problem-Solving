class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int i, current = 0, maximum = 0, n = intervals.size();
        priority_queue<int, vector<int>, greater<int>> endTimes;

        for (i = 0; i < n; ++i) {

            endTimes.push(intervals[i][1]);
            ++ current;

            while(endTimes.top() <= intervals[i][0]) {
                endTimes.pop();
                -- current;
            }

            maximum = max(maximum, current);
        }

        return maximum;
    }
};