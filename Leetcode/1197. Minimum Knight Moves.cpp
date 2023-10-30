class Solution {
public:
    int minKnightMoves(int x, int y) {
        queue<pair<pair<int, int>, int>> qu;

        bool visited [610][610];
        memset(visited, false, sizeof(visited));

        pair<pair<int, int>, int> current = make_pair(make_pair(0, 0), 0);
        qu.push(current);

        visited[0 + 303][0 + 303] = true;

        pair<int, int> position;
        int i, ans = -1, level;

        while(!qu.empty()) {
            current = qu.front();
            qu.pop();

            position = current.first;
            level = current.second;

            if (position.first == x && position.second == y) {
                ans = level;
                break;
            }


            pair<int, int> move = make_pair(position.first - 2, position.second - 1);
            if (!visited[move.first + 303][move.second + 303]) {
                if (move.first == x && move.second == y) {
                    ans = level + 1;
                    break;
                }
                else {
                    visited[move.first + 303][move.second + 303] = true;
                    qu.push(make_pair(move, level + 1));
                }
            }

            move = make_pair(position.first - 2, position.second + 1);
            if (!visited[move.first + 303][move.second + 303]) {
                if (move.first == x && move.second == y) {
                    ans = level + 1;
                    break;
                }
                else {
                    visited[move.first + 303][move.second + 303] = true;
                    qu.push(make_pair(move, level + 1));
                }
            }

            move = make_pair(position.first + 2, position.second + 1);
            if (!visited[move.first + 303][move.second + 303]) {
                if (move.first == x && move.second == y) {
                    ans = level + 1;
                    break;
                }
                else {
                    visited[move.first + 303][move.second + 303] = true;
                    qu.push(make_pair(move, level + 1));
                }
            }

            move = make_pair(position.first + 2, position.second - 1);
            if (!visited[move.first + 303][move.second + 303]) {
                if (move.first == x && move.second == y) {
                    ans = level + 1;
                    break;
                }
                else {
                    visited[move.first + 303][move.second + 303] = true;
                    qu.push(make_pair(move, level + 1));
                }
            }

            move = make_pair(position.first + 1, position.second - 2);
            if (!visited[move.first + 303][move.second + 303]) {
                if (move.first == x && move.second == y) {
                    ans = level + 1;
                    break;
                }
                else {
                    visited[move.first + 303][move.second + 303] = true;
                    qu.push(make_pair(move, level + 1));
                }
            }

            move = make_pair(position.first - 1, position.second - 2);
            if (!visited[move.first + 303][move.second + 303]) {
                if (move.first == x && move.second == y) {
                    ans = level + 1;
                    break;
                }
                else {
                    visited[move.first + 303][move.second + 303] = true;
                    qu.push(make_pair(move, level + 1));
                }
            }

            move = make_pair(position.first + 1, position.second + 2);
            if (!visited[move.first + 303][move.second + 303]) {
                if (move.first == x && move.second == y) {
                    ans = level + 1;
                    break;
                }
                else {
                    visited[move.first + 303][move.second + 303] = true;
                    qu.push(make_pair(move, level + 1));
                }
            }

            move = make_pair(position.first - 1, position.second + 2);
            if (!visited[move.first + 303][move.second + 303]) {
                if (move.first == x && move.second == y) {
                    ans = level + 1;
                    break;
                }
                else {
                    visited[move.first + 303][move.second + 303] = true;
                    qu.push(make_pair(move, level + 1));
                }
            }
        }

        return ans;
    }

};