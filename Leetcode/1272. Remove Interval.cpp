class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
        sort(intervals.begin(), intervals.end());
        int i;
        vector<vector<int>> ans;

        for (i = 0; i < intervals.size(); ++i) {
            // Outside
            if (intervals[i][0] < toBeRemoved[0] && intervals[i][1] <= toBeRemoved[0]) {
                ans.push_back(vector<int>{intervals[i][0], intervals[i][1]});
            }
            else if (intervals[i][0] >= toBeRemoved[1] && intervals[i][1] > toBeRemoved[1]) {
                ans.push_back(vector<int>{intervals[i][0], intervals[i][1]});
            }
            else if (intervals[i][0] < toBeRemoved[0] && intervals[i][1] <= toBeRemoved[1]) {
                ans.push_back(vector<int>{intervals[i][0], toBeRemoved[0]});
            }
            else if (intervals[i][0] >= toBeRemoved[0] && intervals[i][1] > toBeRemoved[1]) {
                ans.push_back(vector<int>{toBeRemoved[1], intervals[i][1]});
            }
            else if (intervals[i][0] < toBeRemoved[0] && intervals[i][1] > toBeRemoved[1]) {
                ans.push_back(vector<int>{intervals[i][0], toBeRemoved[0]});
                ans.push_back(vector<int>{toBeRemoved[1], intervals[i][1]});
            }
        }

        return ans;
    }
};