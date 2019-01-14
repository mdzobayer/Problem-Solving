#include <bits/stdc++.h>
#define ll long long int

using namespace std;

/* Count how many d's occur in a single n */
ll popcount(ll n, ll d) {
    ll result = 0;
    while (n != 0) {
        result += ((n%10) == d);
        n /= 10;
    }
    return result;
}

/* Compute how many d's occur all numbers from 1 to n */
ll Count(ll n, ll d) {
    /* Special case single-digit n */
    if (n < 10) return (d > 0 && n >= d);

    /* If n does not end in 9, recurse until it does */
    if ((n % 10) != 9) return popcount(n, d) + Count(n - 1, d);

    return (10 * Count(n / 10, d) + (n / 10) + (d > 0));
}

int main() {

    //freopen("in.txt", "r", stdin);

    ll test, t, m, n, r1, r2;
    scanf("%lld", &test);
    for (t = 1; t <= test; ++t) {
        scanf("%lld %lld", &m, &n);


        r1 = Count(n, 0);


        if (m > 0) --m;

        r2 = Count(m, 0);

        r1 -= r2;
        if (m == 0) ++r1;

        printf("Case %lld: %lld\n", t, r1);
    }


    return (0);
}
