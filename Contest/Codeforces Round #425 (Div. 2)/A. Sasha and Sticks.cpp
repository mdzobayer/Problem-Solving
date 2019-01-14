#include <cstdio>
#define ull unsigned long long int

int main() {
    ull n, k;
    scanf("%llu %llu", &n, &k);
    if (n % k == 0) {
        if ((n / k) % 2 == 0) {
            printf("NO\n");
        }
        else {
            printf("YES\n");
        }
    }
    else {
        if ((n / k) % 2 != 0) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
    }

    return (0);
}
