#include <bits/stdc++.h>
#define ull unsigned long long int

using namespace std;



ull solve(int n, int m, int k) {
    if (k > n || k > m) return (0);
    else if (k == 0) return 1;
    else if (m == 1) return n;


    ull ans;
    return ans = n * solve(n - 1, m - 1, k - 1) + solve(n, m - 1, k);
}

int main() {

    int test, t, n, k;
    //memset(dp, -1, sizeof(dp));
    scanf("%d", &test);
    for (t = 1; t <= test; ++t) {
        scanf("%d %d", &n, &k);
        printf("Case %d: ", t);

        printf("%llu\n", solve(n, n, k));
    }

    return (0);
}
