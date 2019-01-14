#include <bits/stdc++.h>
#define ll long long int

using namespace std;


int main() {

    //freopen("in.txt", "r", stdin);

    ll test, t, n, i, sum, x;
    scanf("%lld", &test);
    for (t = 1; t <= test; ++t) {
        scanf("%lld", &n);
        sum = 0;
        for (i = 0; i < n; ++i) {
            scanf("%lld", &x);
            if (x > 0)
                sum += x;
        }
        printf("Case %lld: %lld\n", t, sum);
    }

    return (0);
}
