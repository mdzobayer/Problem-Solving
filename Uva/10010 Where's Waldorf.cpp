#include <bits/stdc++.h>


using namespace std;
int test, t, m, n, k;

char grid[55][55], s[55];

int dir [2][8] = {{-1,0,0,1,-1,-1,1,1},
                  {0,-1,1,0,-1,1,1,-1}};


void findAndPrint() {

    int i, j, d, idx, x, y;

    for (i = 0; i < m; ++i) {
        for (j = 0; j < n; ++j) {
                if (grid[i][j] == s[0])
            for (d = 0; d < 8; ++d) {
                x = i; y = j; idx = 0;

                while(grid[x][y] == s[idx]) {
                    ++idx;

                    if (s[idx] == '\0') {
                        printf("%d %d\n", i+1, j+1);
                        return;
                    }

                    x = x + dir[0][d];
                    y = y + dir[1][d];

                    if (x < 0 || x > (m - 1) || y < 0 || y > (n-1))
                        break;
                }
            }
        }
    }
}


int main() {

    //freopen("in.txt", "r", stdin);

    int i, j;

    while(scanf("%d", &test) == 1) {
        getchar();
        for (t = 0; t < test; ++t) {
            if (t > 0) puts("");

            scanf("%d %d", &m, &n);
            getchar();
            for (i = 0; i < m; ++i) {
                scanf("%s", &grid[i]);
                for (j = 0; j < n; ++j) {
                    grid[i][j] = tolower(grid[i][j]);
                }
            }
            scanf("%d", &k);
            getchar();
            for (i = 0; i < k; ++i) {
                scanf("%s", &s);
                for (j = 0; s[j]; ++j) {
                    s[j] = tolower(s[j]);
                }

                findAndPrint();
            }
        }
    }

    return (0);
}
