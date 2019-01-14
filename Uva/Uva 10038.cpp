#include <cstdio>
#include <cmath>
#include <algorithm>

int main() {

    int n, i, a[3005], b[3005];
    bool flag;
    while(scanf("%d", &n) == 1) {
        flag = true;
        for (i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }

        for (i = 0; i < n - 1; i++) {
            b[i] = abs(a[i + 1] - a[i]);
        }
        std::sort(b, b + i);
        for (i = 1; i < n; i++) {
            if (b[i] == b[i - 1]) {
                flag = false;
                break;
            }
        }
        if (flag)
            printf("Jolly\n");
        else
            printf("Not jolly\n");
    }

    return (0);
}
