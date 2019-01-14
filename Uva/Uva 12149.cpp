#include <cstdio>

int main() {

    int n, n2;
    while(scanf("%d", &n) && n) {
        n2 = n;
        n *= 2;
        n += 1;
        n2 = n2 * n2 + n2;
        n *= n2;
        n /= 6;
        printf("%d\n", n);
    }

    return (0);
}
