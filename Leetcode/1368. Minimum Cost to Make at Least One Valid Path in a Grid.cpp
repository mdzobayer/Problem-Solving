class Solution {
    vector<vector<int>> dirs = {{0,1}, {0, -1}, {1, 0}, {-1, 0}};

public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        pq.push({0, 0, 0});

        vector<vector<int>> minCost(m, vector<int>(n, INT_MAX));
        minCost[0][0] = 0;

        while(!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            int cost = curr[0], row = curr[1], col = curr[2];

            for (int dir = 0; dir < 4; ++dir) {
                int newRow = row + dirs[dir][0];
                int newCol = col + dirs[dir][1];

                if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n) {
                    int newCost = cost + (dir != (grid[row][col] - 1) ? 1 : 0);

                    if (minCost[newRow][newCol] > newCost) {
                        minCost[newRow][newCol] = newCost;
                        pq.push({newCost, newRow, newCol});
                    }
                }
            }
        }

        return minCost[m - 1][n - 1];
    }
};