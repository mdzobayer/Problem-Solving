class Solution {
    const vector< vector<int> > SingleStepMoves = {
        {0, 1}, {0, -1},
        {1, 0}, {-1, 0}, // Adjacent moves
        {1, 1}, {-1, 1},
        {1, -1}, {-1, -1}, // Diagonal moves
        {-2, 1}, {-2, -1},
        {2, 1}, {2, -1}, // Extended moves
        {1, -2}, {-1, -2},
        {1, 2}, {-1, 2}
    };
    const vector< vector<int> > SkipDotMoves = {
        {0, 2}, {0, -2},
        {2, 0}, {-2, 0}, // Straight skip moves
        {-2, -2}, {2, 2},
        {2, -2}, {-2, 2} // Diagonal skip moves
    };
    int m, n;
public:
    int numberOfPatterns(int m, int n) {
        this->m = m;
        this->n = n;

        int totalPatterns = 0;

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                vector< vector<bool> > visited(3, vector<bool>(3, false));

                totalPatterns += countPatternsFromDot(1, i, j, visited);
            }
        }

        return totalPatterns;
    }

    int countPatternsFromDot(int currentLen, int row, int col, vector< vector<bool> > &visited) {
        if (currentLen > n) return 0;

        int validPatterns = currentLen >= m ? 1 : 0;
        visited[row][col] = true;

        for (auto & move : SingleStepMoves) {
            int newRow = row + move[0];
            int newCol = col + move[1];

            if (isValidMove(newRow, newCol, visited)) {
                validPatterns += countPatternsFromDot(currentLen + 1, newRow, newCol, visited);
            }
        }

        for (auto & move : SkipDotMoves) {
            int newRow = row + move[0];
            int newCol = col + move[1];

            if (isValidMove(newRow, newCol, visited)) {
                int middleRow = row + move[0] / 2;
                int middleCol = col + move[1] / 2;
                if (visited[middleRow][middleCol]) {
                    validPatterns += countPatternsFromDot(currentLen + 1, newRow, newCol, visited);
                }
                
            }
        }

        visited[row][col] = false;

        return validPatterns;
    }

    bool isValidMove(int row, int col, vector< vector<bool> >& visited) {
        return row >= 0 && col >= 0 && row < 3 && col < 3 && !visited[row][col];
    }
};