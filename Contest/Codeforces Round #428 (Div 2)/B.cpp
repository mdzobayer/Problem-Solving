#include <cstdio>

int main() {

    int n, k, i, x, totalSeat;
    bool flag = true;
    scanf("%d %d", &n, &k);
    totalSeat = n * 8;
    for (i = 0; i < k; ++i) {
        scanf("%d", &x);
        if (totalSeat < x) {
            flag = false;
            break;
        }
        if (x % 2 == 0) {
            totalSeat -= x;
        }
        else {
            totalSeat -= (x + 1);
        }
    }
    if (!flag || totalSeat <= 0) {
        printf("NO\n");
    }
    else {
        printf("YES\n");
    }

    return (0);
}
