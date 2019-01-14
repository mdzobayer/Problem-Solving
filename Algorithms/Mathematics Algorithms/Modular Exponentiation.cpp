#include <cstdio>

int bigMod(int a, int b, int m) {
    if (b == 0) return 1;

    int x = bigMod(a, b / 2, m);
    //printf("x is %d\n", x);
    x = (x * x) % m;
    if (b % 2 == 1) {
        x = (x * a) % m;
    }
    return x;
}

int main() {

    printf("From main %d\n", bigMod(3, 10, 5));

    return (0);
}
