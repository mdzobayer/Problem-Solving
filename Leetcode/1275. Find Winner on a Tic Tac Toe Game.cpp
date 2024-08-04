class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        string ans = "Pending";

        int n = moves.size();
        if (n < 5) return ans;
        int i, j, k = 10;

        vector< vector<int> > grid(3, vector<int>(3, 0));
        for (i = 0; i < 3; ++i) {
            for (j = 0; j < 3; ++j) {
                grid[i][j] = k++;
            }
        }

        for (i = 0; i < moves.size(); ++i) {
            bool player1 = i % 2 == 0;
            if (player1) {
                grid[moves[i][0]][moves[i][1]] = 1;
            }
            else {
                grid[moves[i][0]][moves[i][1]] = 2;
            }

            if (i >= 4 && check(grid)) {
                
                if (player1) ans = "A";
                else ans = "B";

                return ans;
            }
        }

        if (moves.size() == 9) {
            ans = "Draw";
        }

        return ans;
    }

    bool check(vector< vector<int> > & grid) {
        // Row check
        if (grid[0][0] == grid[0][1] && grid[0][1] == grid[0][2]) {
            return true;
        }

        if (grid[1][0] == grid[1][1] && grid[1][1] == grid[1][2]) {
            return true;
        }

        if (grid[2][0] == grid[2][1] && grid[2][1] == grid[2][2]) {
            return true;
        }

        // Column check
        if (grid[0][0] == grid[1][0] && grid[1][0] == grid[2][0]) {
            return true;
        }

        if (grid[0][1] == grid[1][1] && grid[1][1] == grid[2][1]) {
            return true;
        }

        if (grid[0][2] == grid[1][2] && grid[1][2] == grid[2][2]) {
            return true;
        }

        // Back diagonal
        if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2]) {
            return true;
        }

        // Front diagonal
        if (grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0]) {
            return true;
        }

        return false;
    }
};