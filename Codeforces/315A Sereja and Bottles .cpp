#include <bits/stdc++.h>


using namespace std;

int main() {


    int n, i, j, a[100+5], b[100+5], cnn = 0;

    scanf("%d", &n);
    for (i = 0; i < n; ++i)
        scanf("%d %d", &a[i], &b[i]);

    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            if (i != j && a[i] == b[j]) {
                ++cnn;
                break;
            }
        }
    }

    printf("%d\n", n - cnn);

    return (0);
}
