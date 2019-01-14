#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main() {

    int test, t;
    ll n, i, x, result;

    vector < ll > vt;

    scanf("%d", &test);
    for (t = 1; t <= test; ++t) {
        vt.clear();
        scanf("%lld", &n);
        for (i = 1; i < n; ++i) {
            x = i * i;
            if (x >= n) break;
            result = n - x;
            if ((result % i == 0) &&(result / i) > 0)
                vt.push_back(result);
        }
        printf("Case %d:", t);
        for (i = vt.size() - 1; i >= 0; --i) {
            printf(" %lld", vt[i]);
        }
        puts("");
    }

    return (0);
}
