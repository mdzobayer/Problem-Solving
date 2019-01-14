#include <cstdio>

int main() {
    freopen("input.txt", "r", stdin);
    int i, n, m, num[100005], k, v, count, j;
    bool flag;
    while(scanf("%d %d", &n, &m) == 2) {
        for (i = 0; i < n; ++i) {
            scanf("%d", &num[i]);
        }
        for (i = 0; i < m; ++i) {
            count = 0;
            flag = true;
            scanf("%d %d", &k ,&v);
            for (j = 0; j < n; ++j) {
                if (num[j] == v)
                    ++count;
                if (count == k) {
                    printf("%d\n", j + 1);
                    flag = false;
                    break;
                }
            }
            if (flag)
                printf("0\n");
        }
    }
    return (0);
}
