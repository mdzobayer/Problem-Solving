#include <cstdio>

int main() {

    int test, e, f, c, soda;
    scanf("%d", &test);
    while(test--) {
        scanf("%d%d%d", &e, &f, &c);
        soda = 0;
        e += f;
        while(e >= c) {
            f = e % c;
            e /= c;
            soda += e;
            e += f;
        }
        printf("%d\n", soda);
    }

    return (0);
}
