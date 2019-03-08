#include <bits/stdc++.h>


int main() {

    int n, k, i, x, cn = 0;

    scanf("%d %d", &n, &k);
    for (i = 0; i < n; ++i) {
        scanf("%d", &x);
        if(x % k == 0)
            ++cn;
    }
    printf("%d\n", cn);

    return (0);
}