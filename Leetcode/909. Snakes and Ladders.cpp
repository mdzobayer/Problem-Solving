class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int i, j, k, dir, ans = -1, n = board.size();
        int maxNumber = n * n;

        vector<int> boardNumber(maxNumber + 4);
        vector<int> cost(maxNumber + 4, INT_MAX);

        i = n - 1;
        j = 0;
        k = 1;
        dir = 1;

        while(i >= 0) {
            
            while(j >= 0 && j < n) {
                boardNumber[k] = board[i][j];
                ++k;
                j += dir;
            }

            if (dir == 1) {
                dir = -1;
                j = n - 1;
            }
            else {
                dir = 1;
                j = 0;
            }
            --i;
        }

        pair<int, int> position = make_pair(0, 1);
        queue<pair<int,int>> q;
        q.push(position);

        while(!q.empty()) {
            position = q.front();
            q.pop();

            if (position.second == maxNumber) {
                ans = position.first;
                break;
            }

            for (i = position.second + 1; i <= maxNumber && (i - position.second) <= 6; ++i) {
                if (boardNumber[i] == -1) {
                    if (position.first + 1 < cost[i]) {
                        cost[i] = position.first + 1;
                        q.push(make_pair(position.first + 1, i));
                    }
                }
                else {
                    if (position.first + 1 < cost[boardNumber[i]]) {
                        cost[boardNumber[i]] = position.first + 1;
                        q.push(make_pair(position.first + 1, boardNumber[i]));
                    }
                }
            }
        }

        return ans;
    }
};