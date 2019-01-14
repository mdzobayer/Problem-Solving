#include <cstdio>
#define ull unsigned long long int

ull mod = 1e9 + 7;

int main() {

    ull test, t, n, a, b, c, d, e, x, y, result;
    scanf("%llu", &test);

    for (t = 1; t <= test ; ++t) {
        scanf("%llu", &n);

        a = n; b = n + 1; c = (2*n) + 1;
        if (a % 6 == 0)
            a /= 6;
        else if (b % 6 == 0)
            b /= 6;
        else if (c % 6 == 0)
            c /= 6;
        else if (a % 2 == 0) {
            a /= 2;
            if (b % 3 == 0)
                b /= 3;
            else c /= 3;
        }
        else if (a % 3 == 0) {
            a /= 3;
            if (b % 2 == 0)
                b /= 2;
            else c /= 2;
        }
        else {
            if (b % 2 == 0) {
                b /= 2;
                c /= 3;
            }
            else {
                b /= 3;
                c /= 2;
            }
        }
        d = n; e = n + 1;
        if (d % 2 == 0)
            d /= 2;
        else e /= 2;

        x = (((a * b) % mod) * (c % mod)) % mod;
        y = (d * e) % mod;
        //printf("%llu %llu\n",x, y);
        result = (x + y) % mod;
        printf("Case %llu: %llu\n", t, result);
    }

    return (0);
}
