class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        vector< priority_queue<int> > scoreMap(1001, priority_queue<int>());
        int i;
        vector<vector<int>> ans;

        for (i = 0; i < items.size(); ++i) {
            scoreMap[items[i][0]].push(items[i][1]);
        }

        for (i = 1; i < 1001; ++i) {
            if (scoreMap[i].size() > 0) {
                int cnt = 0, sum = 0;
                while(cnt < 5) {
                    ++ cnt;
                    sum += scoreMap[i].top();
                    scoreMap[i].pop();
                }
                ans.push_back(vector<int>{i, sum / cnt});
            }
        }

        return ans;
    }
};