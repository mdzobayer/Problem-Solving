#include <bits/stdc++.h>
#define SIZE 62505
using namespace std;

int s1[SIZE], s2[SIZE], dp[SIZE][SIZE];


int main() {

    int test, t, n, p, q, x, i;
    while(scanf("%d", &test) == 1) {
        for (t = 1; t <= test; ++t) {
            scanf("%d %d %d", &n, &p, &q);

            for (i = 0; i <= p; ++i) {
                scanf("%d", &s1[i]);
            }
            for (i = 0; i <= q; ++i) {
                scanf("%d", &s2[i]);
            }


        }
    }

    return (0);
}
