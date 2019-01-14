#include <bits/stdc++.h>


using namespace std;


int main() {

    //freopen("in.txt", "r", stdin);

    int test, t, cx, cy, x1, x2, y1, y2, c, i;
    scanf("%d", &test);
    for (t = 1; t <= test; ++t) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

        printf("Case %d:\n", t);

        scanf("%d", &c);
        for (i = 0; i < c; ++i) {
            scanf("%d %d", &cx, &cy);
            if ((x1 <= cx && cx <= x2) && (y1 <= cy && cy <= y2)) {
                printf("Yes\n");
            }
            else if ((x1 <= cx && cx <= x2) && (y2 <= cy && cy <= y1)) {
                printf("Yes\n");
            }
            else if ((x2 <= cx && cx <= x1) && (y1 <= cy && cy <= y2)) {
                printf("Yes\n");
            }
            else if ((x2 <= cx && cx <= x1) && (y2 <= cy && cy <= y1)) {
                printf("Yes\n");
            }
            else {
                printf("No\n");
            }
        }
    }

    return (0);
}
