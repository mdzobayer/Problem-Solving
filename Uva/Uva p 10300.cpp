#include <cstdio>
//#define EOF -1

int main() {
    int n, f, ans;
    int a, b, c;
    while(scanf("%d", &n) != EOF) {
        for (int j = 0; j < n; j++) {

            scanf("%d", &f) != EOF;
            ans = 0;
            for(int i = 0; i < f; ++i) {
                scanf("%d%d%d", &a, &b, &c) != EOF;
                ans += a * c;
            }
            printf("%d\n", ans);
        }
    }

    return (0);
}
