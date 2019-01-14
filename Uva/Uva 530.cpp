#include <cstdio>

int main() {
    freopen("input.txt", "r", stdin);
    unsigned long long int n, m, t, p, q, result, tn, tm;
    while(scanf("%llu %llu", &n, &m)) {
        if (n == 0 || m == 0) break;
        p = q = 1;
        t = n - m;
        tn = n;
        tm = m;
        while(n > t) {
            p *= n;
            --n;
        }
        while (m > 1) {
            q *= m;
            --m;
        }
        result = p / q;
        printf("%llu things taken %llu at a time is %llu exactly.\n", tn, tm, result);
    }

    return (0);
}
