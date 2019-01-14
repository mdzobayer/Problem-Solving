#include <bits/stdc++.h>

using namespace std;
#define SIZE 1001

int n, m, K, sx, sy, tx, ty;
int k, T, nx, ny, x, y;

char mp[SIZE][SIZE];
int d[SIZE][SIZE], dw[4][2] = { { 0, 1 }, {1, 0}, {0, -1}, {-1, 0}};

void bfs() {
    //int k, T, nx, ny, x, y;
    queue < pair < int , int > > q;
    q.push({sx, sy});
    d[sx][sy] = 0;
    while (q.size()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        //cout << "Poped " << x << " " << y << endl;
        if (x == tx && y == ty) {
            cout << d[x][y] << endl;
            return;
        }
        for (k = 0; k < 4; ++k) {
            for (T = 1; T <= K; ++T) {
                nx = x + dw[k][0] * T;
                ny = y + dw[k][1] * T;

                if (nx < 1 || nx > n || ny < 1 || ny > m)
                    continue;

                if (mp[nx][ny] != '.' || d[nx][ny] <= d[x][y])
                    break;
                if (d[nx][ny] > d[x][y] + 1) {
                    d[nx][ny] = d[x][y] + 1;
                    q.push({nx, ny});
                    //cout << "--- Pushed " << nx << " " << ny << endl;
                }
            }
        }
    }
    cout << "-1" << endl;
}
int main() {

    //freopen("in.txt", "r", stdin);
    memset(d, 127, sizeof(d));

    cin >> n >> m >> K;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> mp[i][j];
        }
    }
    cin >> sx >> sy >> tx >> ty;
    bfs();

    return (0);
}
