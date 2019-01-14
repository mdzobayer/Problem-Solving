#include <cstdio>

int main() {

    long long int length[60], i, n;
    while(scanf("%lld", &n) == 1) {
        if (n == 0)
            break;
        length[0] = 0;
        length[1] = 1;
        for (i = 2; i <= n + 1; ++i) {
            length[i] = length[i - 1] + length[i - 2];
        }
        printf("%lld\n", length[n+1]);
    }
    return (0);
}
