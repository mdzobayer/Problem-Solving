#include <bits/stdc++.h>

using namespace std;

void solve() {

    int n, i, arr[105], sum;
    cin >> n;

    sum = 0;

    for (i = 0; i < n; ++i) {
        cin >> arr[i];
        sum ^= arr[i];
        // cout << "sum = " << sum << endl;
    }

    for (i = 0; i < n; ++i) {
        // cout << "sum ^ arr[i]) == arr[i] " <<  (sum ^ arr[i]) << " " << arr[i] << endl;
        if ((sum ^ arr[i]) == arr[i]) {
            cout << arr[i] << endl;
            return;
        }
    }
    return;
}

int main() {

    // freopen("in.txt", "r", stdin);

    int test;

    cin >> test;
    while(test--) {
        solve();
    }

    return (0);
}