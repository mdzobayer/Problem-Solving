#include <cstdio>

int main() {

    int s, v1, v2, t1, t2, x, y;
    scanf("%d %d %d %d %d", &s, &v1, &v2, &t1, &t2);
    x = (s * v1) + (2 * t1);
    y = (s * v2) + (2 * t2);
    if (x < y) {
        printf("First\n");
    }
    else if (y < x) {
        printf("Second\n");
    }
    else {
        printf("Friendship\n");
    }

    return (0);
}
