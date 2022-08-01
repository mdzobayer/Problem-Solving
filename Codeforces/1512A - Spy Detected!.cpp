#include <bits/stdc++.h>

using namespace std;


int main() {

    // freopen("in.txt", "r", stdin);

    int test, t, n, i, maximum, arr[100+5], conn[100+5];

    scanf("%d", &test);
    for (t = 0; t < test; ++t) {
        scanf("%d", &n);

        memset(conn, 0, sizeof(conn));
        maximum = 0;

        for (i = 0; i < n; ++i) {
            scanf("%d", &arr[i]);
            conn[arr[i]] += 1;
            if (arr[i] > maximum) {
                maximum = arr[i];
            }
        }

        for (i = 1; i <= maximum; ++i) {
            if (conn[i] == 1) {
                maximum = i;
                break;
            }
        }
        for (i = 0; i < n; ++i) {
            if (arr[i] == maximum) {
                printf("%d\n", i + 1);
                break;
            }
        }

    }



    return (0);
}