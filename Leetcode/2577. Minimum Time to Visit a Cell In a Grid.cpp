class Solution {
    vector< vector<int> > dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    int minimumTime(vector<vector<int>>& grid) {
        if (grid[0][1] > 1 && grid[1][0] > 1) {
            return -1;
        }

        int rows = grid.size(), cols = grid[0].size();
        vector< vector<bool> > visited(rows, vector<bool>(cols, false));
        priority_queue< vector<int>, vector< vector<int> >, greater<> > pq;

        pq.push({grid[0][0], 0, 0});

        while(!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            int time = curr[0], row = curr[1], col = curr[2];

            if (row == rows - 1 && col == cols - 1) return time;
            if (visited[row][col]) continue;

            visited[row][col] = true;

            for (auto & dir : dirs) {
                int nextRow = row + dir[0], nextCol = col + dir[1];
                if (!isValid(visited, nextRow, nextCol)) continue;

                int waitingTime = ((grid[nextRow][nextCol] - time) % 2 == 0) ? 1 : 0;
                int nextTime = max(grid[nextRow][nextCol] + waitingTime, time + 1);
                pq.push({nextTime, nextRow, nextCol});
            }

        }
        
        return -1;
    }

    bool isValid(vector< vector<bool> >& visited, int row, int col) {
        return row >= 0 && col >= 0 && row < visited.size() && col < visited[0].size() && !visited[row][col];
    }
};