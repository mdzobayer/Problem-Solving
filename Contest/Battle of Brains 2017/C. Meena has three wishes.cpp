#include <cstdio>

int main() {

    int test, m;
    double x;
    scanf("%d", &test);
    while(test--) {
        scanf("%d", &m);
        x = m * (m / 2.0);
        printf("%0.2lf\n", x);
    }

    return (0);
}
