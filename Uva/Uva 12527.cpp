#include <cstdio>
#include <cstring>
#define ld long long int
void swap(ld & x, ld & y) {
    ld temp = x;
    x = y;
    y = temp;
}
bool dup[12];
bool isDuplicate (ld n) {
    ld t;
    memset(dup, true, sizeof(dup));
    while (n > 0) {
        t = n % 10;
        n /= 10;
        if (dup[t] == true)
            dup[t] = false;
        else
            return false;
    }
    return true;
}
int main() {
    freopen("input.txt", "r", stdin);
    ld n, m, i, count;
    while(scanf("%lld %lld", &n, &m) == 2) {
        if (n > m)
            swap(n,m);
        count = 0;
        for (i = n; i <= m; ++i) {
            if (isDuplicate(i)) {
                ++count;
            }
        }
        printf("%lld\n", count);
    }

    return (0);
}
