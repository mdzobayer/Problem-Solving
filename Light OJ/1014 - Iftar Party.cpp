#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int test, i, j;
    long long int p, l, n, range;
    scanf("%d", &test);
    for( i = 1; i <= test; ++i) {
        scanf("%lld %lld", &p, &l);
        printf("Case %d:", i);
        n = p - l;
        if (n <= l || n < 0) {
            printf(" impossible\n");
            continue;
        }
        if (n == 1) {
            puts(" 1");
            continue;
        }
        range = sqrt(n) + 1;
        vector<long long int> vt;
        for ( j = 1; j <= range && j < n; ++j) {
            if (n % j == 0) {
                vt.push_back(j);
                if (j != (n/j))
                    vt.push_back(n / j);
            }
        }
        sort(vt.begin(), vt.end());
        for ( j = 0; j < vt.size(); ++j) {
            if (vt[j] > l)
                printf(" %d", vt[j]);
        }
        printf("\n");
    }

    return (0);
}
