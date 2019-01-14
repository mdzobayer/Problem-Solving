#include <bits/stdc++.h>

using namespace std;

int main() {

    //freopen("in.txt", "r", stdin);

    int test, t, i, n, lie, arr[15];
    scanf("%d", &test);
    for (t = 1; t <= test; ++t) {
        scanf("%d", &n);
        arr[0] = 2;
        for (i = 1; i <= n; ++i) {
            scanf("%d", &arr[i]);
        }
        lie = 0;
        for (i = 0; i < n; ++i) {
            if (arr[i+1] > arr[i])
                lie += ceil((arr[i+1] - arr[i])/5.0);
        }
        printf("Case %d: %d\n", t, lie);
    }

    return (0);
}
