#include <bits/stdc++.h>

using namespace std;


int main() {

    int test, t, a, b, ans1, ans2;
    scanf("%d", &test);
    for (t = 1; t <= test; ++t) {
        scanf("%d %d", &a, &b);
        printf("Case %d: ", t);

        if (b < a) {
            swap(a,b);
        }
        --a;
        ans1 = a / 3;

        ans2 = b / 3;



        ans1 *= 2;
        ans2 *= 2;

        if (a % 3 == 2) {
            ++ans1;
        }
        if (b % 3 == 2) {
            ++ans2;
        }

        printf("%d\n", ans2 - ans1);
    }

    return (0);
}
