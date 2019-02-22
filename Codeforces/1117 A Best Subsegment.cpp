#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, arr[100000+5], i, mx = 0, ans = 0, cnn = 0;
    cin >> n;
    for (i = 0; i < n; ++i) {
        cin >> arr[i];
        mx = max(arr[i], mx);
    }
    for (i = 0; i < n; ++i) {
        if(arr[i] == mx) ++cnn;
        else cnn = 0;
        ans = max(ans, cnn);
    }
    cout << ans << endl;

    return (0);
}
