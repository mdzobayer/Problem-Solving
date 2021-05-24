#include <bits/stdc++.h>

using namespace std;

int main() {

    long long int n, result, target, count, i;
    bool marker[1000000+5], space;

    memset(marker, false, sizeof(marker));

    scanf("%lld", &n);

    result = (n * (n + 1)) / 2;

    if (result % 2 == 0) {
        target = result / 2;
        count = 0;

        for (i = n; i > 0; --i) {
            if ((target - i) >= 0) {
                target -= i;
                marker[i] = true;
                count ++;
            }
            if (target == 0) break;
        }

        puts("YES");
        space = false;
        printf("%lld\n", count);
        for (i = 1; i <= n; ++i) {
            if (marker[i]) {
                if (space) printf(" ");
                printf("%lld", i);
                space = true;
            }
        }
        puts("");

        space = false;
        printf("%lld\n", (n - count));
        for (i = 1; i <= n; ++i) {
            if (!marker[i]) {
                if (space) printf(" ");
                printf("%lld", i);
                space = true;
            }
        }
        puts("");
    }
    else {
        printf("NO\n");
    }

    return (0);
}