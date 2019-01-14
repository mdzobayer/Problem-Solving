#include <cstdio>
#include <cstdlib>
#include <cmath>


int main() {

    int r, d, xi, yi, ri, i, n, count = 0;
    int distance;
    scanf("%d %d %d", &r, &d, &n);

    for (i = 0; i < n; ++i) {
        scanf("%d %d %d", &xi, &yi, &ri);
        distance = sqrt((xi * xi) + (yi * yi));

        if ((distance - ri) >= (r - d) && (distance + ri) <= r) {
            count += 1;
        }
    }

    printf("%d\n", count);

    return (0);
}
