class Solution {
    int m, n;
    int dir[4][2] = {{-1, 0},{0, 1}, {1, 0}, {0, -1}};
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int i, j, k, ans = 0;
        m = grid.size();
        n = grid[0].size();

        for (i = 0; i < m; ++i) {
            for (j = 0; j < n; ++j) {
                for (k = 0; k < 4 && grid[i][j] == 1; ++k) {
                    if (isValid(i + dir[k][0], j + dir[k][1])) {
                        if (hasPerimeter(i + dir[k][0], j + dir[k][1], grid)) {
                            ++ ans;
                        }
                    }
                    else {
                        ++ ans;
                    }
                }
            }
        }

        return ans;
    }

    bool isValid(int x, int y) {
        if (x < 0 || y < 0 || x >= m || y >= n) return false;
        return true;
    }

    bool hasPerimeter(int x, int y, vector<vector<int>>& grid) {
        if (grid[x][y] == 1) return false;
        return true;
    }
};