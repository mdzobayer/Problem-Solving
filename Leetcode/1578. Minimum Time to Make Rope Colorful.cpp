class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int i, j, cnt = 1, cost = 0, n = colors.size();
        vector<int> consecutiveCost;

        for (i = 1; i < n; ++i) {
            if (colors[i] == colors[i - 1]) {
                if (cnt == 1) {
                    consecutiveCost.clear();
                    consecutiveCost.push_back(neededTime[i - 1]);
                }
                ++cnt;
                consecutiveCost.push_back(neededTime[i]);
            }
            else {
                cnt = 1;

                if (consecutiveCost.size() > 1) {
                    sort(consecutiveCost.begin(), consecutiveCost.end(), greater<int>());
                    for (j = 1; j < consecutiveCost.size(); ++j) {
                        cost += consecutiveCost[j];
                    }
                }
                consecutiveCost.clear();
            }
        }

        if (consecutiveCost.size() > 1) {
            sort(consecutiveCost.begin(), consecutiveCost.end(), greater<int>());
            for (j = 1; j < consecutiveCost.size(); ++j) {
                cost += consecutiveCost[j];
            }
        }

        return cost;
    }
};