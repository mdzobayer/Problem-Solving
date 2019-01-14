#include <cstdio>

int main() {

    int n, arr[110], sum[110], s, e, i, cost1, cost2;

    scanf("%d", &n);
    sum[0] = 0;
    for (i = 1; i <= n; ++i) {
        scanf("%d", &arr[i]);
    }
    scanf("%d %d", &s, &e);
    if (s > e) {
        s = s + e;
        e = s - e;
        s = s - e;
    }
    cost1 = cost2 = 0;
    for (i = s; i < e; ++i) {
        cost1 += arr[i];
    }
    for (i = s - 1; i > 0; --i) {
        cost2 += arr[i];
    }
    for (i = e; i <= n; ++i) {
        cost2 += arr[i];
    }
    //printf("%d %d\n", cost1, cost2);
    if (cost1 < cost2) printf("%d\n", cost1);
    else printf("%d\n", cost2);

    return (0);
}
