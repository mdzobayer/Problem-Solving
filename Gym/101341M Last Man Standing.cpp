// Verdict: Wrong Answer

#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, arr[200000+5], i, j, alive, cnn;
    cin >> n;
    alive = n;
    for (i = 1; i <= n; ++i) {
        cin >> arr[i];
        alive -= arr[i];
    }
    if (alive < 1) {
        cout << "NO" << endl;
    }
    else {
        cnn = 1;
        cout << "YES" << endl;
        for (i = 1; arr[i] > 0; ++i) {
            for (j = 0; j < arr[i]; ++j) {
                cout << i << " " << ++cnn << endl;
            }
        }
    }

    return (0);
}