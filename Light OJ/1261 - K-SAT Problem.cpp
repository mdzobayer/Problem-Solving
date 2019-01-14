#include <bits/stdc++.h>

using namespace std;

int main() {

    //freopen("in.txt", "r", stdin);

    int test, x, t, n, m, s, k, i, j, p, sol[35], choose[35][35];
    bool flag;
    scanf("%d", &test);
    for (t = 1; t <= test; ++t) {
        scanf("%d %d %d", &n, &m, &k);

        for (i = 0; i < n; ++i) {
            for (j = 0; j < k; ++j) {
                scanf("%d", &choose[i][j]);

            }
        }
        memset(sol, -1, sizeof(sol));

        scanf("%d", &p);
        for (i = 0; i < p; ++i) {
            scanf("%d", &x);
            if (x < 0)
                sol[abs(x)] = -1;
            else sol[x] = 1;

        }
        printf("Case %d: ", t);
        for (i = 0; i < n; ++i) {
            flag = false;
            for (j = 0; j < k; ++j) {
                x = abs(choose[i][j]);
                //cout << choose[i][j] << endl;
                if (choose[i][j] < 0) {
                    if (sol[x] == -1) {
                        flag = true;
                        break;
                    }
                }
                else {
                    if (sol[x] == 1) {
                        flag = true;
                        break;
                    }
                }

            }
            if (flag == false) {
                printf("No\n");
                break;
            }
        }
        if (flag) {
            printf("Yes\n");
        }
    }

    return (0);
}
