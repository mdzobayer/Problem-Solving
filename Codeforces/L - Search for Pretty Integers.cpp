#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int main() {

    int n, y,m, x, i;
    int arr[12];
    memset(arr, 0, sizeof(arr));
    cin >> n >> m;
    for (i = 0; i < n; ++i) {
        cin >> x;
        if (arr[x] == 0) {
            ++arr[x];
        }
    }
    for (i = 0; i < m; ++i) {
        cin >> x;
        if (arr[x] == 1) {
            ++arr[x];
        }
        else if (arr[x] == 0)
            arr[x] = 3;
    }
    x = y = 9;
    for (i = 1; i < 10; ++i) {
        if (arr[i] == 2) {
            cout << i << endl;
            return (0);
        }
        else if (arr[i] == 1) {
            if (i < x) x = i;
        }
        else if (arr[i] == 3) {
            if (i < y) y = i;
        }
    }
    cout << min(x,y) << max(x,y) << endl;

    return (0);
}
