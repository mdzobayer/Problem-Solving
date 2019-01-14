#include <bits/stdc++.h>


int main() {

    int n, j, i, arr[110], m, l, r, sum, total;
    scanf("%d %d", &n, &m);
    for (i = 1; i <= n; ++i) {
        scanf("%d", &arr[i]);
    }
    total = 0;
    for (i = 0; i < m; ++i) {
        scanf("%d %d", &l, &r);
        sum = 0;
        for (j = l; j <= r; ++j) {
            sum += arr[j];
        }
        if (sum > 0)
            total += sum;
        //printf("sum is %d\n", sum);
    }
    printf("%d\n", total);

    return (0);
}
