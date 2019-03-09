#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, arr[50+5], ans = 0, x, k, i, y;

    memset(arr, -1, sizeof(arr));

    cin >> n >> k;

    for (i = 1; i <= n; ++i) {
        cin >> arr[i];
    }

    y = arr[k];


    for (i = 1; i <= n; ++i) {
        if (arr[i] >= y && arr[i] > 0) {
            ++ans;
        }
    }
    cout << ans << endl;

    return (0);
}
