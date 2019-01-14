#include <cstdio>
#include <cmath>
int main() {
    long long int n;
    int i, ans;
    while(scanf("%lld", &n) == 1) {
        if (n == 0)
            break;
        printf("%lld : ", n);
        ans = 0;
        if (n % 2 == 0) {
            ++ans;
            while(n % 2 == 0) {
                n /= 2;
            }
        }
        for (i = 3; i <= sqrt(n); i += 2) {
            if (n % i == 0)
                ++ans;
            while(n % i == 0) {
                n /= i;
            }
        }
        if (n != 1) ++ans;
        printf("%d\n", ans);

    }
    return (0);
}
