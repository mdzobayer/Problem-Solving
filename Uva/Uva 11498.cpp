#include <cstdio>

int main() {
    int t, n, m, x, y;

    while(scanf("%d", &t) == 1) {
        if (t == 0)
            break;
        scanf("%d %d", &n, &m);
        for (int i = 0; i < t; ++i) {
            scanf("%d %d", &x, &y);
            if ( n == x || m == y)
                printf("divisa\n");
            else if ( x > n && y > m)
                printf("NE\n");
            else if ( x < n && y > m)
                printf("NO\n");
            else if ( x < n && y < m)
                printf("SO\n");
            else
                printf("SE\n");
        }
    }


    return (0);
}
