#include <bits/stdc++.h>
#define SIZE 25

using namespace std;
int w, h;
char s[SIZE][SIZE];
bool v[SIZE][SIZE];
int dir [2][8] = {{-1,0,0,1,-1,-1,1,1},
                  {0,-1,1,0,-1,1,1,-1}};

struct point {
    int x, y;
};

bool isValid(const point & p) {
    if (p.x < 0 || p.x >= h || p.y < 0 || p.y >= w)
        return false;
    return true;
}

int bfs(point cP) {
    int i, Count = 0;
    point nP;
    queue < point > q;
    v[cP.x][cP.y] = false;
    q.push(cP);

    while(!q.empty()) {
        cP = q.front();
        ++Count;
        q.pop();

        for (i = 0; i < 4; ++i) {
            nP.x = cP.x + dir[0][i];
            nP.y = cP.y + dir[1][i];
            if (!isValid(nP)) {
                continue;
            }
            if (v[nP.x][nP.y] && s[nP.x][nP.y] == '.') {
                v[nP.x][nP.y] = false;
                q.push(nP);
            }
        }
    }
    return Count;
}

int main() {

    freopen("in.txt", "r", stdin);

    int test, t, i, ans, j;
    point tmp;
    scanf("%d", &test);
    for (t = 1; t <= test; ++t) {
        scanf("%d %d", &w, &h);
        getchar();
        for (i = 0; i < h; ++i) {
            scanf("%s", &s[i]);
        }
        memset(v, true, sizeof(v));
        for (i = 0; i < h; ++i) {
            for (j = 0; j < w; ++j) {
                if (s[i][j] == '@') {
                    tmp.x = i;
                    tmp.y = j;
                    ans = bfs(tmp);
                    j = w;
                    i = h;
                }
            }
        }
        printf("Case %d: %d\n", t, ans);
    }


    return (0);
}
