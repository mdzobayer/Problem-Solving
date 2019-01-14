#include <cstdio>

int gcd (const int& n1, const int& n2) {
    int i, gcd = 0;
    for(i = 1; i <= n1 && i <= n2; ++i)
    {
        if(n1 % i == 0 && n2 % i == 0)
            gcd = i;
    }
    return (gcd);
}

int main() {

    int n, i, j, g;
    while ( scanf("%d", &n) && (n > 0)) {
        g = 0;
        for (i = 1; i < n; i++) {
            for (j = i + 1; j <= n; j++) {
                g += gcd(i, j);
            }
        }
        printf("%d\n", g);

    }

    return (0);
}
