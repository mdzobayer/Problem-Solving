#include <bits/stdc++.h>


using namespace std;

int main() {

    int n, i, j, x, y;
    bool flag;
    scanf("%d", &n);
    x = 1;
    y = 1;
    for (i = 2; x < n; x += i, ++i) {
        y = 1;
        for (j = 2; ( y <= n - x) ; y += j, ++j) {
            if (x + y == n) {
                printf("YES\n");
                return (0);
            }
        }
    }
    printf("NO\n");

    return (0);
}
