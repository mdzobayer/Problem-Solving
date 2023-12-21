class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        int i, j, k, m, n, ans = INT_MAX;
        m = grid.size();
        n = grid[0].size();
        vector<int> rows, cols;
        
        for (i = 0; i < m; ++i) {
            for (j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    rows.push_back(i);
                    cols.push_back(j);
                }
            }
        }
        sort(rows.begin(), rows.end());
        sort(cols.begin(), cols.end());

        int row = rows.at(rows.size() / 2);
        int col = cols.at(cols.size() / 2);

        ans = calculateManhattanDis1D(rows, row) + calculateManhattanDis1D(cols, col);

        return ans;
    }

    int calculateManhattanDis1D(vector<int> & collection, int origin) {
        int i, totalDistance = 0;

        for (i = 0; i < collection.size(); ++i) {
                totalDistance += abs(origin - collection[i]);
        }

        return totalDistance;
    }
};