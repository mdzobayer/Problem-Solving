#include <cstdio>

int main() {

    unsigned long long int n;
    while(scanf("%llu", &n) == 1) {
        n = (n + 1) * (n + 1);
        n >>= 1;
        n -= 3;
        n *= 3;
        printf("%llu\n", n);
    }

    return (0);
}
