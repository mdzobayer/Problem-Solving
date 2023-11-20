class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int i, j, n = garbage.size();

        vector<int> rowCount(3, 0);
        vector<int> costSum(n, 0);
        vector< vector<int> > garbageCounts;

        for (i = 0; i < n; ++i) {
            garbageCounts.push_back(rowCount);
            if (i > 0) {
                costSum[i] = costSum[i - 1] + travel[i - 1];
            }
        }

        for (i = 0; i < n; ++i) {
            for (j = 0; j < garbage[i].size(); ++j) {
                if (garbage[i][j] == 'M') {
                    garbageCounts[i][0] += 1;
                }
                else if (garbage[i][j] == 'P') {
                    garbageCounts[i][1] += 1;
                }
                else {
                    garbageCounts[i][2] += 1;
                }
            }
        }
        int travelCostM = 0, travelCostP = 0, travelCostG = 0;
        int pickingCostM = 0, pickingCostP = 0, pickingCostG = 0;

        for (i = 0; i < n; ++i) {
            if (garbageCounts[i][0] > 0) {
                travelCostM = max(travelCostM, costSum[i]);
                pickingCostM += garbageCounts[i][0];
            }
            
            if (garbageCounts[i][1] > 0) {
                travelCostP = max(travelCostP, costSum[i]);
                pickingCostP += garbageCounts[i][1];
            }

            if (garbageCounts[i][2] > 0) {
                travelCostG = max(travelCostG, costSum[i]);
                pickingCostG += garbageCounts[i][2];
            }
        }

        return (travelCostM + travelCostP + travelCostG) + (pickingCostM + pickingCostP + pickingCostG);
    }
};