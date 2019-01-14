#include <bits/stdc++.h>

using namespace std;

int main() {

    int test, t, x, y, ans, sh;
    scanf("%d", &test);
    for (t = 1; t <= test; ++t) {
        scanf("%d %d", &x, &y);
        sh = x * y;
        if (x == 1 || y == 1) {
            ans = sh;
        }
        else if (x == 2 || y == 2) {
            ans = (sh / 8)*4;
            if (sh % 8 == 2) {
                ans += 2;
            }
            else if (sh % 8 == 4 || sh % 8 == 6) {
                ans += 4;
            }
        }
        else {
            ans = (sh + 1) / 2;
        }

        printf("Case %d: %d\n", t, ans);
    }

    return (0);
}
