class Solution {
    int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size(), n = isWater[0].size();

        vector<vector<int>> cellHeights(m, vector<int>(n, -1));
        queue<pair<int,int>> q;

        for (int x = 0; x < m; ++x) {
            for (int y = 0; y < n; ++y) {
                if (isWater[x][y]) {
                    q.push({x, y});
                    cellHeights[x][y] = 0;
                }
            }
        }

        int currentHeight = 1;

        while(!q.empty()) {
            int layerSize = q.size();

            for (int i = 0; i < layerSize; ++i) {
                pair<int, int> currentCell = q.front();
                q.pop();

                for (int d = 0; d < 4; ++d) {
                    pair<int, int> neighbor = {currentCell.first + dx[d], currentCell.second + dy[d]};

                    if (isValid(neighbor, m, n) && cellHeights[neighbor.first][neighbor.second] == -1) {
                        cellHeights[neighbor.first][neighbor.second] = currentHeight;
                        q.push(neighbor);
                    }
                }
            }

            ++currentHeight;
        }

        return cellHeights;
    }

    bool isValid(pair<int, int> cell, int m, int n) {
        return cell.first >= 0 && cell.second >= 0 && cell.first < m && cell.second < n;
    }
};