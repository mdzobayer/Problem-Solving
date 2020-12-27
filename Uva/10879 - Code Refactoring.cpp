#include <bits/stdc++.h>
#define ll long long int
#define pb push_back

using namespace std;

vector < ll > factors (ll n) {
    vector < ll > f;

    for (ll x = 2; x * x <= n; ++x) {
        while(n % x == 0) {
            f.pb(x);

            n /= x;
        }
    }

    if (n > 0)
        f.pb(n);

    return f;
}

int main () {

    //freopen("in.txt", "r", stdin);

    ll test, t, n, i, len, a, b, c, d;
    vector < ll > factorList;

    scanf("%lld", &test);
    for (t = 0; t < test; ++t) {
        scanf("%lld", &n);

        factorList = factors(n);
        len = factorList.size();
        len /= 2;

        a = 1;
        // printf("Factors of %lld = ", n);
        // for (i = 0; i < factorList.size(); ++i) {
        //     printf(" %lld", factorList[i]);
        // }
        // puts("");

        a = factorList[0];
        c = a * factorList[1]; 

        b = n / a;
        d = n / c;

        printf("Case #%lld: %lld = %lld * %lld = %lld * %lld\n", t + 1, n, a, b, c, d);
    }

    return (0);
}