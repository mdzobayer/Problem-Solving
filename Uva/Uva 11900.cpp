#include <cstdio>
#include <algorithm>
int main() {

    int n, p, q, egg[35], t, i, j, count, range, c;
    scanf("%d", &t);
    for (i = 1; i <= t; ++i) {
        scanf("%d %d %d", &n, &p, &q);
        for (j = 0; j < n; ++j) {
            scanf("%d", &egg[j]);
        }
        /// No need for sort because its non-decreasing order
        //std::sort(egg, egg + n);
        count = 0;
        range = std::min(p, n);
        for ( j = 0; j < range; ++j) {
            q -= egg[j];
            if (q >= 0) count++;
        }

        printf("Case %d: %d\n", i, count);
    }

    return (0);
}
/**
2
3 2 10
1 2 3
4 5 5
4 4 5 5
**/
