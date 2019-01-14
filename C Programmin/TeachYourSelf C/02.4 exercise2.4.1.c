#include <stdio.h>

int main() {
    int i = 0;
    for (i; i < 100; i++) {
        printf("%d ", i + 1);
    }
    putchar('\n');
    putchar('\n');


    int j = 17;
    for (j; j <=100; ++j) {
        if((j % 17) == 0) {
            printf("%d ", j);
        }
    }
    putchar('\n');

    return (0);
}
