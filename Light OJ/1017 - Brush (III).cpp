#include <bits/stdc++.h>
#define ll long long int
using namespace std;

vector <int> vt;
int dp[110][110], n, k, w;

int solve(int index, int ava) {

    if (ava == 0) return (0);
    if(index >= n) return (0);

    if(dp[index][ava] != -1) return dp[index][ava];

    int x = upper_bound(vt.begin(), vt.end(), vt.at(index) + w) - vt.begin();
    int y = x - index;
    //printf("x = %d index = %d y = %d\n", x, index, y);

    dp[index][ava] = max(y+solve(index+y, ava - 1), solve(index + 1, ava));

    return dp[index][ava];
}

int main() {

    //freopen("in.txt", "r", stdin);

    int test, t, i, x, y;
    scanf("%d", &test);
    for (t = 1; t <= test; ++t) {
        scanf("%d %d %d", &n, &w, &k);
        vt.clear();

        for (i = 0; i < n; ++i) {
            scanf("%d %d", &x, &y);
            vt.push_back(y);
        }
        sort(vt.begin(), vt.end());

        memset(dp, -1, sizeof(dp));
        printf("Case %d: %d\n", t, solve(0, k));
    }

    return (0);
}
