
#include <bits/stdc++.h>
using namespace std;

/// Read & Write to File Short-Cut
#define fRead(x) freopen(x, "r", stdin)
#define fWrite(x) freopen(x, "w", stdout)
/// Data type Short-Cut
#define LLI long long int
#define ULL unsigned long long int
#define ff first
#define ss second
#define mk make_pair
#define phb push_back
#define ppb pop_back
#define phf push_front
#define ppf pop_front
/// Input Short-Cut
#define scan(a) scanf("%d", &a);
#define scan2(a, b) scanf("%d %d", &a, &b);
#define scan3(a, b, c) scanf("%d %d %d", &a, &b, &c);
#define scan4(a, b, c, d) scanf("%d %d %d %d", &a, &b, &c, &d);
/// Utility
#define SQR(x) ((x) * (x))
#define PI acos(-1.0)
/// Fast Read and de-active buffer flash
#define FastRead std::cin.sync_with_stdio(false);std::cin.tie(nullptr);

///======================== Let's GO ========================

int cuttingPoint[50 + 5], dp[50 + 5][50 + 5];

int minimumCost(int left, int right) {

    if (dp[left][right] != -1) return dp[left][right];

    if (left + 1 == right) {
        return dp[left][right] = 0;
    }
    int i;
    dp[left][right] = INT_MAX;
    for (i = left + 1; i < right; ++i) {
        dp[left][right] = min(dp[left][right], cuttingPoint[right] - cuttingPoint[left]
                      + minimumCost(left, i) + minimumCost(i, right));
    }

    return dp[left][right];
}

int main() {
    FastRead
    int l, n, i;
    while(scanf("%d", &l) == 1) {
        if (l == 0) break;
        scanf("%d", &n);
        memset(dp, -1, sizeof(dp));
        cuttingPoint[0] = 0;
        for (i = 1; i <= n; ++i) {
            scanf("%d", &cuttingPoint[i]);
        }
        cuttingPoint[i] = l;
        /// No call DP function minimumCost
        printf("The minimum cutting is %d.\n", minimumCost(0,i));
        for (int j = 0; j <= n + 2; ++j) {
            for (int k = 0; k <= n + 2; ++k) {
                printf("%d ", dp[j][k]);
            }
            printf("\n");
        }
    }

    return (0);
}
