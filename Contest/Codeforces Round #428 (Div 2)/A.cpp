#include <cstdio>

int main() {
    int n, k, i, x, sum = 0, day = 0;
    scanf("%d %d", &n, &k);
    for (i = 0; i < n; ++i) {
        scanf("%d", &x);
        sum += x;
        if (sum > 8) {
            k -= 8;
            sum -= 8;
            ++day;
        }
        else {
            k -= sum;
            sum = 0;
            ++day;
        }
        if (k <= 0) {
            break;
        }
    }
    if (day == 0 || k > 0) {
        printf("-1\n");
    }
    else {
        printf("%d\n", day);
    }

    return (0);
}
