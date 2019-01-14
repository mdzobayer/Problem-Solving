#include <bits/stdc++.h>
#define ll long long int
#define SIZE 300000+5
using namespace std;
ll indexN[SIZE], hookN[SIZE];

int main() {

    //freopen("in.txt", "r", stdin);

    int test, t, x, y, n, m, i;
    ll ans;
    scanf("%d", &test);
    for (t = 1; t <= test; ++t) {
        scanf("%d %d", &n, &m);
        memset(indexN, 0, sizeof(indexN));
        memset(hookN, 0, sizeof(hookN));

        for (i = 0; i < n; ++i) {
            scanf("%d %d", &x, &y);
            indexN[x] += 1;
            hookN[y] += 1;
        }

        for (i = 1; i < SIZE; ++i) {
            indexN[i] += indexN[i-1];
            hookN[i] += hookN[i-1];

        }

//        for (i = 1; i < 15; ++i) {
//            printf("%d ", hookN[i]);
//        }
//        puts("");
//        for (i = 1; i < 15; ++i) {
//            printf("%d ", indexN[i]);
//        }
//        puts("");

        ans = 0;
        for (i = 0; i < m; ++i) {
            scanf("%d %d", &x, &y);
            ll total_hook,total_pos;
            total_hook=hookN[y-1];
            total_pos=indexN[x-1];
            if(total_hook<total_pos) ans+=total_pos-total_hook;
            total_hook=n-hookN[y];
            total_pos=n-indexN[x];
            if(total_hook<total_pos) ans+=total_pos-total_hook;
        }
        printf("Case %d: %lld\n", t, ans);
    }

    return (0);
}
