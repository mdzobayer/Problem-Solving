#include <bits/stdc++.h>

using namespace std;

int main() {

    // freopen("in.txt", "r", stdin);

    int n, x, arr[105], i;
    cin >> n;

    for (i = 1; i <= n; ++i) {
        cin >> x;
        arr[x] = i; 
    }

    for (i = 1; i <= n; ++i) {
        if (i > 1) cout << " ";
        cout << arr[i];
    }
    cout << endl;


    return (0);
}