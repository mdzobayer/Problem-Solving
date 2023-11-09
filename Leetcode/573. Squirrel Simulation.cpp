class Solution {
public:
    int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
        int i, cost = 0, n = nuts.size();
        vector<int> treeDistances(n, 0), squirrelDistances(n, 0);

        int totalTreeCost = 0;

        for (i = 0; i < n; ++i) {
            treeDistances[i] = twoPointDistance(nuts[i][0], nuts[i][1], tree[0], tree[1]);
            totalTreeCost += (treeDistances[i] * 2);

            squirrelDistances[i] = twoPointDistance(nuts[i][0], nuts[i][1], squirrel[0], squirrel[1]);

        }

        int tempCost = 0;
        cost = (totalTreeCost - treeDistances[0]) + squirrelDistances[0];
        for (i = 1; i < n; ++i) {
            tempCost = (totalTreeCost - treeDistances[i]) + squirrelDistances[i];
            if (tempCost < cost) {
                cost = tempCost;
            }
        }

        return cost;
    }

    int twoPointDistance(int x1, int y1, int x2, int y2) {
        int x = abs(x1 - x2);
        int y = abs(y1 - y2);
        int ans = x + y;

        return ans;
    }
};