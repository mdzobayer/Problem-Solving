#include <bits/stdc++.h>

using namespace std;

int main() {

    //freopen("in.txt", "r", stdin);

    vector <int> arr;
    int n, test, t, i, x, conn;
    bool isNew;
    scanf("%d", &test);
    for (t = 1; t <= test; ++t) {
        scanf("%d %d", &t, &n);
        arr.clear();
        printf("%d %d\n", t, (n/2 + 1));
        isNew = true;
        conn = 0;
        for (i = 0; i < n; ++i) {
            scanf("%d", &x);
            arr.push_back(x);
            if (i % 2 == 0) {
                ++conn;
                sort(arr.begin(), arr.end());
                if (isNew) {
                    printf("%d", arr[i/2]);
                    isNew = 0;
                }
                else printf(" %d", arr[i/2]);
                if (conn % 10 == 0) {
                    printf("\n");
                    isNew = true;
                }
            }
        }
        printf("\n");
    }

    return (0);
}
