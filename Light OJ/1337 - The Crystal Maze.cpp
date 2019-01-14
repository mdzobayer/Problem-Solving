    #include <bits/stdc++.h>

    #define SIZE 505
    using namespace std;

    char str[SIZE][SIZE];
    int m, n;

    bool vis[SIZE][SIZE];

    int result[SIZE][SIZE];

    struct point {
        int x, y;
        void operator = (const point &p) {
            this->x = p.x;
            this->y = p.y;
        }
    };

    bool isValid(const point &p) {
        if(p.x < 0 || p.y < 0 || p.x >= m || p.y >= n) {
            return false;
        }
        return true;
    }

    int bfs(point st) {

        point cPoint, nPoint;
        int ans = 0;
        memset(vis, true, sizeof(vis));

        queue < point > q;
        if(str[st.x][st.y] == 'C')
            ++ans;
        vis[st.x][st.y] = false;
        q.push(st);

        while(!q.empty()) {
            cPoint = q.front();
            q.pop();

            //printf("Poped %d %d\n", cPoint.x, cPoint.y);

            nPoint.x = cPoint.x - 1;
            nPoint.y = cPoint.y;
            if(isValid(nPoint)) {
                if(str[nPoint.x][nPoint.y] == 'C' && vis[nPoint.x][nPoint.y]) {
                    vis[nPoint.x][nPoint.y] = false;
                    q.push(nPoint);
                    ++ans;
                }
                else if(str[nPoint.x][nPoint.y] == '.' && vis[nPoint.x][nPoint.y]) {
                    vis[nPoint.x][nPoint.y] = false;
                    q.push(nPoint);
                }
            }

            nPoint.x = cPoint.x + 1;
            nPoint.y = cPoint.y;
            if(isValid(nPoint)) {
                if(str[nPoint.x][nPoint.y] == 'C' && vis[nPoint.x][nPoint.y]) {
                    vis[nPoint.x][nPoint.y] = false;
                    q.push(nPoint);
                    ++ans;
                }
                else if(str[nPoint.x][nPoint.y] == '.' && vis[nPoint.x][nPoint.y]) {
                    vis[nPoint.x][nPoint.y] = false;
                    q.push(nPoint);
                }
            }

            nPoint.x = cPoint.x;
            nPoint.y = cPoint.y + 1;
            if(isValid(nPoint)) {
                if(str[nPoint.x][nPoint.y] == 'C' && vis[nPoint.x][nPoint.y]) {
                    vis[nPoint.x][nPoint.y] = false;
                    q.push(nPoint);
                    ++ans;
                }
                else if(str[nPoint.x][nPoint.y] == '.' && vis[nPoint.x][nPoint.y]) {
                    vis[nPoint.x][nPoint.y] = false;
                    q.push(nPoint);
                }
            }

            nPoint.x = cPoint.x ;
            nPoint.y = cPoint.y - 1;
            if(isValid(nPoint)) {
                if(str[nPoint.x][nPoint.y] == 'C' && vis[nPoint.x][nPoint.y]) {
                    vis[nPoint.x][nPoint.y] = false;
                    q.push(nPoint);
                    ++ans;
                }
                else if(str[nPoint.x][nPoint.y] == '.' && vis[nPoint.x][nPoint.y]) {
                    vis[nPoint.x][nPoint.y] = false;
                    q.push(nPoint);
                }
            }

        }

        return ans;
    }

    void bfs2(point st, int res) {

        point cPoint, nPoint;
        memset(vis, true, sizeof(vis));

        queue < point > q;

        vis[st.x][st.y] = false;
        q.push(st);

        while(!q.empty()) {
            cPoint = q.front();
            result[cPoint.x][cPoint.y] = res;

            q.pop();

            //printf("Poped %d %d\n", cPoint.x, cPoint.y);

            nPoint.x = cPoint.x - 1;
            nPoint.y = cPoint.y;
            if(isValid(nPoint)) {
                if(str[nPoint.x][nPoint.y] == 'C' && vis[nPoint.x][nPoint.y]) {
                    vis[nPoint.x][nPoint.y] = false;
                    q.push(nPoint);
                }
                else if(str[nPoint.x][nPoint.y] == '.' && vis[nPoint.x][nPoint.y]) {
                    vis[nPoint.x][nPoint.y] = false;
                    q.push(nPoint);
                }
            }

            nPoint.x = cPoint.x + 1;
            nPoint.y = cPoint.y;
            if(isValid(nPoint)) {
                if(str[nPoint.x][nPoint.y] == 'C' && vis[nPoint.x][nPoint.y]) {
                    vis[nPoint.x][nPoint.y] = false;
                    q.push(nPoint);
                }
                else if(str[nPoint.x][nPoint.y] == '.' && vis[nPoint.x][nPoint.y]) {
                    vis[nPoint.x][nPoint.y] = false;
                    q.push(nPoint);
                }
            }

            nPoint.x = cPoint.x;
            nPoint.y = cPoint.y + 1;
            if(isValid(nPoint)) {
                if(str[nPoint.x][nPoint.y] == 'C' && vis[nPoint.x][nPoint.y]) {
                    vis[nPoint.x][nPoint.y] = false;
                    q.push(nPoint);
                }
                else if(str[nPoint.x][nPoint.y] == '.' && vis[nPoint.x][nPoint.y]) {
                    vis[nPoint.x][nPoint.y] = false;
                    q.push(nPoint);
                }
            }

            nPoint.x = cPoint.x ;
            nPoint.y = cPoint.y - 1;
            if(isValid(nPoint)) {
                if(str[nPoint.x][nPoint.y] == 'C' && vis[nPoint.x][nPoint.y]) {
                    vis[nPoint.x][nPoint.y] = false;
                    q.push(nPoint);
                }
                else if(str[nPoint.x][nPoint.y] == '.' && vis[nPoint.x][nPoint.y]) {
                    vis[nPoint.x][nPoint.y] = false;
                    q.push(nPoint);
                }
            }

        }

    }


    int main() {

        //freopen("in.txt", "r", stdin);

        int test, t, q, i, j, res;
        point tmp;
        scanf("%d", &test);
        for (t = 1; t <= test; ++t) {
            scanf("%d %d %d", &m, &n, &q);
            getchar();

            for (i = 0; i < m; ++i) {
                scanf("%s", &str[i]);
            }
            /// PreProcess

            memset(result, -1, sizeof(result));

            for (i = 0; i < m; ++i) {
                for (j = 0; j < n; ++j) {
                    if((str[i][j] == '.' || str[i][j] == 'C') && result[i][j] == -1) {
                        tmp.x = i;
                        tmp.y = j;
                        res = bfs(tmp);
                        bfs2(tmp, res);
                    }
                }
            }
    //        for (i = 0; i < m; ++i) {
    //            for (j = 0; j < n; ++j) {
    //                printf("%d ", result[i][j]);
    //            }
    //            puts("");
    //        }


            printf("Case %d:\n", t);
            for (i = 0; i < q; ++i) {
                scanf("%d %d", &tmp.x, &tmp.y);
                --tmp.x;
                --tmp.y;
                if(result[tmp.x][tmp.y] == -1) {
                    printf("0\n");
                }
                else {
                    printf("%d\n", result[tmp.x][tmp.y]);
                }
            }
        }

        return (0);
    }

