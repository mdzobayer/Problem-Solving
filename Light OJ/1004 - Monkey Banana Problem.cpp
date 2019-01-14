#include <bits/stdc++.h>
#define ll long long int

using namespace std;

vector < int > arr[200+5];
ll dp[200+5][100+5];
int n;

ll solve (int r, int c) {
    if (c < 0) return (0);
    if (r > (n+n)) return (0);
    if (arr[r].size() <= c) return (0);


    if (dp[r][c] != -1) return dp[r][c];
    int newC;
    if (r + 1 <= n) newC = c + 1;
    else newC = c - 1;

    ll & ans = dp[r][c];
    ans = LONG_MIN;

//    if (r == 6 && c == 1) {
//        printf("--- %d %d %lld\n", r + 1, newC, dp[r+1][newC]);
//    }

    ans = max(solve(r + 1, c), ans);
    ans = max(solve(r + 1, newC), ans);
    ans += arr[r][c];

    return ans;
}

int main() {

    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int test, t, x, i, j, tmp;
    scanf("%d", &test);
    for (t = 1; t <= test; ++t) {

        scanf("%d", &n);
        // Reset
        for (i = 0; i <= n * 2 + 2; ++i) {
            arr[i].clear();
        }
        // Input
        for (i = 1, j = 1; i <= n; ++i) {
            for (x = 0; x < i; ++x) {
                scanf("%d", &tmp);
                arr[j].push_back(tmp);
            }
            ++j;
        }
        for (i = n - 1; i > 0; --i) {
            for (x = 0; x < i; ++x) {
                scanf("%d", &tmp);
                arr[j].push_back(tmp);
            }
            ++j;
        }

        // Input Verification
//        for (i = 1; i < (n * 2); ++i) {
//            for (j = 0; j < arr[i].size(); ++j) {
//                printf("%d ", arr[i][j]);
//            }
//            puts("");
//        }
        memset(dp, -1, sizeof(dp));
        printf("Case %d: %lld\n", t, solve(1, 0));

        // DP matrix print
//        for (i = 1; i < (n * 2); ++i) {
//            for (j = 0; j < arr[i].size(); ++j) {
//                printf("%lld ", dp[i][j]);
//            }
//            puts("");
//        }

    }


    return (0);
}
