#include <cstdio>

int main() {
    int n = 4, i , j;
    for (i = 1; i < (1 << n); ++i) {
        for (j = 0; j < n; ++j)
            if ((i & (1 << j)) > 0)
                printf("%d", j + 1);
        printf("\n");
    }
    return (0);
}
