#include <bits/stdc++.h>


using namespace std;

int grid[105][105], n, c;
int dp[105][105];
int visit[105][105];

int dir [2][8] = {{-1,0,0,1,-1,-1,1,1},
                  {0,-1,1,0,-1,1,1,-1}};

bool isValid(int x, int y) {
    if (x < 0 || y < 0 || x > (n-1) || y > (c-1))
        return false;
    return true;
}

int gen(int x, int y) {
    //printf("Debug in %d %d\n", x, y);

    if (!isValid(x,y))
        return 0;

    if (dp[x][y] != -1) {
        return dp[x][y];
    }
    int i, j, mx = 0, nx, ny;
    for (i = 0; i < 4; ++i) {
        nx = x + dir[0][i];
        ny = y + dir[1][i];

        if (!isValid(nx,ny)) {
            continue;
        }
        //printf("new x = %d y = %d visit = %d\n", nx, ny, visit[nx][ny]);
        if (grid[nx][ny] < grid[x][y] && (visit[nx][ny] == 0 || visit[nx][ny] == 2)) {
            visit[nx][ny] = max(visit[nx][ny], 1);
            mx = max(mx, gen(nx, ny));
        }
    }
    //cout << "out " << x << " " << y << " " << mx + 1 << endl;
    visit[x][y] = 2;
    return dp[x][y] = (mx + 1);
}

int main() {

    //freopen("in.txt", "r", stdin);

    int test, mx, i, j;
    char str[110];
    scanf("%d", &test);
    getchar();
    while(test--) {
        scanf("%s %d %d", &str, &n, &c);
        for (i = 0; i < n; ++i) {
            for (j = 0; j < c; ++j) {
                scanf("%d", &grid[i][j]);
            }
        }
        //cout << "Debug 1" << endl;
        memset(dp, -1, sizeof(dp));
        memset(visit, 0, sizeof(visit));

        mx = 0;
        for (i = 0; i < n; ++i) {
            for (j = 0; j < c; ++j) {
                if (visit[i][j] == 0 || visit[i][j] == 2) {
                    visit[i][j] = max(1, visit[i][j]);
                    mx = max(mx, gen(i, j));
                }
            }
        }
//        for (i = 0; i < n; ++i) {
//            for (j = 0; j < c; ++j) {
//                printf("%d ", dp[i][j]);
//            }
//            puts("");
//        }

        printf("%s: %d\n", str, mx);
    }

    return (0);
}
