#include <cstdio>

int main() {

    int test, a, b, c, d, e, f, g, h, Case = 1;

    scanf("%d", &test);
    while(test--) {
        scanf("%d:%d %d:%d", &a, &b, &c, &d);
        a = a * 60 + b;
        c = c * 60 + d;
        scanf("%d:%d %d:%d", &e, &f, &g, &h);
        e = e * 60 + f;
        g = g * 60 + h;

        printf("Case %d: ", Case++);
        if (e > c || a > g) {
            printf("Hits Meeting\n");
        }
        else {
            printf("Mrs Meeting\n");
        }
    }

    return (0);
}
