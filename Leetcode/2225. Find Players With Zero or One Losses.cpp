class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int i, len = 100001;

        map<int, int> wins, losses;

        for (i = 0; i < matches.size(); ++i) {
            wins[matches[i][0]] += 1;
            losses[matches[i][1]] += 1;
        }

        vector<vector<int>> ans(2);

        auto it = wins.begin();
        for (; it != wins.end(); ++it) {
            if (losses.find(it->first) == losses.end())
                ans[0].push_back(it->first);
        }

        it = losses.begin();
        for (; it != losses.end(); ++it) {
            if (it->second == 1)
                ans[1].push_back(it->first);
        }

        return ans;
    }
};