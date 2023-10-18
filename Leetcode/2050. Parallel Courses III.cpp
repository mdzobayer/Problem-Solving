class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int> preRequired(n+1, 0);
        vector<int> maxSoFarRequired(n+1, 0);
        vector< vector<int> > ajList;

        for (int i = 0; i <= n; ++i) {
            vector<int> listRow;
            ajList.push_back(listRow);
        }

        for (int i = 0; i < relations.size(); ++i) {
            preRequired[relations[i][1]] += 1;
            ajList[relations[i][0]].push_back(relations[i][1]);
        }

        queue<pair<int,int>> qu;
        int level = 0;
        for (int i = 1; i <= n; ++i) {
            if (preRequired[i] == 0) {
                qu.push(make_pair(i, time[i - 1]));
            }
        }
        pair<int, int> frontItem;

        int totalTime = 0;

        while(!qu.empty()) {
            frontItem = qu.front();
            qu.pop();

            totalTime = max(totalTime, frontItem.second);

            for (int i = 0; i < ajList[frontItem.first].size(); ++i) {
                
                preRequired[ajList[frontItem.first][i]] -= 1;

                maxSoFarRequired[ajList[frontItem.first][i]] = max(maxSoFarRequired[ajList[frontItem.first][i]], frontItem.second);

                if (preRequired[ajList[frontItem.first][i]] == 0) {
                    qu.push(make_pair(ajList[frontItem.first][i], maxSoFarRequired[ajList[frontItem.first][i]] + time[ajList[frontItem.first][i] - 1]));
                }
            }

        }

        return totalTime;

    }
};