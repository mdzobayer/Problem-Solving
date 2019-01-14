#include <bits/stdc++.h>


using namespace std;

int main() {

    //freopen("in.txt", "r", stdin);

    int test, t, n, p, q, i, weight[35], wt, mx;

    scanf("%d", &test);
    for (t = 1; t <= test; ++t) {
        scanf("%d %d %d", &n, &p, &q);
        for (i = 0; i < n; ++i) {
            scanf("%d", &weight[i]);
        }
        sort(weight, weight+n);
        wt = 0;
        mx = 0;
        for (i = 0; i < n && mx < p; ++i) {
            wt += weight[i];
            if (wt > q) break;
            ++mx;
        }
        printf("Case %d: %d\n", t, mx);
    }


    return (0);
}
