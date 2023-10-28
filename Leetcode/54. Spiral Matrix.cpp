class Solution {
    int m, n;
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();

        vector<bool> visitedRow(n, false);
        vector<vector<bool>> visited;
        for (int i = 0; i < m; ++i) {
            visited.push_back(visitedRow);
        }

        vector<int> ans;

        int targetValue = m * n;
        int dir = 0;
        pair<int, int> cursor = make_pair(0, 0);

        while(targetValue > 0) {

            ans.push_back(matrix[cursor.first][cursor.second]);
            visited[cursor.first][cursor.second] = true;
            -- targetValue;

            if(isValid(nextMove(cursor, dir), visited)) {
                cursor = nextMove(cursor, dir);
            }
            else {
                dir = nextDir(dir);
                cursor = nextMove(cursor, dir);
            }

        }

        return ans;
    }

    bool isValid(pair<int, int> cursor, vector<vector<bool>>& visited) {

        if (cursor.first < 0 || cursor.second < 0 || cursor.first >= m || cursor.second >= n) return false;

        if (visited[cursor.first][cursor.second]) return false;

        return true;
    }

    int nextDir(int dir) {
        if (dir == 0) return 1;
        else if (dir == 1) return 2;
        else if (dir == 2) return 3;
        else return 0;
    }

    pair<int, int> nextMove(pair<int, int> cursor, int dir) {
        
        if (dir == 0) {
            // right
            return make_pair(cursor.first, cursor.second + 1);
        }
        else if (dir == 1) {
            // down
            return make_pair(cursor.first + 1, cursor.second);
        }
        else if (dir == 2) {
            // left
            return make_pair(cursor.first, cursor.second - 1);
        }
        else {
            // up
            return make_pair(cursor.first - 1, cursor.second);
        }
    }
};