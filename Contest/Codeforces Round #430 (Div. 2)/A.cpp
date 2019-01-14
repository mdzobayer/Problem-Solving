#include <cstdio>

int main () {

    long long int l, r, x, y, k, a, b;
    double re;

    scanf("%lld %lld %lld %lld %lld",&l, &r, &x, &y, &k);

    for (a = l; a <= r; ++a) {
        re = (double) a / k;
        if (re >= x && re <= y) {
            printf("YES\n");
            return (0);
        }
    }
    printf("NO\n");

    return (0);
}
