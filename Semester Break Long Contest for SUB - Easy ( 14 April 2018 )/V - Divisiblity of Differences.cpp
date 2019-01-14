#include <bits/stdc++.h>

using namespace std;
#define SIZE 100005
#define pb push_back

vector < int > pre[SIZE];
int n, k, m, i, x;
int main() {

    scanf("%d %d %d", &n, &k, &m);
    for (i = 0; i < n; ++i) {
        scanf("%d", &x);
        pre[x%m].pb(x);
    }
    for (i = 0; i < m; ++i) {
        if (pre[i].size() >= k) {
            puts("Yes");
            printf("%d", pre[i][0]);
            for (x = 1; x < k; ++x) {
                printf(" %d", pre[i][x]);
            }
            puts("");
            return (0);
        }
    }
    puts("No");

    return (0);
}
