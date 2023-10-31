class Solution {
    int m, n;
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int, int>> zerosPosition;
        int i, j;
        m = matrix.size(), n = matrix[0].size();

        for (i = 0; i < m; ++i) {
            for (j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    zerosPosition.push_back(make_pair(i, j));
                }
            }
        }

        for (i = 0; i < zerosPosition.size(); ++i) {
            setZero(matrix, zerosPosition[i], 1);
            setZero(matrix, zerosPosition[i], 2);
            setZero(matrix, zerosPosition[i], 3);
            setZero(matrix, zerosPosition[i], 4);
        }
    }

    void setZero(vector<vector<int>>& matrix, pair<int, int> position, int dir) {
        while(isValid(position)) {
            matrix[position.first][position.second] = 0;
            // Up
            if (dir == 1) {
                position.first -= 1;
            }
            else if (dir == 2) {
                position.second += 1;
            }
            else if (dir == 3) {
                position.first += 1;
            }
            else {
                position.second -= 1;
            }
        }
    }

    bool isValid(pair<int, int> & position) {
        if (position.first < 0 || position.first >= m || 
            position.second < 0 || position.second >= n) return false;

        return true;
    }
};