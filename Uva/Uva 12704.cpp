#include <cstdio>
#include <cmath>
int power(int x, int y) {
    int result = x;
    for (int i = 1; i < y; ++i) {
        result *= x;
    }
    return result;
}
int main() {
    freopen("input.txt", "r", stdin);
    int test, x, y, r;
    float minDistance, maxDistance, distanceFromOrigin;
    scanf("%d", &test);
    while(test--) {
        scanf("%d %d %d", &x, &y, &r);
        distanceFromOrigin = sqrt(power(x,2) + power(y,2));
        minDistance = r - distanceFromOrigin;
        maxDistance = r + distanceFromOrigin;
        printf("%0.2f %0.2f\n", minDistance, maxDistance);
    }

    return (0);
}
