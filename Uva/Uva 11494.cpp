#include <cstdio>

int abs(int x) {
    if (x < 0)
        return x *= -1;
    return x;
}

int main() {

    int x1, x2, y1, y2;
    while(scanf("%d %d %d %d", &x1, &y1, &x2, &y2) == 4) {
        if (x1 == 0 || y1 == 0 || x2 == 0 || y2 == 0) {
            break;
        }
        if (x1 == x2 && y1 == y2) {
            printf("0\n");
        }
        else if (x1 == x2) {
            printf("1\n");
        }
        else if (y1 == y2) {
            printf("1\n");
        }
        else if (abs(x1 - x2) == abs(y1 - y2)) {
            printf("1\n");
        }
        else {
            printf("2\n");
        }
    }

    return (0);
}
