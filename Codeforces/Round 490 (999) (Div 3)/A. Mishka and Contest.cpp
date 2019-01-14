#include <bits/stdc++.h>


using namespace std;

int main() {

    int arr[105], n, i, k, Count = 0;
    bool a[105];
    memset(a, true, sizeof(a));

    scanf("%d %d", &n, &k);
    for (i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < n; ++i) {
        if (arr[i] > k || !a[i]) break;
        ++Count;
        a[i] = false;
    }
    for (i = n - 1; i >= 0; --i) {
        if (arr[i] > k || !a[i]) break;
        ++Count;
        a[i] = false;
    }
    printf("%d\n", Count);

    return (0);
}
