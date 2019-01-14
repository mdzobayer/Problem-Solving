#include <cstdio>
#include <cstring>

#define lli long long int

lli sums[100010], sum, n, m, test, t, i, x, k, count;
int dp1[100015];
int dp2[100015];

int countWays(lli l, lli r) {
    /// If same situation before
    if (dp1[l] == 0 && dp2[r] == 0) {
        return 0;
    }

    if (l == r) {
        printf("Combinations %lld %lld\n", l, r);
        //printf("same index %lld\n", r);
        if ((sums[r] - sums[l - 1]) % m == 0) {
            ++count;
            printf("sum is %lld\n", (sums[r] - sums[l - 1]));
            return 0;
        }
        else {
            return 0;
        }
    }
    /*
    if (sums[l] % m == 0){
        //printf("YES\n");
        ++count;
    }
    */
    printf("Combinations %lld %lld\n", l, r);
    if ((sums[r] - sums[l - 1]) % m == 0){
        printf("sum is no %lld\n", (sums[r] - sums[l - 1]));
        //printf(" NO\n");
        ++count;
    }
    int i;
    for (i = l; i < r; ++i) {
        countWays(l, i);
        dp1[l] = 0;
        dp2[i] = 0;
        countWays(i + 1, r);
        dp1[i + 1] = 0;
        dp2[r] = 0;
    }

    return 0;
}

int main() {

    scanf("%lld", &test);
    for (t = 1; t <= test; ++t) {
        sums[0] = 0;
        memset(dp1, 1, sizeof(dp1));
        memset(dp2, 1, sizeof(dp2));
        scanf("%lld %lld", &n, &m);
        for (i = 1; i <= n; ++i) {
            scanf("%lld", &x);
            sums[i] = sums[i - 1] + x;
        }
        count = 0;
        countWays(1, n);
        dp1[1] = 0;
        dp2[n] = 0;
        printf("Case %lld: %lld\n", t, count);
    }

    return (0);
}
