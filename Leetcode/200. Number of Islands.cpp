class Solution {
    int m, n;
    vector<vector<bool>> visited;
    int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        int i, j;
        vector<bool> visitedRow(n, false);
        
        for (i = 0; i < m; ++i) {
            visited.push_back(visitedRow);
        }
        int ans = 0;
        for (i = 0; i < m; ++i) {
            for (j = 0; j < n; ++j) {
                if (grid[i][j] == '1' && 
                visited[i][j] == false) {
                    ++ ans;
                markIsland(make_pair(i, j), grid);

                }
            }
        }

        return ans;
    }

    void markIsland(pair<int,int> position, vector<vector<char>>& grid) {
        
        queue<pair<int, int>> qu;
        visited[position.first][position.second] = true;
        qu.push(position);

        while(!qu.empty()) {
            position = qu.front();
            qu.pop();

            pair<int,int> newPosition;
            for (int i = 0; i < 4; ++i) {
                newPosition.first = position.first + dir[i][0];
                newPosition.second = position.second + dir[i][1];

                if (!isValid(newPosition)) continue;

                if (grid[newPosition.first][newPosition.second] == '1' && 
                visited[newPosition.first][newPosition.second] == false) {
                    visited[newPosition.first][newPosition.second] = true;
                    qu.push(newPosition);
                }
            }

        }
    }

    bool isValid(const pair<int,int> & position) {
        if (position.first < 0 || position.first >= m || 
            position.second < 0 || position.second >= n) return false;

        return true;
    }
};