#include <cstdio>

int main() {
    int a, b, c, d, i, j, k, l;

    for ( i = 6; i <= 200; i++) {
        a = i * i * i;
        for (j = 2; j < i; j++) {
            b = j * j * j;
            for (k = j; k < i; k++) {
                c = k * k * k;
                for (l = k; l < i; l++) {
                    d = l * l * l;
                    if ( a == (b + c + d)) {
                        printf("Cube = %d, Triple = (%d,%d,%d)\n", i, j, k, l);
                    }
                }
            }
        }
    }

    return (0);
}
