#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int n, q, d, m, arr[200+5];

//ll dp[203][23][12];

ll solve (int pos, int rem, int cnt) {
    if (cnt == m && rem == 0) return 1;

    if (pos >= n) return 0;

    ll ans = 0;
    ans += solve(pos + 1, rem, cnt);    // Skip Current element
    ans += solve(pos + 1, (rem + arr[pos]) % d, cnt + 1);   // Add current element

    return ans;
}


int main() {

    int test, t, i;
    scanf("%d", &test);
    for (t = 1; t <= test; ++t) {
        scanf("%d %d", &n, &q);
        for (i = 0; i < n; ++i) {
            scanf("%d", &arr[i]);
        }

        printf("Case %d:\n", t);
        for (i = 0; i < q; ++i) {
            scanf("%d %d", &d, &m);

            //memset(dp, -1, sizeof(dp));

            printf("%lld\n", solve(0, 0, 0));
        }
    }

    return (0);
}