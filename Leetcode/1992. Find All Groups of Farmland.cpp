class Solution {
    int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int M, N;
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        M = land.size();
        N = land[0].size();

        vector< vector<bool> > visited(M, vector<bool>(N, false));
        vector<vector<int>> ans;

        int i, j;
        for (i = 0; i < M; ++i) {
            for (j = 0; j < N; ++j) {
                if (land[i][j] && !visited[i][j]) {
                    int x2 = 0, y2 = 0;
                    dfs(land, visited, i, j, x2, y2);
                    ans.push_back({i, j, x2, y2});
                }
            }
        }

        return ans;
    }

    void dfs(vector<vector<int>>& land, vector< vector<bool> >& visited, int x, int y, int & x2, int & y2) {
        visited[x][y] = true;

        x2 = max(x, x2);
        y2 = max(y, y2);

        for (auto dir : dirs) {
            int newX = x + dir[0], newY = y + dir[1];
            if (isValid(newX, newY) && !visited[newX][newY] && land[newX][newY]) {
                dfs(land, visited, newX, newY, x2, y2);
            }
        }
    }

    bool isValid(int x, int y) {
        return x >= 0 && y >= 0 && x < M && y < N;
    }
};