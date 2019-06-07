#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int n, q, d, m, arr[200+5];

ll dp[203][46][12];

ll solve (int pos, int rem, int cnt) {
    if (cnt == 0 && rem == 0) {
        return 1;
    }
    //printf("pos %d rem %d cnt %d\n", pos, rem, cnt);
    if (pos < 0 || cnt < 0) return 0;

    

    int nRem = -100;
    if (rem < 0) {
        nRem = (-1) * rem;
        nRem += 23;
    }

   // printf("pos %d rem %d cnt %d\n", pos, rem, cnt);
    
    if (nRem == -100) {
        if (dp[pos][rem][cnt] != -1) {
            return dp[pos][rem][cnt];
        }
    }
    else {
        if (dp[pos][nRem][cnt] != -1) {
            return dp[pos][nRem][cnt];
        }
    }
    //printf("pos %d rem %d nRem %d cnt %d\n", pos, rem, nRem, cnt);

    ll ans = 0;
    ans += solve(pos - 1, rem, cnt);    // Skip Current element
    ans += solve(pos - 1, (rem + arr[pos]) % d, cnt - 1);   // Add current element

    if (nRem == -100)
        dp[pos][rem][cnt] = ans;
    else 
        dp[pos][nRem][cnt] = ans;

    return ans;
}


int main() {

    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

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

            if (m <= n) {

                memset(dp, -1, sizeof(dp));

                printf("%lld\n", solve(n - 1, 0, m));
            }
            else {
                puts("0");
            }
        }
    }

    return (0);
}