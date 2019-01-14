#include <cstdio>
#include <cstring>
int main() {

    int test, n, speed[1024], minSpeed, i, j;
    scanf("%d", &test);
    for( i = 1; i <= test; ++i) {
        minSpeed = 0;
        memset(speed, 0, sizeof(speed));
        scanf("%d", &n);
        for ( j = 0; j < n; ++j) {
            scanf("%d", &speed[j]);
        }
        minSpeed = speed[0];
        for ( j = 1; j < n; ++j) {
            if (speed[j] > minSpeed)
                minSpeed = speed[j];
        }
        printf("Case %d: %d\n", i, minSpeed);
    }

    return (0);
}
